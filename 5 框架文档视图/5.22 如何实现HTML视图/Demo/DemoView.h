// DemoView.h : interface of the CDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEMOVIEW_H__FDB0C524_46B1_475D_BF83_CEA193D40EDA__INCLUDED_)
#define AFX_DEMOVIEW_H__FDB0C524_46B1_475D_BF83_CEA193D40EDA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDemoView : public CHtmlView
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
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDemoView)
	afx_msg void OnNavigate();
	afx_msg void OnGoBack();
	afx_msg void OnGoForward();
	afx_msg void OnStop();
	afx_msg void OnRefresh();
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

#endif // !defined(AFX_DEMOVIEW_H__FDB0C524_46B1_475D_BF83_CEA193D40EDA__INCLUDED_)
