#if !defined(AFX_DEMODLG_H__BBD46CAF_382E_4822_8EFF_BDE792679589__INCLUDED_)
#define AFX_DEMODLG_H__BBD46CAF_382E_4822_8EFF_BDE792679589__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DemoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDemoDlg dialog

class CDemoDlg : public CDialog
{
// Construction
public:
	int m_nEdit;
	CDemoDlg();   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDemoDlg)
	
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoDlg)
	protected:
	virtual void PostNcDestroy();
	virtual void OnOK();
	virtual void OnCancel();
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDemoDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMODLG_H__BBD46CAF_382E_4822_8EFF_BDE792679589__INCLUDED_)
