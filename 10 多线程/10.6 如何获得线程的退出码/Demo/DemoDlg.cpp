// DemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "DemoDlg.h"

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

	m_pThread1 = NULL;
	m_hThread2 = NULL;
}

CDemoDlg::~CDemoDlg()
{
	if (m_pThread1 != NULL)
	{
		delete m_pThread1;
		m_pThread1 = NULL;
	}

	if (m_hThread2 != NULL)
	{
		::CloseHandle(m_hThread2);
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
	ON_BN_CLICKED(IDC_BEGIN_THREAD1, OnBeginThread1)
	ON_BN_CLICKED(IDC_BEGIN_THREAD2, OnBeginThread2)
	ON_BN_CLICKED(IDC_GET_EXITCODETHREAD1, OnGetExitCodeThread1)
	ON_BN_CLICKED(IDC_GET_EXITCODETHREAD2, OnGetExitCodeThread2)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
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

void CDemoDlg::OnBeginThread1() 
{
	if (m_pThread1 != NULL)
	{
		delete m_pThread1;
		m_pThread1 = NULL;
	}

	//启动线程 初始为挂起状态
	m_pThread1 = (CMyThread1*)AfxBeginThread
		(RUNTIME_CLASS(CMyThread1), 
		THREAD_PRIORITY_NORMAL, 
		0, 
		CREATE_SUSPENDED);

	//线程结束时不自动撤销
	m_pThread1->m_bAutoDelete = FALSE;

	//恢复线程运行
	m_pThread1->ResumeThread();	
}

void CDemoDlg::OnBeginThread2() 
{
	//启动线程 初始为挂起状态
	CWinThread* pThread2 = (CMyThread2*)AfxBeginThread(
		RUNTIME_CLASS(CMyThread2), 
		THREAD_PRIORITY_NORMAL, 
		0, 
		CREATE_SUSPENDED);

	//线程结束时自动撤销（默认）
	pThread2->m_bAutoDelete = TRUE;   

	//复制线程句柄
	::DuplicateHandle(GetCurrentProcess(),
		pThread2->m_hThread, 
		GetCurrentProcess(),
		&m_hThread2,
		0,
		FALSE,
		DUPLICATE_SAME_ACCESS);				

	//恢复线程运行
  	pThread2->ResumeThread();
}

void CDemoDlg::OnGetExitCodeThread1() 
{
	if (m_pThread1 == NULL)
	{
		return;
	}

	DWORD dwExitCode = 0;

	if (::GetExitCodeThread(m_pThread1->m_hThread, &dwExitCode))
	{    
		if (dwExitCode == STILL_ACTIVE)
		{
			AfxMessageBox(_T("线程正在运行\n"));
		}
		else
		{
			CString strText = _T("");
			strText.Format("线程退出，退出码：%d\n", dwExitCode);
			AfxMessageBox(strText);
		}
	}
}

void CDemoDlg::OnGetExitCodeThread2() 
{
	DWORD dwExitCode = 0;

	if (::GetExitCodeThread(m_hThread2, &dwExitCode))
	{    
		if (dwExitCode == STILL_ACTIVE)
		{
			AfxMessageBox(_T("线程正在运行\n"));
		}
		else
		{
			CString strText = _T("");
			strText.Format("线程退出，退出码：%d\n", dwExitCode);
			AfxMessageBox(strText);
		}
	}	
}
