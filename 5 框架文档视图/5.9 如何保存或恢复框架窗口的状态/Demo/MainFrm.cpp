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
	ON_WM_CLOSE()
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
	m_bFirst = TRUE;	
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


void CMainFrame::ActivateFrame(int nCmdShow) 
{
	if (m_bFirst)
	{
		m_bFirst = FALSE;

		WINDOWPLACEMENT* pWndpl = new WINDOWPLACEMENT;
		pWndpl->length = sizeof(WINDOWPLACEMENT);

		CWinApp* pApp = AfxGetApp();

		//恢复窗口位置
		pWndpl->flags = pApp->GetProfileInt(_T("WINDOWPLACEMENT"), 
			_T("FLAGS"), 0);
		pWndpl->showCmd = pApp->GetProfileInt(_T("WINDOWPLACEMENT"), 
			_T("SHOWCMD"), 0);
		nCmdShow = pWndpl->showCmd;
		pWndpl->ptMinPosition.x = pApp->GetProfileInt(_T("WINDOWPLACEMENT"), 
			_T("MINX"), 0);	
		pWndpl->ptMinPosition.y = pApp->GetProfileInt(_T("WINDOWPLACEMENT"), 
			_T("MINY"), 0);	
		pWndpl->ptMaxPosition.x = pApp->GetProfileInt(_T("WINDOWPLACEMENT"), 
			_T("MAXX"), 0);
		pWndpl->ptMaxPosition.y = pApp->GetProfileInt(_T("WINDOWPLACEMENT"),
			_T("MAXY"), 0);
		pWndpl->rcNormalPosition.top = pApp->GetProfileInt(_T("WINDOWPLACEMENT"), 
			_T("TOP"), 0);
		pWndpl->rcNormalPosition.left = pApp->GetProfileInt(_T("WINDOWPLACEMENT"), 
			_T("LEFT"), 0);
		pWndpl->rcNormalPosition.right = pApp->GetProfileInt(_T("WINDOWPLACEMENT"), 
			_T("RIGHT"), 0);
		pWndpl->rcNormalPosition.bottom = pApp->GetProfileInt(_T("WINDOWPLACEMENT"), 
			_T("BOTTOM"), 0);

		//设置窗口位置
		SetWindowPlacement(pWndpl);

		delete pWndpl;
	}

	CFrameWnd::ActivateFrame(nCmdShow);
}

void CMainFrame::OnClose() 
{
	WINDOWPLACEMENT* pWndpl = new WINDOWPLACEMENT;
	pWndpl->length = sizeof(WINDOWPLACEMENT);

	//获得窗口位置
	GetWindowPlacement(pWndpl);

	CWinApp* pApp = AfxGetApp();

	//保存窗口位置
	pApp->WriteProfileInt(_T("WINDOWPLACEMENT"), _T("FLAGS"), 
		pWndpl->flags);
	pApp->WriteProfileInt(_T("WINDOWPLACEMENT"), _T("SHOWCMD"), 
		pWndpl->showCmd);
	pApp->WriteProfileInt(_T("WINDOWPLACEMENT"), _T("MINX"), 
		pWndpl->ptMinPosition.x);
	pApp->WriteProfileInt(_T("WINDOWPLACEMENT"), _T("MINY"), 
		pWndpl->ptMinPosition.y);
	pApp->WriteProfileInt(_T("WINDOWPLACEMENT"), _T("MAXX"), 
		pWndpl->ptMaxPosition.x);
	pApp->WriteProfileInt(_T("WINDOWPLACEMENT"), _T("MAXY"), 
		pWndpl->ptMaxPosition.y);
	pApp->WriteProfileInt(_T("WINDOWPLACEMENT"), _T("TOP"), 
		pWndpl->rcNormalPosition.left);
	pApp->WriteProfileInt(_T("WINDOWPLACEMENT"), _T("LEFT"), 
		pWndpl->rcNormalPosition.top);
	pApp->WriteProfileInt(_T("WINDOWPLACEMENT"), _T("RIGHT"), 
		pWndpl->rcNormalPosition.right);
	pApp->WriteProfileInt(_T("WINDOWPLACEMENT"), _T("BOTTOM"), 
		pWndpl->rcNormalPosition.bottom);

	delete pWndpl;

	CFrameWnd::OnClose();
}

