#if !defined(AFX_DEMOBUTTON_H__FD8E0B98_B774_49F9_BBC3_0EA3B53F4D2C__INCLUDED_)
#define AFX_DEMOBUTTON_H__FD8E0B98_B774_49F9_BBC3_0EA3B53F4D2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DemoButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDemoButton window

class CDemoButton : public CButton
{
// Construction
public:
	CDemoButton();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoButton)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDemoButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CDemoButton)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMOBUTTON_H__FD8E0B98_B774_49F9_BBC3_0EA3B53F4D2C__INCLUDED_)
