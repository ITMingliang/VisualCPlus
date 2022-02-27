#if !defined(AFX_DEMOEDIT_H__2F56DDB2_BAAF_4D8A_9AF1_D02CC2537750__INCLUDED_)
#define AFX_DEMOEDIT_H__2F56DDB2_BAAF_4D8A_9AF1_D02CC2537750__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DemoEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDemoEdit window

class CDemoEdit : public CEdit
{
// Construction
public:
	CDemoEdit();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoEdit)
	//}}AFX_VIRTUAL

// Implementation
public:
	HBRUSH m_hBrush;
	virtual ~CDemoEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CDemoEdit)
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMOEDIT_H__2F56DDB2_BAAF_4D8A_9AF1_D02CC2537750__INCLUDED_)
