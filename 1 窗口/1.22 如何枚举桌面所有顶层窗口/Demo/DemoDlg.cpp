// DemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "DemoDlg.h"
#include "Tlhelp32.h"

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
	
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST);
	pList->ModifyStyle(LVS_ICON | LVS_SMALLICON | LVS_LIST, LVS_REPORT);
	pList->SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	pList->InsertColumn(0, _T("窗口类名"), LVCFMT_LEFT, 100);
	pList->InsertColumn(1, _T("窗口标题"), LVCFMT_LEFT, 100);

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

void CDemoDlg::OnTest1() 
{
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST);
	pList->DeleteAllItems();
	pList->SetRedraw(FALSE);

	//获得桌面窗口
	CWnd* pDesktopWnd = CWnd::GetDesktopWindow();

	//获得第一个子窗口
	CWnd* pWnd = pDesktopWnd->GetWindow(GW_CHILD);

	while (pWnd != NULL) 
	{		
		int nItem = pList->GetItemCount();

		//获得窗口类名
		CString strClassName = _T("");
		::GetClassName(pWnd->GetSafeHwnd(), strClassName.GetBuffer(256), 256);
		strClassName.ReleaseBuffer();
		pList->InsertItem(nItem, strClassName);

		//获得窗口标题
		CString strWindowText= _T("");
		::GetWindowText(pWnd->GetSafeHwnd(), strWindowText.GetBuffer(256), 256);
		strWindowText.ReleaseBuffer();
		pList->SetItemText(nItem, 1, strWindowText);

		//继续下一个子窗口 
		pWnd = pWnd->GetWindow(GW_HWNDNEXT);
	}

	pList->SetRedraw(TRUE);
}

void CDemoDlg::OnTest2() 
{
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST);
	pList->DeleteAllItems();
	pList->SetRedraw(FALSE);

	//枚举窗口
	::EnumWindows(EnumWndProc, (LPARAM)pList);

	pList->SetRedraw(TRUE);
}

BOOL CALLBACK EnumWndProc(HWND hwnd,LPARAM lParam)
{
	if (hwnd == NULL)
	{
		return FALSE;
	}

 	CListCtrl* pList = (CListCtrl*)lParam;
	int nItem = pList->GetItemCount();

	//获得窗口类名
	CString strClassName = _T("");
	::GetClassName(hwnd, strClassName.GetBuffer(256), 256);
	strClassName.ReleaseBuffer();
	pList->InsertItem(nItem, strClassName);

	//获得窗口标题
	CString strWindowText= _T("");
	::GetWindowText(hwnd, strWindowText.GetBuffer(256), 256);
	strWindowText.ReleaseBuffer();
	pList->SetItemText(nItem, 1, strWindowText);

	return TRUE;
}
 
  