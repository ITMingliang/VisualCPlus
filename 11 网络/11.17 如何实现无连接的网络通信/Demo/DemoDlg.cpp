// DemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "DemoDlg.h"
#include "DatagramSocket.h"


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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
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
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_pDatagramSocket = NULL;
}

CDemoDlg::~CDemoDlg()
{
	if (m_pDatagramSocket != NULL)
	{
		delete m_pDatagramSocket;
		m_pDatagramSocket = NULL;
	}
}

void CDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDemoDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SEND, OnSend)
	ON_BN_CLICKED(IDC_INIT, OnInit)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_RECEIVE, OnReceive)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	SetDlgItemInt(IDC_LOCALPORT, 5050);
	SetDlgItemText(IDC_ADDR, _T("129.26.11.100"));
	SetDlgItemInt(IDC_PORT, 5050);

	GetDlgItem(IDC_ADDR)->EnableWindow(FALSE);
	GetDlgItem(IDC_PORT)->EnableWindow(FALSE);
	GetDlgItem(IDC_SDATA)->EnableWindow(FALSE);
	GetDlgItem(IDC_SEND)->EnableWindow(FALSE);
	GetDlgItem(IDC_RDATA)->EnableWindow(FALSE);

	return TRUE;
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
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

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
//  the minimized window.
HCURSOR CDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDemoDlg::OnInit() 
{
	CString strPort = _T("");
	GetDlgItemText(IDC_LOCALPORT, strPort);
	if (strPort.IsEmpty())
	{
		AfxMessageBox("请设置本机端口号。");
		return;
	}
	int nLocalPort = atoi(strPort);

	GetDlgItem(IDC_ADDR)->EnableWindow(FALSE);
	GetDlgItem(IDC_PORT)->EnableWindow(FALSE);
	GetDlgItem(IDC_SDATA)->EnableWindow(FALSE);
	GetDlgItem(IDC_SEND)->EnableWindow(FALSE);
	GetDlgItem(IDC_RDATA)->EnableWindow(FALSE);

	if (m_pDatagramSocket != NULL)
	{
		delete m_pDatagramSocket;
		m_pDatagramSocket = NULL;
	}
	m_pDatagramSocket = new CDatagramSocket(m_hWnd);
	
	//创建套接字
	if (!m_pDatagramSocket->Create(nLocalPort, SOCK_DGRAM))
	{
		delete m_pDatagramSocket;
		m_pDatagramSocket = NULL;
		AfxMessageBox("套接字创建失败。");
		return;
	}

	GetDlgItem(IDC_ADDR)->EnableWindow(TRUE);
	GetDlgItem(IDC_PORT)->EnableWindow(TRUE);
	GetDlgItem(IDC_SDATA)->EnableWindow(TRUE);
	GetDlgItem(IDC_SEND)->EnableWindow(TRUE);
	GetDlgItem(IDC_RDATA)->EnableWindow(TRUE);
}

void CDemoDlg::OnSend() 
{
	if (m_pDatagramSocket == NULL)
	{
		return;
	}

	CString strAddr = _T("");
	GetDlgItemText(IDC_ADDR, strAddr);
	if (strAddr.IsEmpty())
	{
		AfxMessageBox("请设置目标机IP地址。");
		return;
	}
	
	CString strPort = _T("");
	GetDlgItemText(IDC_PORT, strPort);
	if (strPort.IsEmpty())
	{
		AfxMessageBox("请设置目标机端口号。");
		return;
	}
	int nPort = atoi(strPort);

	CString strSData = _T("");
	GetDlgItemText(IDC_SDATA, strSData);
	int nLength = strSData.GetLength();
	TCHAR* pBuffer = strSData.GetBuffer(nLength+1024);

	//发送数据
	m_pDatagramSocket->SendTo(pBuffer, nLength, nPort, strAddr);

	strSData.ReleaseBuffer();	
}

LRESULT CDemoDlg::OnReceive()
{
	if (m_pDatagramSocket == NULL)
	{
		return -1;
	}

	TCHAR* pBuffer = new TCHAR[1024];
	memset(pBuffer, 0, 1024);

	//接收数据
	CString strAddr = _T("");
	UINT nPort = 0;
	m_pDatagramSocket->ReceiveFrom(pBuffer, 1024, strAddr, nPort);

	CString strSData = pBuffer;
	SetDlgItemText(IDC_RDATA, strSData);
	delete[] pBuffer;
 
 	return 0;
}
