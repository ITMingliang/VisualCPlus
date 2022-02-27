// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Demo.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	ON_WM_CREATE()
	ON_CBN_SELCHANGE(ID_COMBOBOX, OnSelchangeCombobox)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here

}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	//创建组合框
	if (!CreateComboBox(ID_COMBOBOX))
	{
		TRACE0("Failed to create combo box\n");
		return -1;
	}
	
	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

BOOL CMainFrame::CreateComboBox(UINT nID)
{
	int nIndex = 0;
	CRect rect;

	//查找按钮
	while (m_wndToolBar.GetItemID(nIndex) != nID)
	{
		nIndex++;
	}

    //为组合框创建一个空白区域
	m_wndToolBar.SetButtonInfo(nIndex, nID, TBBS_SEPARATOR, 80);

	//获得空白区域大小和位置
	m_wndToolBar.GetItemRect(nIndex, &rect);

	//组合框大小和位置
	rect.top += 0;
	rect.bottom += 200;

	//在空白区域创建组合框
	if (!m_ComboBox.Create(WS_CHILD | WS_VISIBLE | CBS_AUTOHSCROLL | 
		CBS_DROPDOWNLIST | CBS_HASSTRINGS, rect, &m_wndToolBar, nID))
    {
		TRACE0("Failed to create combo-box\n");
		return FALSE;
    }

	//显示组合框
	m_ComboBox.ShowWindow(SW_SHOW);

	//在组合框中添加字符串
	m_ComboBox.AddString("500%");
	m_ComboBox.AddString("200%");
	m_ComboBox.AddString("150%");
	m_ComboBox.AddString("100%");
	m_ComboBox.AddString("75%");
	m_ComboBox.AddString("50%");
	m_ComboBox.AddString("25%");
	m_ComboBox.AddString("10%");
	m_ComboBox.SetCurSel(3);

	return TRUE;
}

void CMainFrame::OnSelchangeCombobox() 
{
	CString strText = _T("");
	m_ComboBox.GetWindowText(strText);
	AfxMessageBox(strText);
}