// DemoView1.cpp : implementation of the CDemoView1 class
//

#include "stdafx.h"
#include "Demo.h"

#include "DemoDoc.h"
#include "DemoView1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoView1

IMPLEMENT_DYNCREATE(CDemoView1, CView)

BEGIN_MESSAGE_MAP(CDemoView1, CView)
	//{{AFX_MSG_MAP(CDemoView1)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoView1 construction/destruction

CDemoView1::CDemoView1()
{
	// TODO: add construction code here

}

CDemoView1::~CDemoView1()
{
}

BOOL CDemoView1::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView1 drawing

void CDemoView1::OnDraw(CDC* pDC)
{
	CDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here	
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView1 printing

BOOL CDemoView1::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDemoView1::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDemoView1::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView1 diagnostics

#ifdef _DEBUG
void CDemoView1::AssertValid() const
{
	CView::AssertValid();
}

void CDemoView1::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDemoDoc* CDemoView1::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemoDoc)));
	return (CDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDemoView1 message handlers

void CDemoView1::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	CRect rect;
	GetClientRect(rect);
	CString strText = _T("");
	strText.Format(_T("ÎÄµµÄ£°å%d"), lHint);
	CDC* pDC = GetDC();
	pDC->SetTextAlign(TA_CENTER);
	pDC->TextOut(rect.Width() / 2, rect.Height() / 2, strText);	
}
