#if !defined(AFX_DEMOVIEW1_H__C74A906A_CC7A_4615_9104_B69078484EF9__INCLUDED_)
#define AFX_DEMOVIEW1_H__C74A906A_CC7A_4615_9104_B69078484EF9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DemoView1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDemoView1 view

class CDemoView1 : public CView
{
public:
	CDemoView1();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CDemoView1)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoView1)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CDemoView1();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CDemoView1)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMOVIEW1_H__C74A906A_CC7A_4615_9104_B69078484EF9__INCLUDED_)
