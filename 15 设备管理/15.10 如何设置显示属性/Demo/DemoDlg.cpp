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
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDemoDlg)
	DDX_Control(pDX, IDC_BITSPERPIXEL, m_ctrlBitsPerPixel);
	DDX_Control(pDX, IDC_PIXELS, m_ctrlPixels);
	DDX_Control(pDX, IDC_DISPLAYFREQUENCRY, m_ctrlDispalyFrequencry);
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
	
	m_ctrlBitsPerPixel.AddString(_T("16 位"));
	m_ctrlBitsPerPixel.AddString(_T("32 位"));
	m_ctrlPixels.AddString(_T("600×800 像素"));
	m_ctrlPixels.AddString(_T("1024×768 像素"));
	m_ctrlDispalyFrequencry.AddString(_T("60 赫兹"));
	m_ctrlDispalyFrequencry.AddString(_T("75 赫兹"));

	DEVMODE DevMode; 

	//获得显示属性
	EnumDisplaySettings(NULL, ENUM_REGISTRY_SETTINGS, &DevMode);
	
	//颜色深度
	if (DevMode.dmBitsPerPel == 16)
	{
		m_ctrlBitsPerPixel.SetCurSel(0);
	}
	else if (DevMode.dmBitsPerPel == 32)
	{
		m_ctrlBitsPerPixel.SetCurSel(1);
	}
	//分辨率
	if ((DevMode.dmPelsWidth == 800) && (DevMode.dmPelsHeight == 600))
	{
		m_ctrlPixels.SetCurSel(0);
	}
	else if ((DevMode.dmPelsWidth == 1024) && (DevMode.dmPelsHeight == 768))
	{
		m_ctrlPixels.SetCurSel(1);
	}
	//刷新率
	if (DevMode.dmDisplayFrequency == 60)
	{
		m_ctrlDispalyFrequencry.SetCurSel(0);
	}
	else if (DevMode.dmDisplayFrequency == 75)
	{
		m_ctrlDispalyFrequencry.SetCurSel(1);
	}

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

void CDemoDlg::OnTest() 
{ 
	DEVMODE DevMode;

	//颜色深度
	if (m_ctrlBitsPerPixel.GetCurSel() == 0)
	{
		DevMode.dmBitsPerPel = 16;
	}
	else if (m_ctrlBitsPerPixel.GetCurSel() == 1)
	{
		DevMode.dmBitsPerPel = 32;
	}
	//分辨率
	if (m_ctrlPixels.GetCurSel() == 0)
	{
		DevMode.dmPelsWidth = 800;
		DevMode.dmPelsHeight = 600;
	}
	else if (m_ctrlPixels.GetCurSel() == 1)
	{
		DevMode.dmPelsWidth = 1024;
		DevMode.dmPelsHeight = 768;
	}
	//刷新率
	if (m_ctrlDispalyFrequencry.GetCurSel() == 0)
	{
		DevMode.dmDisplayFrequency = 60;
	}
	else if (m_ctrlDispalyFrequencry.GetCurSel() == 1)
	{
		DevMode.dmDisplayFrequency = 75;
	}
	DevMode.dmSize = sizeof(DEVMODE);  
	DevMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT | 
		DM_BITSPERPEL | DM_DISPLAYFREQUENCY; 

	//设置显示属性
	LONG nResult = ChangeDisplaySettings(&DevMode, 0);
	if (nResult == DISP_CHANGE_SUCCESSFUL)  
	{
		//用新的设置参数更新注册表
		ChangeDisplaySettings(&DevMode, CDS_UPDATEREGISTRY);

		AfxMessageBox(_T("设置显示属性成功。"));
	}
	else  
	{
		//恢复默认设置
		ChangeDisplaySettings(NULL, 0);
		
		AfxMessageBox(_T("设置显示属性失败。"));
	}
}
