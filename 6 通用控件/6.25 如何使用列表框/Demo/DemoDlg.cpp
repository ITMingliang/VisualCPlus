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
	DDX_Control(pDX, IDC_LIST2, m_ctrlList2);
	DDX_Control(pDX, IDC_LIST1, m_ctrlList1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_TEST1, OnTest1)
	ON_BN_CLICKED(IDC_TEST2, OnTest2)
	ON_BN_CLICKED(IDC_TEST3, OnTest3)
	ON_BN_CLICKED(IDC_TEST4, OnTest4)
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
	
	for (int n = 0; n < 10; n++)
	{
		CString strText = _T("");
		strText.Format(_T("??????%d"), n);

		//????????1????????
		m_ctrlList1.AddString(strText);
	}

	GetDlgItem(IDC_TEST1)->EnableWindow(TRUE);
	GetDlgItem(IDC_TEST3)->EnableWindow(TRUE);
	GetDlgItem(IDC_TEST2)->EnableWindow(FALSE);
	GetDlgItem(IDC_TEST4)->EnableWindow(FALSE);

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
	CString strText = _T("");

	//??????????1??????????
	int nSel1 = m_ctrlList1.GetCurSel();
	if (nSel1 == LB_ERR)
	{
		return;
	}
	//??????????1????
	m_ctrlList1.GetText(nSel1, strText);
	//????????1????????
	m_ctrlList1.DeleteString(nSel1);
	//??????????1??????????
	m_ctrlList1.SetCurSel(-1);

	//??????????2??????????
	int nSel2 = m_ctrlList2.GetCurSel();
	if (nSel2 == LB_ERR)
	{
		//????????2????????
		m_ctrlList2.AddString(strText);
	}
	else
	{
		//????????2????????
		m_ctrlList2.InsertString(nSel2, strText);
	}
	//??????????2??????????
	m_ctrlList2.SetCurSel(-1);

	if (m_ctrlList1.GetCount() == 0)
	{
		GetDlgItem(IDC_TEST1)->EnableWindow(FALSE);
		GetDlgItem(IDC_TEST3)->EnableWindow(FALSE);
	}
	GetDlgItem(IDC_TEST2)->EnableWindow(TRUE);
	GetDlgItem(IDC_TEST4)->EnableWindow(TRUE);
}

void CDemoDlg::OnTest2() 
{
	CString strText = _T("");

	//??????????2??????????
	int nSel2 = m_ctrlList2.GetCurSel();
	if (nSel2 == LB_ERR)
	{
		return;
	}
	//??????????2????
	m_ctrlList2.GetText(nSel2, strText);
	//????????2????????
	m_ctrlList2.DeleteString(nSel2);
	//??????????2??????????
	m_ctrlList2.SetCurSel(-1);

	//??????????1??????????
	int nSel1 = m_ctrlList1.GetCurSel();
	if (nSel1 == LB_ERR)
	{
		//????????1????????
		m_ctrlList1.AddString(strText);
	}
	else
	{
		//????????1????????
		m_ctrlList1.InsertString(nSel1, strText);
	}
	//??????????1??????????
	m_ctrlList1.SetCurSel(-1);

	if (m_ctrlList2.GetCount() == 0)
	{
		GetDlgItem(IDC_TEST2)->EnableWindow(FALSE);
		GetDlgItem(IDC_TEST4)->EnableWindow(FALSE);
	}
	GetDlgItem(IDC_TEST1)->EnableWindow(TRUE);
	GetDlgItem(IDC_TEST3)->EnableWindow(TRUE);
}

void CDemoDlg::OnTest3() 
{
	CString strText = _T("");

	//??????????2??????????
	int nSel2 = m_ctrlList2.GetCurSel();
	if (nSel2 == LB_ERR)
	{
		for (int n = 0; n < m_ctrlList1.GetCount(); n++)
		{
			//??????????1????
			m_ctrlList1.GetText(n, strText);
			//????????2????????
			m_ctrlList2.AddString(strText);
		}
	}
	else
	{
		for (int n = 0; n < m_ctrlList1.GetCount(); n++)
		{
			//??????????1????
			m_ctrlList1.GetText(n, strText);
			//????????2????????
			m_ctrlList2.InsertString(nSel2, strText);
		}	
	}

	//??????????2??????????
	m_ctrlList2.SetCurSel(-1);

	//??????????1????
	m_ctrlList1.ResetContent();

	GetDlgItem(IDC_TEST1)->EnableWindow(FALSE);
	GetDlgItem(IDC_TEST3)->EnableWindow(FALSE);
	GetDlgItem(IDC_TEST2)->EnableWindow(TRUE);
	GetDlgItem(IDC_TEST4)->EnableWindow(TRUE);
}

void CDemoDlg::OnTest4() 
{
	CString strText = _T("");

	//??????????1??????????
	int nSel1 = m_ctrlList1.GetCurSel();
	if (nSel1 == LB_ERR)
	{
		for (int n = 0; n < m_ctrlList2.GetCount(); n++)
		{
			//??????????2????
			m_ctrlList2.GetText(n, strText);
			//????????1????????
			m_ctrlList1.AddString(strText);
		}
	}
	else
	{
		for (int n = 0; n < m_ctrlList2.GetCount(); n++)
		{
			//??????????2????
			m_ctrlList2.GetText(n, strText);
			//????????1????????
			m_ctrlList1.InsertString(nSel1, strText);
		}	
	}

	//??????????1??????????
	m_ctrlList1.SetCurSel(-1);

	//??????????2????
	m_ctrlList2.ResetContent();

	GetDlgItem(IDC_TEST2)->EnableWindow(FALSE);
	GetDlgItem(IDC_TEST4)->EnableWindow(FALSE);
	GetDlgItem(IDC_TEST1)->EnableWindow(TRUE);
	GetDlgItem(IDC_TEST3)->EnableWindow(TRUE);
}
