// DemoDlg.h : header file
//

#if !defined(AFX_DEMODLG_H__0E064245_49ED_46F9_90F3_3B9318881304__INCLUDED_)
#define AFX_DEMODLG_H__0E064245_49ED_46F9_90F3_3B9318881304__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MyThread1.h"
#include "MyThread2.h"
/////////////////////////////////////////////////////////////////////////////
// CDemoDlg dialog

class CDemoDlg : public CDialog
{
// Construction
public:
	CMyThread1* m_pThread1;
	HANDLE m_hThread2;

	CDemoDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CDemoDlg();

// Dialog Data
	//{{AFX_DATA(CDemoDlg)
	enum { IDD = IDD_DEMO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBeginThread1();
	afx_msg void OnBeginThread2();
	afx_msg void OnGetExitCodeThread1();
	afx_msg void OnGetExitCodeThread2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMODLG_H__0E064245_49ED_46F9_90F3_3B9318881304__INCLUDED_)
