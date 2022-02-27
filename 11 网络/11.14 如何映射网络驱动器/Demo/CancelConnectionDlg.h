#if !defined(AFX_CANCELCONNECTIONDLG_H__77145816_BC54_4D4C_A721_0931675D42EB__INCLUDED_)
#define AFX_CANCELCONNECTIONDLG_H__77145816_BC54_4D4C_A721_0931675D42EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CancelConnectionDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCancelConnectionDlg dialog

class CCancelConnectionDlg : public CDialog
{
// Construction
public:
	CCancelConnectionDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCancelConnectionDlg)
	enum { IDD = IDD_CANCEL_CONNECTION };
	CString	m_strLocalName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCancelConnectionDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCancelConnectionDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CANCELCONNECTIONDLG_H__77145816_BC54_4D4C_A721_0931675D42EB__INCLUDED_)
