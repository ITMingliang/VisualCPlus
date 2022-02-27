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

void CDemoDlg::OnTest() 
{
	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LIST);
	pListBox->ResetContent();

	int nWidth = 0;
	int nHeight = 0;
	CString strText = _T("");

	//屏幕大小
	strText.Format(_T("屏幕大小：           %d × %d"), 
		GetSystemMetrics(SM_CXSCREEN), 
		GetSystemMetrics(SM_CYSCREEN));
	pListBox->AddString(strText);

	//全屏窗口客户区大小
	strText.Format(_T("全屏窗口客户区大小： %d × %d"), 
		GetSystemMetrics(SM_CXFULLSCREEN), 
		GetSystemMetrics(SM_CYFULLSCREEN));
	pListBox->AddString(strText);

	//最大化窗口大小
	strText.Format(_T("最大化窗口大小：     %d × %d"), 
		GetSystemMetrics(SM_CXMAXIMIZED), 
		GetSystemMetrics(SM_CYMAXIMIZED));
	pListBox->AddString(strText);

	//最小化窗口大小
	strText.Format(_T("最小化窗口大小：     %d × %d"), 
		GetSystemMetrics(SM_CXMINIMIZED), 
		GetSystemMetrics(SM_CYMINIMIZED));
	pListBox->AddString(strText);

	//窗口边界大小
	strText.Format(_T("窗口边界大小：       %d × %d"), 
		GetSystemMetrics(SM_CXBORDER), 
		GetSystemMetrics(SM_CYBORDER));
	pListBox->AddString(strText);

	//固定框架厚度
	strText.Format(_T("固定框架厚度：       %d × %d"), 
		GetSystemMetrics(SM_CXFIXEDFRAME), 
		GetSystemMetrics(SM_CYFIXEDFRAME));
	pListBox->AddString(strText);

	//可变框架厚度
	strText.Format(_T("可变框架厚度：       %d × %d"), 
		GetSystemMetrics(SM_CXSIZEFRAME), 
		GetSystemMetrics(SM_CYSIZEFRAME));
	pListBox->AddString(strText);
								
	//水平滚动条箭头大小
	strText.Format(_T("水平滚动条箭头大小： %d × %d"), 
		GetSystemMetrics(SM_CXHSCROLL), 
		GetSystemMetrics(SM_CYHSCROLL));
	pListBox->AddString(strText);

	//垂直滚动条箭头大小
	strText.Format(_T("垂直滚动条箭头大小： %d × %d"), 
		GetSystemMetrics(SM_CXVSCROLL), 
		GetSystemMetrics(SM_CYVSCROLL));
	pListBox->AddString(strText);

	//标题栏高度
	strText.Format(_T("标题栏高度：         %d"), 
		GetSystemMetrics(SM_CYCAPTION));
	pListBox->AddString(strText);

	//标题栏按钮大小
	strText.Format(_T("标题栏按钮大小：     %d × %d"), 
		GetSystemMetrics(SM_CXSIZE), 
		GetSystemMetrics(SM_CYSIZE));
	pListBox->AddString(strText);

	//菜单栏高度
	strText.Format(_T("菜单栏高度：         %d"), 
		GetSystemMetrics(SM_CYMENU));
	pListBox->AddString(strText);

	//光标大小
	strText.Format(_T(""));
	strText.Format(_T("光标大小：           %d × %d"), 
		GetSystemMetrics(SM_CXCURSOR), 
		GetSystemMetrics(SM_CYCURSOR));
	pListBox->AddString(strText);

	//图标大小
	strText.Format(_T(""));
	strText.Format(_T("默认图标大小：       %d × %d"), 
		GetSystemMetrics(SM_CXICON), 
		GetSystemMetrics(SM_CYICON));
	pListBox->AddString(strText);
}

