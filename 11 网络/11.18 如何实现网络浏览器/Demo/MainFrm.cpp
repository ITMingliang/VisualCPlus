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
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	ON_WM_CREATE()
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

	//创建Rebar
	if (!m_wndReBar.Create(this))
	{
		return -1;
	}

	//创建工具栏
	if (!m_wndToolBar.CreateEx(this))
	{
		return -1;
	}

	//设置工具栏图像列表
	CImageList ToolBarImageList;
	ToolBarImageList.Create(IDB_TOOLBAR, 22, 0, RGB(255, 0, 255));
	m_wndToolBar.GetToolBarCtrl().SetImageList(&ToolBarImageList);
	ToolBarImageList.Detach();

	//设置工具栏风格
	m_wndToolBar.GetToolBarCtrl().SetExtendedStyle(TBSTYLE_EX_DRAWDDARROWS);
	m_wndToolBar.ModifyStyle(0, TBSTYLE_FLAT | TBSTYLE_TRANSPARENT);

	//设置工具栏按钮
	m_wndToolBar.GetToolBarCtrl().SetButtonWidth(20, 100);
	m_wndToolBar.SetButtons(NULL, 6);
 	CString strText = _T("");
	//后退
	m_wndToolBar.SetButtonInfo(0, ID_GO_BACK, TBSTYLE_BUTTON, 0);
	strText = _T("后退");
	m_wndToolBar.SetButtonText(0, strText);
	//前进
	m_wndToolBar.SetButtonInfo(1, ID_GO_FORWARD, TBSTYLE_BUTTON, 1);
	strText = _T("前进");
	m_wndToolBar.SetButtonText(1, strText);
	//停止
	m_wndToolBar.SetButtonInfo(2, ID_STOP, TBSTYLE_BUTTON, 2);
	strText = _T("停止");
	m_wndToolBar.SetButtonText(2, strText);
	//刷新
	m_wndToolBar.SetButtonInfo(3, ID_GO_REFRESH, TBSTYLE_BUTTON, 3);
	strText = _T("刷新");
	m_wndToolBar.SetButtonText(3, strText);
	//主页
	m_wndToolBar.SetButtonInfo(4, ID_GO_HOME, TBSTYLE_BUTTON, 4);
	strText = _T("主页");
	m_wndToolBar.SetButtonText(4, strText);
	//搜索
	m_wndToolBar.SetButtonInfo(5, ID_GO_SERACH, TBSTYLE_BUTTON, 5);
	strText = _T("搜索");
	m_wndToolBar.SetButtonText(5, strText);

	//设置工具栏尺寸
	CRect rcToolBar;
	m_wndToolBar.GetItemRect(0, &rcToolBar);
	m_wndToolBar.SetSizes(CSize(40, 40), CSize(25, 20));

	//创建组合框作为地址栏
	m_wndAddressBar.Create(CBS_DROPDOWN | WS_CHILD, 
		CRect(0, 0, 200, 120), this, IDC_ADDRESS);

	//添加工具栏、地址栏到Rebar中
	m_wndReBar.AddBar(&m_wndToolBar);
	m_wndReBar.AddBar(&m_wndAddressBar, _T("地址："), NULL, 
		RBBS_GRIPPERALWAYS | RBBS_FIXEDBMP | RBBS_BREAK);

	//创建状态栏
	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		return -1;
	}

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

