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
	ON_COMMAND(ID_CREATE_SOLIDBRUSH, OnCreateSolidBrush)
	ON_COMMAND(ID_CREATE_HATCHBRUSH, OnCreateHatchBrush)
	ON_COMMAND(ID_CREATE_PATTERNBRUSH, OnCreatePatternBrush)
	ON_UPDATE_COMMAND_UI(ID_CREATE_SOLIDBRUSH, OnUpdateCreateSolidbrush)
	ON_UPDATE_COMMAND_UI(ID_CREATE_HATCHBRUSH, OnUpdateCreateHatchbrush)
	ON_UPDATE_COMMAND_UI(ID_CREATE_PATTERNBRUSH, OnUpdateCreatePatternbrush)
	ON_WM_LBUTTONDOWN()
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
	m_nType = 0;

	COLORREF crColor = RGB(255, 0, 0);

	//创建实线画刷
	m_Brush.CreateSolidBrush(crColor);
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

	OnLButtonDown(0, CPoint(75,75));

	OnCreateHatchBrush();
	OnLButtonDown(0, CPoint(150,75));

	OnCreatePatternBrush();
	OnLButtonDown(0, CPoint(225,75));
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

void CDemoView::OnCreateSolidBrush() 
{
	m_nType = 0;

	m_Brush.DeleteObject();

	COLORREF crColor = RGB(255, 0, 0);

	//创建实线画刷
	m_Brush.CreateSolidBrush(crColor);
}

void CDemoView::OnUpdateCreateSolidbrush(CCmdUI* pCmdUI) 
{
	if (m_nType == 0)
	{
		pCmdUI->SetCheck(TRUE);
	}
	else
	{
		pCmdUI->SetCheck(FALSE);
	}
}

void CDemoView::OnCreateHatchBrush() 
{
	m_nType = 1;

	m_Brush.DeleteObject();

	COLORREF crColor = RGB(255, 0, 0);

	//创建阴影线画刷
	m_Brush.CreateHatchBrush(HS_CROSS, crColor);
}

void CDemoView::OnUpdateCreateHatchbrush(CCmdUI* pCmdUI) 
{
	if (m_nType == 1)
	{
		pCmdUI->SetCheck(TRUE);
	}
	else
	{
		pCmdUI->SetCheck(FALSE);
	}
}

void CDemoView::OnCreatePatternBrush() 
{
	m_nType = 3;

	m_Brush.DeleteObject();

	//创建图案
	WORD HatchBits[8] = {0x11, 0x22, 0x44, 0x88, 0x11, 0x22, 0x44, 0x88};

	//创建位图
	CBitmap bmp;
	bmp.CreateBitmap(8, 8, 1, 1, HatchBits);

	//创建位图图案画刷
	m_Brush.CreatePatternBrush(&bmp);
}

void CDemoView::OnUpdateCreatePatternbrush(CCmdUI* pCmdUI) 
{
	if (m_nType == 2)
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
	CDC* pDC = GetDC();

	//选择画笔
	CPen* pOldPen = (CPen*)pDC->SelectStockObject(NULL_PEN);
	//选择画刷
	CBrush* pOldBrush = (CBrush*)pDC->SelectObject(&m_Brush);

	pDC->Ellipse(point.x - 25, point.y - 25, point.x + 25, point.y + 25);

	//恢复画笔
	pDC->SelectObject(pOldPen);
	//恢复画刷
	pDC->SelectObject(pOldBrush);

	CView::OnLButtonDown(nFlags, point);
}
