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

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_INSERT_MENU, OnInsertMenu)
	ON_COMMAND(ID_REMOVE_MENU, OnRemoveMenu)
	ON_COMMAND(ID_TEST_MENU, OnTestMenu)
	ON_COMMAND(ID_APPEND_MENU, OnAppendMenu)
	ON_COMMAND(ID_DELETE_MENU, OnDeleteMenu)
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
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
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
	if( !CFrameWnd::PreCreateWindow(cs) )
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
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers
void CMainFrame::OnAppendMenu() 
{
	//??????????
	CMenu* pMenu = GetMenu();
	//??????????
	CMenu* pSubMenu = pMenu->GetSubMenu(4);

	if (pSubMenu->GetMenuItemCount() == 4)
	{
		//????????????????????
		pSubMenu->AppendMenu(MF_STRING, ID_TEST_MENU, _T("????????"));

		//????????
		DrawMenuBar();
	}
}

void CMainFrame::OnInsertMenu() 
{
	//??????????
	CMenu* pMenu = GetMenu();
	//??????????
	CMenu* pSubMenu = pMenu->GetSubMenu(4);

	if (pSubMenu->GetMenuItemCount() == 4)
	{
		//????????????????????????
		pSubMenu->InsertMenu(4, MF_BYPOSITION, ID_TEST_MENU, _T("????????"));

		//????????
		DrawMenuBar();
	}
}

void CMainFrame::OnRemoveMenu() 
{
	//??????????
	CMenu* pMenu = GetMenu();
	//??????????
	CMenu* pSubMenu = pMenu->GetSubMenu(4);

	if (pSubMenu->GetMenuItemCount() == 5)
	{
 		//??????????
 		pSubMenu->RemoveMenu(4, MF_BYPOSITION);

		//????????
		DrawMenuBar();
	}
}

void CMainFrame::OnDeleteMenu() 
{
	//??????????
	CMenu* pMenu = GetMenu();
	//??????????
	CMenu* pSubMenu = pMenu->GetSubMenu(4);

	if (pSubMenu->GetMenuItemCount() == 5)
	{
 		//??????????
 		pSubMenu->DeleteMenu(4, MF_BYPOSITION);

		//????????
		DrawMenuBar();
	}
}

void CMainFrame::OnTestMenu() 
{
	AfxMessageBox(_T("??????????????"));	
}
