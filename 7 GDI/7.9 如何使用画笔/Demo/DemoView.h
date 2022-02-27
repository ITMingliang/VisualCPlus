// DemoView.h : interface of the CDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEMOVIEW_H__F6F09E33_6C8E_417C_B21D_44F26212822B__INCLUDED_)
#define AFX_DEMOVIEW_H__F6F09E33_6C8E_417C_B21D_44F26212822B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDemoView : public CView
{
protected: // create from serialization only
	CDemoView();
	DECLARE_DYNCREATE(CDemoView)

// Attributes
public:
	CDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	CPen m_Pen;
	int m_nStyle;
	int m_nWidth;
	COLORREF m_crColor;
	BOOL m_bDraw;
	CPoint m_StartPoint;
	CPoint m_EndPoint;
	virtual ~CDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDemoView)
	afx_msg void OnSetSolidStyle();
	afx_msg void OnUpdateSetSolidStyle(CCmdUI* pCmdUI);
	afx_msg void OnSetDashStyle();
	afx_msg void OnUpdateSetDashStyle(CCmdUI* pCmdUI);
	afx_msg void OnSetDotStyle();
	afx_msg void OnUpdateSetDotStyle(CCmdUI* pCmdUI);
	afx_msg void OnSetRedColor();
	afx_msg void OnUpdateSetRedColor(CCmdUI* pCmdUI);
	afx_msg void OnSetGreenColor();
	afx_msg void OnUpdateSetGreenColor(CCmdUI* pCmdUI);
	afx_msg void OnSetBlueColor();
	afx_msg void OnUpdateSetBlueColor(CCmdUI* pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnSetWidth1();
	afx_msg void OnUpdateSetWidth1(CCmdUI* pCmdUI);
	afx_msg void OnSetWidth2();
	afx_msg void OnUpdateSetWidth2(CCmdUI* pCmdUI);
	afx_msg void OnSetWidth3();
	afx_msg void OnUpdateSetWidth3(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DemoView.cpp
inline CDemoDoc* CDemoView::GetDocument()
   { return (CDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMOVIEW_H__F6F09E33_6C8E_417C_B21D_44F26212822B__INCLUDED_)
