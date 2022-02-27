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
	ON_COMMAND(ID_DRAW_LINE, OnDrawLine)
	ON_UPDATE_COMMAND_UI(ID_DRAW_LINE, OnUpdateDrawLine)
	ON_COMMAND(ID_DRAW_RECTANGLE, OnDrawRectangle)
	ON_UPDATE_COMMAND_UI(ID_DRAW_RECTANGLE, OnUpdateDrawRectangle)
	ON_COMMAND(ID_DRAW_ELLIPSE, OnDrawEllipse)
	ON_UPDATE_COMMAND_UI(ID_DRAW_ELLIPSE, OnUpdateDrawEllipse)
	ON_COMMAND(ID_DRAW_PIE, OnDrawPie)
	ON_UPDATE_COMMAND_UI(ID_DRAW_PIE, OnUpdateDrawPie)
	ON_COMMAND(ID_DRAW_POLYGON, OnDrawPolygon)
	ON_UPDATE_COMMAND_UI(ID_DRAW_POLYGON, OnUpdateDrawPolygon)
	ON_COMMAND(ID_DRAW_ROUNDRECT, OnDrawRoundRect)
	ON_UPDATE_COMMAND_UI(ID_DRAW_ROUNDRECT, OnUpdateDrawRoundRect)
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
	m_nDraw = 0;
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
	rect.InflateRect(-50, -50, -50, -50);

	//绘制直线
	if (m_nDraw == 1)
	{
		pDC->MoveTo(rect.left, rect.top);
		pDC->LineTo(rect.right, rect.bottom);
	}
	//绘制矩形
	else if (m_nDraw == 2)
	{
		pDC->Rectangle(rect);
	}
	//绘制圆形或椭圆形
	else if (m_nDraw == 3)
	{
		pDC->Ellipse(rect);
	}
	//绘制扇形
	else if (m_nDraw == 4)
	{
 		pDC->Pie(rect, 
 			CPoint(rect.right, rect.CenterPoint().y),
 			CPoint(rect.CenterPoint().x, rect.right));

	}
	//绘制多边形
	else if (m_nDraw == 5)
	{
		CPoint point[4];
		point[0].x = rect.left + rect.Width() / 2;
		point[0].y = rect.top;
		point[1].x = rect.right;
		point[1].y = rect.top + rect.Height() / 2;
		point[2].x = point[0].x;
		point[2].y = rect.bottom;
		point[3].x = rect.left;
		point[3].y = point[1].y;
		pDC->Polygon(point, 4);
	}
	else if (m_nDraw == 6)
	{
		pDC->RoundRect(rect, CPoint(50, 50));
	}
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

void CDemoView::OnDrawLine() 
{
	//绘制直线
	m_nDraw = 1;

	//刷新
	Invalidate();
}

void CDemoView::OnUpdateDrawLine(CCmdUI* pCmdUI) 
{
	if (m_nDraw == 1)
	{
		pCmdUI->SetCheck(TRUE);
	}
	else
	{
		pCmdUI->SetCheck(FALSE);
	}
}

void CDemoView::OnDrawRectangle() 
{
	//绘制矩形
	m_nDraw = 2;

	//刷新
	Invalidate();
}

void CDemoView::OnUpdateDrawRectangle(CCmdUI* pCmdUI) 
{
	if (m_nDraw == 2)
	{
		pCmdUI->SetCheck(TRUE);
	}
	else
	{
		pCmdUI->SetCheck(FALSE);
	}
}

void CDemoView::OnDrawEllipse() 
{
	//绘制椭圆形
	m_nDraw = 3;

	//刷新
	Invalidate();
}

void CDemoView::OnUpdateDrawEllipse(CCmdUI* pCmdUI) 
{
	if (m_nDraw == 3)
	{
		pCmdUI->SetCheck(TRUE);
	}
	else
	{
		pCmdUI->SetCheck(FALSE);
	}
}

void CDemoView::OnDrawPie() 
{
	//绘制扇形
	m_nDraw = 4;

	//刷新
	Invalidate();
}

void CDemoView::OnUpdateDrawPie(CCmdUI* pCmdUI) 
{
	if (m_nDraw == 4)
	{
		pCmdUI->SetCheck(TRUE);
	}
	else
	{
		pCmdUI->SetCheck(FALSE);
	}
}

void CDemoView::OnDrawPolygon() 
{
	//绘制多边形
	m_nDraw = 5;

	//刷新
	Invalidate();	
}

void CDemoView::OnUpdateDrawPolygon(CCmdUI* pCmdUI) 
{
	if (m_nDraw == 5)
	{
		pCmdUI->SetCheck(TRUE);
	}
	else
	{
		pCmdUI->SetCheck(FALSE);
	}
}

void CDemoView::OnDrawRoundRect() 
{
	//绘制圆矩形
	m_nDraw = 6;

	//刷新
	Invalidate();		
}

void CDemoView::OnUpdateDrawRoundRect(CCmdUI* pCmdUI) 
{
	if (m_nDraw == 6)
	{
		pCmdUI->SetCheck(TRUE);
	}
	else
	{
		pCmdUI->SetCheck(FALSE);
	}
}
