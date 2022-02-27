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
	ON_WM_SETCURSOR()
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
	//����Tracker����
	m_RectTracker.m_rect.SetRect(0, 0, 100, 100);
	//����Tracker���
	m_RectTracker.m_nStyle = CRectTracker::resizeInside | CRectTracker::dottedLine;
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
	//���Tracker����
	CRect rect;
	m_RectTracker.GetTrueRect(rect);

	//����Tracker����
	m_RectTracker.Draw(pDC);

	//��������
	CPen pen;
	pen.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	//������ˢ
	CBrush brush;
	brush.CreateSolidBrush(RGB(255, 0, 0));

	//ѡ�񻭱�
	CPen* pOldPen = pDC->SelectObject(&pen);
	//ѡ��ˢ
	CBrush* pOldBrush = pDC->SelectObject(&brush);

	//������Բ
	pDC->Ellipse(rect);
	
	//�ָ�ԭ���Ļ���
	pDC->SelectObject(pOldPen);
	//�ָ�ԭ���Ļ�ˢ
	pDC->SelectObject(pOldBrush);
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

BOOL CDemoView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	if (pWnd == this)
	{
		//���ù��
		if (m_RectTracker.SetCursor(this, nHitTest))
		{
			return TRUE; 
		}
	}

	return CView::OnSetCursor(pWnd, nHitTest, message);
}

void CDemoView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	//��ù��ĵ�ǰλ��
	int nHit = m_RectTracker.HitTest(point);
	
	if (nHit != CRectTracker::hitNothing)
	{
		//��������
		m_RectTracker.Track (this, point, TRUE);
	}
	else
	{
		//ѡ����Ƥ�����
		m_RectTracker.TrackRubberBand(this, point, TRUE);	
	}

	//ˢ��
	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}
