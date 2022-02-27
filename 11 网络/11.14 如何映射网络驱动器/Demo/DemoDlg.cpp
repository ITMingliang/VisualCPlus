// DemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "DemoDlg.h"
#include "AddConnectionDlg.h"
#include "CancelConnectionDlg.h"

#include <Winnetwk.h>

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

void CDemoDlg::OnTest1() 
{
	CAddConnectionDlg dlg;
	if (dlg.DoModal() != IDOK)
	{
		return;
	}

	//获得网络资源的信息
	NETRESOURCE NetSourece;
	NetSourece.dwType = RESOURCETYPE_ANY;
	NetSourece.lpLocalName = (LPSTR)(LPCSTR)dlg.m_strLocalName;
	NetSourece.lpRemoteName = (LPSTR)(LPCSTR)dlg.m_strRemoteName;
	NetSourece.lpProvider = NULL;

	//添加网络驱动器映射
	DWORD dwResult = 0;
	dwResult = WNetAddConnection2(
		&NetSourece, 
		dlg.m_strPassword, 
		dlg.m_strUserName, 
		CONNECT_UPDATE_PROFILE);

	if (dwResult == NO_ERROR)
	{
		AfxMessageBox(_T("添加网络驱动器映射成功。"));
	}
	else if (dwResult == ERROR_ACCESS_DENIED) 
	{
		AfxMessageBox(_T("ERROR_ACCESS_DENIED"));
	}
	else if (dwResult == ERROR_ALREADY_ASSIGNED) 
	{
		AfxMessageBox(_T("ERROR_ALREADY_ASSIGNED"));
	}
	else if (dwResult == ERROR_BAD_DEV_TYPE) 
	{
		AfxMessageBox(_T("ERROR_BAD_DEV_TYPE"));
	}
	else if (dwResult == ERROR_BAD_DEVICE) 
	{
		AfxMessageBox(_T("ERROR_BAD_DEVICE"));
	}
	else if (dwResult == ERROR_BAD_NET_NAME)
	{
		AfxMessageBox(_T("ERROR_BAD_NET_NAME"));
	}
	else if (dwResult == ERROR_BAD_PROFILE)
	{
		AfxMessageBox(_T("ERROR_BAD_PROFILE"));
	}
	else if (dwResult == ERROR_BAD_PROVIDER) 
	{
		AfxMessageBox(_T("ERROR_BAD_PROVIDER"));
	}
	else if (dwResult == ERROR_BUSY) 
	{
		AfxMessageBox(_T("ERROR_BUSY"));
	}
	else if (dwResult == ERROR_CANCELLED) 
	{
		AfxMessageBox(_T("ERROR_CANCELLED"));
	}
	else if (dwResult == ERROR_CANNOT_OPEN_PROFILE) 
	{
		AfxMessageBox(_T("ERROR_CANNOT_OPEN_PROFILE"));
	}
	else if (dwResult == ERROR_DEVICE_ALREADY_REMEMBERED) 
	{
		AfxMessageBox(_T("ERROR_DEVICE_ALREADY_REMEMBERED"));
	}
	else if (dwResult == ERROR_EXTENDED_ERROR) 
	{
		AfxMessageBox(_T("ERROR_EXTENDED_ERROR"));
	}
	else if (dwResult == ERROR_INVALID_PASSWORD) 
	{
		AfxMessageBox(_T("ERROR_INVALID_PASSWORD"));
	}
	else if (dwResult == ERROR_NO_NET_OR_BAD_PATH) 
	{
		AfxMessageBox(_T("ERROR_NO_NET_OR_BAD_PATH"));
	}
	else if (dwResult == ERROR_NO_NETWORK) 
	{
		AfxMessageBox(_T("ERROR_NO_NETWORK"));
	}
	else
	{
		AfxMessageBox(_T("未知错误。"));
	}
}

void CDemoDlg::OnTest2() 
{
	CCancelConnectionDlg dlg;
	if (dlg.DoModal() != IDOK)
	{
		return;
	}

	//取消网络驱动器映射
	DWORD dwResult = 0;
	dwResult = WNetCancelConnection2(
		dlg.m_strLocalName,
		CONNECT_UPDATE_PROFILE,
		FALSE);

	if (dwResult == NO_ERROR)
	{
		AfxMessageBox(_T("取消网络驱动器映射成功。"));
	}
	else if (dwResult == ERROR_BAD_PROFILE) 
	{
		AfxMessageBox(_T("ERROR_BAD_PROFILE"));
	}
	else if (dwResult == ERROR_CANNOT_OPEN_PROFILE) 
	{
		AfxMessageBox(_T("ERROR_CANNOT_OPEN_PROFILE"));
	}
	else if (dwResult == ERROR_DEVICE_IN_USE) 
	{
		AfxMessageBox(_T("ERROR_DEVICE_IN_USE"));
	}
	else if (dwResult == ERROR_EXTENDED_ERROR) 
	{
		AfxMessageBox(_T("ERROR_EXTENDED_ERROR"));
	}
	else if (dwResult == ERROR_NOT_CONNECTED) 
	{
		AfxMessageBox(_T("ERROR_NOT_CONNECTED"));
	}
	else if (dwResult == ERROR_OPEN_FILES) 
	{
		AfxMessageBox(_T("ERROR_OPEN_FILES"));
	}
	else
	{
		AfxMessageBox(_T("未知错误。"));
	}
}
