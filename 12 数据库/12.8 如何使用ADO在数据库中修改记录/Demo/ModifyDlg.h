#if !defined(AFX_MODIFYDLG_H__FCFC7D6B_51A9_415D_98BF_A700D49436BB__INCLUDED_)
#define AFX_MODIFYDLG_H__FCFC7D6B_51A9_415D_98BF_A700D49436BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ModifyDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CModifyDlg dialog

class CModifyDlg : public CDialog
{
// Construction
public:
	CModifyDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CModifyDlg)
	enum { IDD = IDD_SET };
	CString	m_strName;
	int		m_nAge;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CModifyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CModifyDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODIFYDLG_H__FCFC7D6B_51A9_415D_98BF_A700D49436BB__INCLUDED_)
