// DemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "DemoDlg.h"
#include "ListenSocket.h"
#include "AcceptSocket.h"


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

	m_pListenSocket = NULL;
}

CDemoDlg::~CDemoDlg()
{
	if (m_pListenSocket != NULL)
	{
		delete m_pListenSocket;
		m_pListenSocket = NULL;
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
	ON_BN_CLICKED(IDC_LISTEN, OnListen)
	ON_BN_CLICKED(IDC_SEND, OnSend)
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

void CDemoDlg::OnListen() 
{
	CString strPort = _T("");
	GetDlgItemText(IDC_PORT, strPort);
	if (strPort.IsEmpty())
	{
		AfxMessageBox("请设置服务器端口号。");
		return;
	}
	int nPort = atoi(strPort);

	GetDlgItem(IDC_SDATA)->EnableWindow(FALSE);
	GetDlgItem(IDC_SEND)->EnableWindow(FALSE);
	GetDlgItem(IDC_RDATA)->EnableWindow(FALSE);

	if (m_pListenSocket != NULL)
	{
		delete m_pListenSocket;
		m_pListenSocket = NULL;
	}
	m_pListenSocket = new CListenSocket(m_hWnd);

	//创建套接字
	if (!m_pListenSocket->Create(nPort))
	{
		AfxMessageBox(_T("套接字创建失败。"));
		return;
	}

	//监听连接
	if (!m_pListenSocket->Listen())
	{
		AfxMessageBox(_T("监听连接失败。"));
		return;
	}

	GetDlgItem(IDC_SDATA)->EnableWindow(TRUE);
	GetDlgItem(IDC_SEND)->EnableWindow(TRUE);
	GetDlgItem(IDC_RDATA)->EnableWindow(TRUE);
}

void CDemoDlg::OnSend() 
{
	if (m_pListenSocket == NULL)
	{
		return;
	}

	CAcceptSocket* pAcceptSocket = m_pListenSocket->m_pAcceptSocket;
	if (pAcceptSocket == NULL)
	{
		return;
	}

	CString strSData = _T("");
	GetDlgItemText(IDC_SDATA, strSData);
	int nLength = strSData.GetLength();
	TCHAR* pBuffer = strSData.GetBuffer(nLength+1024);

	//发送数据
	pAcceptSocket->Send(pBuffer, nLength);

	strSData.ReleaseBuffer();
}

LRESULT CDemoDlg::OnReceive()
{
	if (m_pListenSocket == NULL)
	{
		return -1;
	}

	CAcceptSocket* pAcceptSocket = m_pListenSocket->m_pAcceptSocket;
	if (pAcceptSocket == NULL)
	{
		return -1;
	}

	TCHAR* pBuffer = new TCHAR[1024];
	memset(pBuffer, 0, 1024);

	//接收数据
	pAcceptSocket->Receive(pBuffer, 1024);

	CString strSData = pBuffer;
	SetDlgItemText(IDC_RDATA, strSData);
	delete[] pBuffer;

	return 0;
}