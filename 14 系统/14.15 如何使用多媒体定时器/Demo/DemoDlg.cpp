// DemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "DemoDlg.h"
#include "Mmsystem.h"

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
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_nTimerID = 0;
	m_pTimerThread = NULL;
	m_ThreadParam.nTime = 0;
	m_ThreadParam.hTimerEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	m_ThreadParam.hExitEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
}

CDemoDlg::~CDemoDlg()
{
	//取消定时器
	if (m_nTimerID != 0) 
	{
		timeKillEvent(m_nTimerID);
	}

	//结束定时线程
	if (m_pTimerThread != NULL)
	{
		//设置退出事件
		SetEvent(m_ThreadParam.hExitEvent);
		//等待定时线程结束
		::WaitForSingleObject(m_pTimerThread->m_hThread, INFINITE);
		delete m_pTimerThread;
		m_pTimerThread = NULL;
	}

	CloseHandle(m_ThreadParam.hTimerEvent);
	CloseHandle(m_ThreadParam.hExitEvent);
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
	ON_MESSAGE(WM_THREADMSG, OnMsgFunc)
	ON_BN_CLICKED(IDC_TEST1, OnTest1)
	ON_BN_CLICKED(IDC_TEST2, OnTest2)
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
	
	SetDlgItemInt(IDC_TIME, 0);
	
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

LRESULT CDemoDlg::OnMsgFunc()
{
	SetDlgItemInt(IDC_TIME, m_ThreadParam.nTime);

	return 1;
}

void CDemoDlg::OnTest1() 
{
	//取消定时器
	if (m_nTimerID != 0) 
	{
		timeKillEvent(m_nTimerID);
	}

	//结束定时线程
	if (m_pTimerThread != NULL)
	{
		//设置退出事件
		SetEvent(m_ThreadParam.hExitEvent);
		//等待定时线程结束
		::WaitForSingleObject(m_pTimerThread->m_hThread, INFINITE);
		delete m_pTimerThread;
		m_pTimerThread = NULL;
	}

	m_ThreadParam.hWnd = GetSafeHwnd();
	m_ThreadParam.nTime = 0;

	SetDlgItemInt(IDC_TIME, 0);

	TIMECAPS tc;

	//获得定时器分辨率
	if (timeGetDevCaps(&tc, sizeof(TIMECAPS)) != TIMERR_NOERROR) 
	{
		return;
	}

	UINT nResolution = min(max(tc.wPeriodMin, 1), tc.wPeriodMax);
	
	UINT nInterval = 100;
	if (nInterval < nResolution)
	{
		nInterval = nResolution;
	}

	//设置定时最小分辨率
	timeBeginPeriod(nResolution);

	//设置定时器
	m_nTimerID = timeSetEvent(nInterval, nResolution, 
		(LPTIMECALLBACK)m_ThreadParam.hTimerEvent, 
		(DWORD)this, TIME_PERIODIC | TIME_CALLBACK_EVENT_SET);

	//创建定时线程
	m_pTimerThread = (CTimerThread*)AfxBeginThread(RUNTIME_CLASS(CTimerThread),
		THREAD_PRIORITY_ABOVE_NORMAL, 0, CREATE_SUSPENDED);
	m_pTimerThread->m_bAutoDelete = FALSE;
	m_pTimerThread->m_pThreadParam = &m_ThreadParam;
	m_pTimerThread->ResumeThread();
}

void CDemoDlg::OnTest2() 
{
	//取消定时器
	if (m_nTimerID != 0) 
	{
		timeKillEvent(m_nTimerID);
	}

	//结束定时线程
	if (m_pTimerThread != NULL)
	{
		//设置退出事件
		SetEvent(m_ThreadParam.hExitEvent);
		//等待定时线程结束
		::WaitForSingleObject(m_pTimerThread->m_hThread, INFINITE);
		delete m_pTimerThread;
		m_pTimerThread = NULL;
	}	
}
