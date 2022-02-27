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
	DDX_Control(pDX, IDC_LIST4, m_ctrlList4);
	DDX_Control(pDX, IDC_LIST3, m_ctrlList3);
	DDX_Control(pDX, IDC_LIST2, m_ctrlList2);
	DDX_Control(pDX, IDC_LIST1, m_ctrlList1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
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
	
	//��ʼ��ͼ���б�
	m_BigImageList.Create(IDB_BIG, 32, 0, RGB(128,128,128));
	m_SmallImageList.Create(IDB_SMALL, 16, 0, RGB(0,128,128));

	//��ʼ���б�ؼ�
	InitList1();
	InitList2();
	InitList3();
	InitList4();

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

void CDemoDlg::InitList1() 
{
	//���б�ؼ��в�����
	m_ctrlList1.InsertColumn(0, _T(""), LVCFMT_LEFT, 100);

	//���б�ؼ��в�����
	for (int m = 0; m < 5; m++)
	{
		CString strItem = _T("");
		strItem.Format("Item%d", m);
		m_ctrlList1.InsertItem(m, strItem, m);
	}

	//�����б�ؼ���ͼ���б�
	m_ctrlList1.SetImageList(&m_BigImageList, LVSIL_NORMAL);

	//�����б�ؼ���ͼ����ʾ��ʽ
	m_ctrlList1.ModifyStyle(LVS_SMALLICON | LVS_LIST | LVS_REPORT, LVS_ICON);
}

void CDemoDlg::InitList2() 
{
	//���б�ؼ��в�����
	m_ctrlList2.InsertColumn(0, _T(""), LVCFMT_LEFT, 100);

	//���б�ؼ��в�����
	for (int m = 0; m < 5; m++)
	{
		CString strItem = _T("");
		strItem.Format("Item%d", m);
		m_ctrlList2.InsertItem(m, strItem, m);
	}

	//�����б�ؼ���ͼ���б�
	m_ctrlList2.SetImageList(&m_SmallImageList, LVSIL_SMALL);

	//�����б�ؼ���Сͼ����ʾ��ʽ
 	m_ctrlList2.ModifyStyle(LVS_ICON | LVS_LIST | LVS_REPORT, LVS_SMALLICON);
}

void CDemoDlg::InitList3() 
{
	//���б�ؼ��в�����
	m_ctrlList3.InsertColumn(0, _T(""), LVCFMT_LEFT, 100);

	//���б�ؼ��в�����
	for (int m = 0; m < 5; m++)
	{
		CString strItem = _T("");
		strItem.Format("Item%d", m);
		m_ctrlList3.InsertItem(m, strItem, m);
	}

	//�����б�ؼ���ͼ���б�
	m_ctrlList3.SetImageList(&m_SmallImageList, LVSIL_SMALL);

	//�����б�ؼ����б���ʾ��ʽ
	m_ctrlList3.ModifyStyle(LVS_ICON | LVS_SMALLICON | LVS_REPORT, LVS_LIST);
}

void CDemoDlg::InitList4() 
{
	//���б�ؼ��в�����
	m_ctrlList4.InsertColumn(0, _T(""), LVCFMT_LEFT, 100);

	//���б�ؼ��в�����
	for (int m = 0; m < 5; m++)
	{
		CString strItem = _T("");
		strItem.Format("Item%d", m);
		m_ctrlList4.InsertItem(m, strItem, m);
	}

	//�����б�ؼ���ͼ���б�
	m_ctrlList4.SetImageList(&m_SmallImageList, LVSIL_SMALL);

	//�����б�ؼ��ı�����ʾ��ʽ
	m_ctrlList4.ModifyStyle(LVS_ICON | LVS_SMALLICON | LVS_LIST, LVS_REPORT);
}

