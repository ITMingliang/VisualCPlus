// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Demo.h"

#include "MainFrm.h"
#include "DemoDoc.h"
#include "DemoView1.h"
#include "DemoView2.h"

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
	ON_COMMAND(ID_SWITCH_VIEW1, OnSwitchView1)
	ON_COMMAND(ID_SWITCH_VIEW2, OnSwitchView2)
	ON_UPDATE_COMMAND_UI(ID_SWITCH_VIEW1, OnUpdateSwitchView1)
	ON_UPDATE_COMMAND_UI(ID_SWITCH_VIEW2, OnUpdateSwitchView2)
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

void CMainFrame::SwitchView(int nView)
{
	//获得旧视图（活动视图）指针
	CView* pOldView = GetActiveView();
	//获得新视图指针
	CView* pNewView = (CView*)GetDlgItem(nView);
	if (pNewView == NULL)
	{
		if (nView == 1)
		{
			pNewView = new CDemoView1();
		}
		else if (nView == 2)
		{
			pNewView = new CDemoView2();
		}
		else
		{
			return;
		}

		CCreateContext context;
		context.m_pCurrentDoc = pOldView->GetDocument();

		//创建新视图
		pNewView->Create(NULL, NULL, WS_BORDER, CFrameWnd::rectDefault, 
			this, nView, &context);
		
		pNewView->OnInitialUpdate();
	}

	//设置新视图为活动视图
	SetActiveView(pNewView);

	//显示新视图
	pNewView->ShowWindow(SW_NORMAL);	
	//隐藏旧视图
	pOldView->ShowWindow(SW_HIDE);

	//设置旧视图ID
	if (pOldView->GetRuntimeClass() == RUNTIME_CLASS(CDemoView1))
	{
		pOldView->SetDlgCtrlID(1);
	}
	else if (pOldView->GetRuntimeClass() == RUNTIME_CLASS(CDemoView2))
	{
		pOldView->SetDlgCtrlID(2);
	}
	//设置新视图ID
	pNewView->SetDlgCtrlID(AFX_IDW_PANE_FIRST);

	//重新布局
	RecalcLayout();										
}

void CMainFrame::OnSwitchView1() 
{
	SwitchView(1);
}

void CMainFrame::OnUpdateSwitchView1(CCmdUI* pCmdUI) 
{
	if (GetActiveView()->IsKindOf(RUNTIME_CLASS(CDemoView1)))
	{
		pCmdUI->Enable(FALSE);
	}
	else
	{
		pCmdUI->Enable(TRUE);
	}
}

void CMainFrame::OnSwitchView2() 
{
	SwitchView(2);
}

void CMainFrame::OnUpdateSwitchView2(CCmdUI* pCmdUI) 
{
	if (GetActiveView()->IsKindOf(RUNTIME_CLASS(CDemoView2)))
	{
		pCmdUI->Enable(FALSE);
	}
	else
	{
		pCmdUI->Enable(TRUE);
	}
}
