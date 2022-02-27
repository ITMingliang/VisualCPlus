#if !defined(AFX_DEMOEDIT_H__FC01D023_8297_415C_9AE2_E303A4AF19D9__INCLUDED_)
#define AFX_DEMOEDIT_H__FC01D023_8297_415C_9AE2_E303A4AF19D9__INCLUDED_

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
	virtual ~CDemoEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CDemoEdit)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMOEDIT_H__FC01D023_8297_415C_9AE2_E303A4AF19D9__INCLUDED_)
