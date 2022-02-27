#if !defined(AFX_DEMOVIEW2_H__6CFC1B25_9F7F_4F8C_8660_19349D89DD6D__INCLUDED_)
#define AFX_DEMOVIEW2_H__6CFC1B25_9F7F_4F8C_8660_19349D89DD6D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DemoView2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDemoView2 view

class CDemoView2 : public CView
{
protected:
	CDemoView2();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CDemoView2)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoView2)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CDemoView2();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CDemoView2)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMOVIEW2_H__6CFC1B25_9F7F_4F8C_8660_19349D89DD6D__INCLUDED_)
