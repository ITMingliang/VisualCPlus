// DemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "DemoDlg.h"
#include "FolderDialog.h"

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
	ON_BN_CLICKED(IDC_GET_FILEINFO, OnGetFileInfo)
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

void CDemoDlg::OnGetFileInfo() 
{
	//创建文件对话框
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | 
		OFN_OVERWRITEPROMPT, _T("所有文件(*.*)|*.*||"));

	if (dlg.DoModal() == IDOK)
	{
		//获得文件路径
		CString strPathName = dlg.GetPathName();

		//获得文件信息
		CFileStatus FileStatus;
		if (CFile::GetStatus(strPathName, FileStatus))
		{
			CString strText = _T("");
			CString strInfo = _T("");

			strInfo.Format(_T("名称：%s\n"), 
				FileStatus.m_szFullName);
			strText += strInfo;

			strInfo.Format(_T("大小：%d字节\n"), 
				FileStatus.m_size);
			strText += strInfo;

			strInfo.Format(_T("创建时间：%d年%d月%d日,%02d:%02d:%02d\n"), 
				FileStatus.m_ctime.GetYear(),
				FileStatus.m_ctime.GetMonth(),
				FileStatus.m_ctime.GetDay(),
				FileStatus.m_ctime.GetHour(),
				FileStatus.m_ctime.GetMinute(),
				FileStatus.m_ctime.GetSecond());
			strText += strInfo;
			strInfo.Format(_T("修改时间：%d年%d月%d日,%02d:%02d:%02d\n"),
				FileStatus.m_ctime.GetYear(),
				FileStatus.m_ctime.GetMonth(),
				FileStatus.m_ctime.GetDay(),
				FileStatus.m_ctime.GetHour(),
				FileStatus.m_ctime.GetMinute(),
				FileStatus.m_ctime.GetSecond());
			strText += strInfo;
			strInfo.Format(_T("访问时间：%d年%d月%d日,%02d:%02d:%02d\n"),
				FileStatus.m_ctime.GetYear(),
				FileStatus.m_ctime.GetMonth(),
				FileStatus.m_ctime.GetDay(),
				FileStatus.m_ctime.GetHour(),
				FileStatus.m_ctime.GetMinute(),
				FileStatus.m_ctime.GetSecond());
 			strText += strInfo;

			CString strFileAttributes = _T("");
			if (FileStatus.m_attribute & 0x00)
			{
				strFileAttributes += _T("无\n");
			}
			if (FileStatus.m_attribute & 0x01)
			{
				strFileAttributes += _T("只读\n");
			}
			if (FileStatus.m_attribute & 0x02)
			{
				strFileAttributes += _T("隐藏\n");
			}
			if (FileStatus.m_attribute & 0x04)
			{
				strFileAttributes += _T("系统\n");
			}
			if (FileStatus.m_attribute & 0x08)
			{
				strFileAttributes += _T("卷标\n");
			}
			if (FileStatus.m_attribute & 0x10)
			{
				strFileAttributes += _T("目录\n");
			}
			if (FileStatus.m_attribute & 0x20)
			{
				strFileAttributes += _T("存档\n");
			}
			strInfo.Format(_T("属性：%s"), strFileAttributes);
			strText += strInfo;

			AfxMessageBox(strText);
		}
	}
}



