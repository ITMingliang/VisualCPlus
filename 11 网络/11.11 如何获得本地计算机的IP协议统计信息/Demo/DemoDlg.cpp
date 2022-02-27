// DemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "DemoDlg.h"

#include <Iphlpapi.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoDlg dialog

CDemoDlg::CDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDemoDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDemoDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_TEST, OnTest)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoDlg message handlers

BOOL CDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.The framework does this automatically
	//when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;// return TRUEunless you set the focus to a control
}

void CDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//to draw the icon.For MFC applications using the document/view model,
//this is automatically done for you by the framework.

void CDemoDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//the minimized window.
HCURSOR CDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDemoDlg::OnTest() 
{
	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LIST);
	pListBox->ResetContent();

	MIB_IPSTATS IPStats;

	//获得IP协议统计信息
	if (GetIpStatistics(&IPStats) != NO_ERROR)
	{
		return;
	}

	CString strText = _T("");
	strText.Format(_T("IP forwarding enabled or disabled:%d"), 
		IPStats.dwForwarding);
	pListBox->AddString(strText);
	strText.Format(_T("default time-to-live:%d"), 
		IPStats.dwDefaultTTL);
	pListBox->AddString(strText);
	strText.Format(_T("datagrams received:%d"), 
		IPStats.dwInReceives);
	pListBox->AddString(strText);
	strText.Format(_T("received header errors:%d"), 
		IPStats.dwInHdrErrors);
	pListBox->AddString(strText);
	strText.Format(_T("received address errors:%d"), 
		IPStats.dwInAddrErrors);
	pListBox->AddString(strText);
	strText.Format(_T("datagrams forwarded:%d"), 
		IPStats.dwForwDatagrams);
	pListBox->AddString(strText);
	strText.Format(_T("datagrams with unknown protocol:%d"), 
		IPStats.dwInUnknownProtos);
	pListBox->AddString(strText);
	strText.Format(_T("received datagrams discarded:%d"), 
		IPStats.dwInDiscards);
	pListBox->AddString(strText);
	strText.Format(_T("received datagrams delivered:%d"), 
		IPStats.dwInDelivers);
	pListBox->AddString(strText);
	strText.Format(_T("outgoing datagrams requested to send:%d"), 
		IPStats.dwOutRequests);
	pListBox->AddString(strText);
	strText.Format(_T("outgoing datagrams discarded:%d"), 
		IPStats.dwOutDiscards);
	pListBox->AddString(strText);
	strText.Format(_T("sent datagrams discarded:%d"), 
		IPStats.dwOutDiscards);
	pListBox->AddString(strText);
	strText.Format(_T("datagrams for which no route exists:%d"), 
		IPStats.dwOutNoRoutes);
	pListBox->AddString(strText);
	strText.Format(_T("datagrams for which all frags did not arrive:%d"), 
		IPStats.dwReasmTimeout);
	pListBox->AddString(strText);
	strText.Format(_T("datagrams requiring reassembly:%d"), 
		IPStats.dwReasmReqds);
	pListBox->AddString(strText);
	strText.Format(_T("successful reassemblies:%d"), 
		IPStats.dwReasmOks);
	pListBox->AddString(strText);
	strText.Format(_T("failed reassemblies:%d"), 
		IPStats.dwReasmFails);
	pListBox->AddString(strText);
	strText.Format(_T("successful fragmentations:%d"), 
		IPStats.dwFragOks);
	pListBox->AddString(strText);
	strText.Format(_T("failed fragmentations:%d"), 
		IPStats.dwFragFails);
	pListBox->AddString(strText);
	strText.Format(_T("datagrams fragmented:%d"), 
		IPStats.dwFragCreates);
	pListBox->AddString(strText);
	strText.Format(_T("number of interfaces on computer:%d"), 
		IPStats.dwNumIf);
	pListBox->AddString(strText);
	strText.Format(_T("number of IP address on computer:%d"), 
		IPStats.dwNumAddr);
	pListBox->AddString(strText);
	strText.Format(_T("number of routes in routing table:%d"), 
		IPStats.dwNumRoutes);
	pListBox->AddString(strText);
}
