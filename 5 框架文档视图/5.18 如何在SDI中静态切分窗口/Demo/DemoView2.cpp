// DemoView2.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "DemoView2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoView2

IMPLEMENT_DYNCREATE(CDemoView2, CView)

CDemoView2::CDemoView2()
{
}

CDemoView2::~CDemoView2()
{
}


BEGIN_MESSAGE_MAP(CDemoView2, CView)
	//{{AFX_MSG_MAP(CDemoView2)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoView2 drawing

void CDemoView2::OnDraw(CDC* pDC)
{
	pDC->TextOut(100, 100, _T("DemoView2"));
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView2 diagnostics

#ifdef _DEBUG
void CDemoView2::AssertValid() const
{
	CView::AssertValid();
}

void CDemoView2::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDemoView2 message handlers
