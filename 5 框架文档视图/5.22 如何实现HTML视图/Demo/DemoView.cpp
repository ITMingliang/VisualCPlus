// DemoView.cpp : implementation of the CDemoView class
//

#include "stdafx.h"
#include "Demo.h"

#include "DemoDoc.h"
#include "DemoView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoView

IMPLEMENT_DYNCREATE(CDemoView, CHtmlView)

BEGIN_MESSAGE_MAP(CDemoView, CHtmlView)
	//{{AFX_MSG_MAP(CDemoView)
	ON_COMMAND(IDC_NAVIGATE, OnNavigate)
	ON_COMMAND(IDC_GOBACK, OnGoBack)
	ON_COMMAND(IDC_GOFORWARD, OnGoForward)
	ON_COMMAND(IDC_STOP, OnStop)
	ON_COMMAND(IDC_REFRESH, OnRefresh)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CHtmlView::OnFilePrint)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoView construction/destruction

CDemoView::CDemoView()
{
	// TODO: add construction code here

}

CDemoView::~CDemoView()
{
}

BOOL CDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CHtmlView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView drawing

void CDemoView::OnDraw(CDC* pDC)
{
	CDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CDemoView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	// TODO: This code navigates to a popular spot on the web.
	//  change the code to go where you'd like.
	Navigate2(_T("http://www.microsoft.com/visualc/"),NULL,NULL);
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView printing


/////////////////////////////////////////////////////////////////////////////
// CDemoView diagnostics

#ifdef _DEBUG
void CDemoView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CDemoView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CDemoDoc* CDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemoDoc)));
	return (CDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDemoView message handlers

void CDemoView::OnNavigate()
{
	CMainFrame* pMainFrame = (CMainFrame *)AfxGetMainWnd();
	CDialogBar* pDialogBar = &(pMainFrame->m_wndDlgBar);

	CString strAddress = _T("");
	pDialogBar->GetDlgItemText(IDC_ADDRESS, strAddress);

	//浏览
	Navigate2(strAddress);

	Invalidate(FALSE);	
}

void CDemoView::OnGoBack()
{
	//后退
	GoBack();
}

void CDemoView::OnGoForward()
{
	//前进
	GoForward();
}

void CDemoView::OnStop()
{
	//停止
	Stop();
}

void CDemoView::OnRefresh()
{
	//刷新
	Refresh();
}