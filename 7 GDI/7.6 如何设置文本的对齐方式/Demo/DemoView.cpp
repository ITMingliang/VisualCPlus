// DemoView.cpp : implementation of the CDemoView class
//

#include "stdafx.h"
#include "Demo.h"

#include "DemoDoc.h"
#include "DemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoView

IMPLEMENT_DYNCREATE(CDemoView, CView)

BEGIN_MESSAGE_MAP(CDemoView, CView)
	//{{AFX_MSG_MAP(CDemoView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
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

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView drawing

void CDemoView::OnDraw(CDC* pDC)
{
	CRect rect;
	GetClientRect(rect);

	pDC->MoveTo(rect.Width() / 2, 0);
	pDC->LineTo(rect.Width() / 2, rect.Height() / 2);
	pDC->MoveTo(0, 3 * rect.Height() / 4);
	pDC->LineTo(rect.Width(), 3 * rect.Height() / 4);

	//设置透明背景
	pDC->SetBkMode(TRANSPARENT);

	//设置左对齐
	pDC->SetTextAlign(TA_LEFT);
	pDC->TextOut(rect.Width() / 2, 0, _T("TA_LEFT"));

	//设置中间对齐
	pDC->SetTextAlign(TA_CENTER);
	pDC->TextOut(rect.Width() / 2, 25, _T("TA_CENTER"));

	//设置右对齐
	pDC->SetTextAlign(TA_RIGHT);
	pDC->TextOut(rect.Width() / 2, 50, _T("TA_RIGHT"));

	//设置基线对齐
	pDC->SetTextAlign(TA_CENTER | TA_BASELINE);
	pDC->TextOut(rect.Width() / 4, 3 * rect.Height() / 4, _T("TA_BASELINE"));

	//设置上对齐
	pDC->SetTextAlign(TA_CENTER | TA_TOP);
	pDC->TextOut(rect.Width() / 2, 3 * rect.Height() / 4, _T("TA_TOP"));

	//设置下对齐
	pDC->SetTextAlign(TA_CENTER | TA_BOTTOM);
	pDC->TextOut(3 * rect.Width() / 4, 3 * rect.Height() / 4, _T("TA_BOTTOM"));
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView printing

BOOL CDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView diagnostics

#ifdef _DEBUG
void CDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDemoDoc* CDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemoDoc)));
	return (CDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDemoView message handlers
