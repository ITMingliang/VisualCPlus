#if !defined(AFX_TESTDIALOG_H__C649C94D_B437_4C22_A9CF_F6462CDD3837__INCLUDED_)
#define AFX_TESTDIALOG_H__C649C94D_B437_4C22_A9CF_F6462CDD3837__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TestDialog.h : header file
//

#ifdef TESTDIALOG_EXPORTS
#define TESTDIALOG AFX_EXT_CLASS
#else
#define TESTDIALOG
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestDialog dialog

TESTDIALOG class CTestDialog : public CDialog
{
// Construction
public:
	CTestDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTestDialog)
	enum { IDD = IDD_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTestDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTDIALOG_H__C649C94D_B437_4C22_A9CF_F6462CDD3837__INCLUDED_)
