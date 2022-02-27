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
	ON_COMMAND(ID_SET_SOLIDSTYLE, OnSetSolidStyle)
	ON_UPDATE_COMMAND_UI(ID_SET_SOLIDSTYLE, OnUpdateSetSolidStyle)
	ON_COMMAND(ID_SET_DASHSTYLE, OnSetDashStyle)
	ON_UPDATE_COMMAND_UI(ID_SET_DASHSTYLE, OnUpdateSetDashStyle)
	ON_COMMAND(ID_SET_DOTSTYLE, OnSetDotStyle)
	ON_UPDATE_COMMAND_UI(ID_SET_DOTSTYLE, OnUpdateSetDotStyle)
	ON_COMMAND(ID_SET_REDCOLOR, OnSetRedColor)
	ON_UPDATE_COMMAND_UI(ID_SET_REDCOLOR, OnUpdateSetRedColor)
	ON_COMMAND(ID_SET_GREENCOLOR, OnSetGreenColor)
	ON_UPDATE_COMMAND_UI(ID_SET_GREENCOLOR, OnUpdateSetGreenColor)
	ON_COMMAND(ID_SET_BLUECOLOR, OnSetBlueColor)
	ON_UPDATE_COMMAND_UI(ID_SET_BLUECOLOR, OnUpdateSetBlueColor)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_SET_WIDTH1, OnSetWidth1)
	ON_UPDATE_COMMAND_UI(ID_SET_WIDTH1, OnUpdateSetWidth1)
	ON_COMMAND(ID_SET_WIDTH2, OnSetWidth2)
	ON_UPDATE_COMMAND_UI(ID_SET_WIDTH2, OnUpdateSetWidth2)
	ON_COMMAND(ID_SET_WIDTH3, OnSetWidth3)
	ON_UPDATE_COMMAND_UI(ID_SET_WIDTH3, OnUpdateSetWidth3)
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
	m_nStyle = PS_SOLID;
	m_nWidth = 1;
	m_crColor = RGB(255, 0, 0);

	//创建画笔
	m_Pen.CreatePen(m_nStyle, m_nWidth, m_crColor);

	m_bDraw = FALSE;

	m_StartPoint = CPoint(0, 0);
	m_EndPoint = CPoint(0, 0);
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
	CDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
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

void CDemoView::OnSetSolidStyle() 
{
	m_nStyle = PS_SOLID;

	m_Pen.DeleteObject();

	//创建画笔
	m_Pen.CreatePen(m_nStyle, m_nWidth, m_crColor);
}

void CDemoView::OnUpdateSetSolidStyle(CCmdUI* pCmdUI) 
{
	if (m_nStyle == PS_SOLID)
	{
		pCmdUI->SetCheck(TRUE);
	}
	else
	{
		pCmdUI->SetCheck(FALSE);
	}
}

void CDemoView::OnSetDashStyle() 
{
	m_nStyle = PS_DASH;

	m_Pen.DeleteObject();

	//创建画笔
	m_Pen.CreatePen(m_nStyle, m_nWidth, m_crColor);
}

void CDemoView::OnUpdateSetDashStyle(CCmdUI* pCmdUI) 
{
	if (m_nStyle == PS_DASH)
	{
		pCmdUI->SetCheck(TRUE);
	}
	else
	{
		pCmdUI->SetCheck(FALSE);
	}
}

void CDemoView::OnSetDotStyle() 
{
	m_nStyle = PS_DOT;

	m_Pen.DeleteObject();

	//创建画笔
	m_Pen.CreatePen(m_nStyle, m_nWidth, m_crColor);
}

void CDemoView::OnUpdateSetDotStyle(CCmdUI* pCmdUI) 
{
	if (m_nStyle == PS_DOT)
	{
		pCmdUI->SetCheck(TRUE);
	}
	else
	{
		pCmdUI->SetCheck(FALSE);
	}
}

