#if !defined(AFX_DEMODLG2_H__9B0E2168_FB71_4670_9C20_148869628C1E__INCLUDED_)
#define AFX_DEMODLG2_H__9B0E2168_FB71_4670_9C20_148869628C1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DemoDlg2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDemoDlg2 dialog

class CDemoDlg2 : public CDialog
{
// Construction
public:
	CDemoDlg2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDemoDlg2)
	enum { IDD = IDD_DEMO2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoDlg2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDemoDlg2)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMODLG2_H__9B0E2168_FB71_4670_9C20_148869628C1E__INCLUDED_)
