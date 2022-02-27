// DemoDlg.h : header file
//

#if !defined(AFX_DEMODLG_H__FE3ED234_EF5C_4C9B_82AE_A76334EB9DF0__INCLUDED_)
#define AFX_DEMODLG_H__FE3ED234_EF5C_4C9B_82AE_A76334EB9DF0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct THREAD_PARAM 
{
	HWND hWnd;
	int nData;
}_THREAD_PARAM;

UINT ThreadProc(LPVOID pParam);
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
	CWinThread* m_pThread;
	THREAD_PARAM m_ThreadParam;
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT OnMsgFunc();
	afx_msg void OnBeginThread();
	afx_msg void OnSuspendThread();
	afx_msg void OnResumeThread();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMODLG_H__FE3ED234_EF5C_4C9B_82AE_A76334EB9DF0__INCLUDED_)
