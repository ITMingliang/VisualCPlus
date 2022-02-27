// DemoDlg.h : header file
//

#if !defined(AFX_DEMODLG_H__D62619E8_769F_4EAB_AA1A_F19E27F03CB7__INCLUDED_)
#define AFX_DEMODLG_H__D62619E8_769F_4EAB_AA1A_F19E27F03CB7__INCLUDED_

#include "TimerThread.h"	// Added by ClassView

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDemoDlg dialog

class CDemoDlg : public CDialog
{
// Construction
public:
	CDemoDlg(CWnd* pParent = NULL);	// standard constructor
	~CDemoDlg();

// Dialog Data
	//{{AFX_DATA(CDemoDlg)
	enum { IDD = IDD_DEMO_DIALOG };
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
	afx_msg LRESULT OnMsgFunc();
	afx_msg void OnTest1();
	afx_msg void OnTest2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	UINT m_nTimerID;
	CTimerThread* m_pTimerThread;
	THREAD_PARAM m_ThreadParam;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMODLG_H__D62619E8_769F_4EAB_AA1A_F19E27F03CB7__INCLUDED_)