void CDemoView::OnSetWidth1() 
{
	m_nWidth = 1;

	m_Pen.DeleteObject();

	//创建画笔
	m_Pen.CreatePen(m_nStyle, m_nWidth, m_crColor);
}

void CDemoView::OnUpdateSetWidth1(CCmdUI* pCmdUI) 
{
	if (m_nWidth == 1)
	{
		pCmdUI->SetCheck(TRUE);
	}
	else
	{
		pCmdUI->SetCheck(FALSE);
	}
}

void CDemoView::OnSetWidth2() 
{
	m_nWidth = 2;

	m_Pen.DeleteObject();

	//创建画笔
	m_Pen.CreatePen(m_nStyle, m_nWidth, m_crColor);	
}

void CDemoView::OnUpdateSetWidth2(CCmdUI* pCmdUI) 
{
	if (m_nWidth == 2)
	{
		pCmdUI->SetCheck(TRUE);
	}
	else
	{
		pCmdUI->SetCheck(FALSE);
	}
}

void CDemoView::OnSetWidth3() 
{
	m_nWidth = 3;

	m_Pen.DeleteObject();

	//创建画笔
	m_Pen.CreatePen(m_nStyle, m_nWidth, m_crColor);	
}

void CDemoView::OnUpdateSetWidth3(CCmdUI* pCmdUI) 
{
	if (m_nWidth == 3)
	{
		pCmdUI->SetCheck(TRUE);
	}
	else
	{
		pCmdUI->SetCheck(FALSE);
	}	
}

void CDemoView::OnSetRedColor() 
{
	m_crColor = RGB(255, 0, 0);

	m_Pen.DeleteObject();

	//创建画笔
	m_Pen.CreatePen(m_nStyle, m_nWidth, m_crColor);
}

void CDemoView::OnUpdateSetRedColor(CCmdUI* pCmdUI) 
{
	if (m_crColor == RGB(255, 0, 0))
	{
		pCmdUI->SetCheck(TRUE);
	}
	else
	{
		pCmdUI->SetCheck(FALSE);
	}
}

void CDemoView::OnSetGreenColor() 
{
	m_crColor = RGB(0, 255, 0);

	m_Pen.DeleteObject();

	//创建画笔
	m_Pen.CreatePen(m_nStyle, m_nWidth, m_crColor);
}

void CDemoView::OnUpdateSetGreenColor(CCmdUI* pCmdUI) 
{
	if (m_crColor == RGB(255, 255, 0))
	{
		pCmdUI->SetCheck(TRUE);
	}
	else
	{
		pCmdUI->SetCheck(FALSE);
	}
}

void CDemoView::OnSetBlueColor() 
{
	m_crColor = RGB(0, 0, 255);

	m_Pen.DeleteObject();

	//创建画笔
	m_Pen.CreatePen(m_nStyle, m_nWidth, m_crColor);
}

void CDemoView::OnUpdateSetBlueColor(CCmdUI* pCmdUI) 
{
	if (m_crColor == RGB(0, 0, 255))
	{
		pCmdUI->SetCheck(TRUE);
	}
	else
	{
		pCmdUI->SetCheck(FALSE);
	}
}

void CDemoView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	m_bDraw = TRUE;

	m_StartPoint = point;

	CView::OnLButtonDown(nFlags, point);
}

void CDemoView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	m_bDraw = FALSE;

	CView::OnLButtonUp(nFlags, point);
}

void CDemoView::OnMouseMove(UINT nFlags, CPoint point) 
{
	if (m_bDraw)
	{
		CDC* pDC = GetDC();

		//选择画笔
		CPen* pOldPen = pDC->SelectObject(&m_Pen);

		m_EndPoint = point;

		//绘制直线
		pDC->MoveTo(m_StartPoint);
		pDC->LineTo(m_EndPoint);

		m_StartPoint = m_EndPoint;

		//恢复画笔
		pDC->SelectObject(pOldPen);
	}

	CView::OnMouseMove(nFlags, point);
}
