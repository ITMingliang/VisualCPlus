#if !defined(AFX_DEMOTOOLBAR_H__C65DB9AF_48AA_4046_AF3C_02DC8252A10A__INCLUDED_)
#define AFX_DEMOTOOLBAR_H__C65DB9AF_48AA_4046_AF3C_02DC8252A10A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DemoToolBar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDemoToolBar window

class CDemoToolBar : public CToolBar
{
// Construction
public:
	CDemoToolBar();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoToolBar)
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL CreateComboBox(UINT nID, int nWidth);
	virtual ~CDemoToolBar();

	// Generated message map functions
protected:
	//{{AFX_MSG(CDemoToolBar)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMOTOOLBAR_H__C65DB9AF_48AA_4046_AF3C_02DC8252A10A__INCLUDED_)
