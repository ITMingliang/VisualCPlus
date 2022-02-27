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

#define WM_THREADMSG WM_USER+1
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
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_pThread1 = NULL;
	m_pThread2 = NULL;
	m_ThreadParam.nData = 0;

	//创建临界区
	m_ThreadParam.pCriticalSection = new CCriticalSection();
}

CDemoDlg::~CDemoDlg()
{
	if (m_pThread1 != NULL)
	{
		//等待线程结束
		::WaitForSingleObject(m_pThread1->m_hThread, INFINITE);

		delete m_pThread1;
		m_pThread1 = NULL;
	}

	if (m_pThread2 != NULL)
	{
		//等待线程结束
		::WaitForSingleObject(m_pThread2->m_hThread, INFINITE);

		delete m_pThread2;
		m_pThread2 = NULL;
	}

	if (m_ThreadParam.pCriticalSection != NULL)
	{
		delete m_ThreadParam.pCriticalSection;
		m_ThreadParam.pCriticalSection = NULL;
	}
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
	ON_BN_CLICKED(IDC_BEGIN_THREAD, OnBeginThread)
	ON_MESSAGE(WM_THREADMSG, OnMsgFunc)
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
	
	SetDlgItemInt(IDC_DATA, m_ThreadParam.nData);
	
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

LRESULT CDemoDlg::OnMsgFunc(WPARAM wParam, LPARAM lpParam)
{
	SetDlgItemInt(IDC_DATA, m_ThreadParam.nData);

	return 1;
}

void CDemoDlg::OnBeginThread() 
{
	//判断线程是否正在运行
	if (m_pThread1 != NULL)
	{	
		DWORD dwExitCode = 0;
		if (::GetExitCodeThread(m_pThread1->m_hThread, &dwExitCode))
		{    
			if (dwExitCode == STILL_ACTIVE)
			{
				AfxMessageBox(_T("线程1已经启动。"));
				return;
			}
			else
			{
				delete m_pThread1;
				m_pThread1 = NULL;
			}
		}
	}
	if (m_pThread2 != NULL)
	{
		//判断线程是否正在运行
		DWORD dwExitCode = 0;
		if (::GetExitCodeThread(m_pThread2->m_hThread, &dwExitCode))
		{    
			if (dwExitCode == STILL_ACTIVE)
			{
				AfxMessageBox(_T("线程2已经启动。"));
				return;
			}
			else
			{
				delete m_pThread2;
				m_pThread2 = NULL;
			}
		}
	}

	m_ThreadParam.hWnd = m_hWnd;

	//启动线程，初始为挂起状态
	m_pThread1 = AfxBeginThread(ThreadProc1, &m_ThreadParam,	
		THREAD_PRIORITY_ABOVE_NORMAL, 0, CREATE_SUSPENDED);
	m_pThread2 = AfxBeginThread(ThreadProc2, &m_ThreadParam,
		THREAD_PRIORITY_ABOVE_NORMAL, 0, CREATE_SUSPENDED);

	//线程结束时不自动删除
	m_pThread1->m_bAutoDelete = FALSE;
	m_pThread2->m_bAutoDelete = FALSE;

	//恢复线程运行
	m_pThread1->ResumeThread();
	m_pThread2->ResumeThread();
}

UINT ThreadProc1(LPVOID pParam)
{
	//线程参数
	THREAD_PARAM* pThreadParam = (THREAD_PARAM*)pParam;

	//锁定
	pThreadParam->pCriticalSection->Lock();

	for (int n = 0; n < 10; n++)
	{
		pThreadParam->nData++;
		::PostMessage(pThreadParam->hWnd, WM_THREADMSG, 0, 0);

		Sleep(500);
	}

	//解锁
	pThreadParam->pCriticalSection->Unlock();

	return 0;
}

UINT ThreadProc2(LPVOID pParam)
{
	//线程参数
	THREAD_PARAM* pThreadParam = (THREAD_PARAM*)pParam;

	//锁定
	pThreadParam->pCriticalSection->Lock();

	for (int n = 0; n < 10; n++)
	{
		pThreadParam->nData--;
		::PostMessage(pThreadParam->hWnd, WM_THREADMSG, 0, 0);

		Sleep(500);
	}

	//解锁
	pThreadParam->pCriticalSection->Unlock();

	return 0;
}





