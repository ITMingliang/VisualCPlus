// DemoView1.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "DemoView1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoView1

IMPLEMENT_DYNCREATE(CDemoView1, CView)

CDemoView1::CDemoView1()
{
}

CDemoView1::~CDemoView1()
{
}


BEGIN_MESSAGE_MAP(CDemoView1, CView)
	//{{AFX_MSG_MAP(CDemoView1)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoView1 drawing

void CDemoView1::OnDraw(CDC* pDC)
{
	pDC->TextOut(100, 100, _T("DemoView1"));
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
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDemoView1 message handlers
