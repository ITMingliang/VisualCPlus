// DemoDlg.h : header file
//

#if !defined(AFX_DEMODLG_H__D6C7F612_DBA0_40C4_AB8B_61CA8E65CB8C__INCLUDED_)
#define AFX_DEMODLG_H__D6C7F612_DBA0_40C4_AB8B_61CA8E65CB8C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CListenSocket;
/////////////////////////////////////////////////////////////////////////////
// CDemoDlg dialog

class CDemoDlg : public CDialog
{
// Construction
public:
	CListenSocket* m_pListenSocket;

	CDemoDlg(CWnd* pParent = NULL);	// standard constructor
	~CDemoDlg();

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
	afx_msg void OnListen();
	afx_msg void OnSend();
	//}}AFX_MSG
	afx_msg LRESULT OnReceive();
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMODLG_H__D6C7F612_DBA0_40C4_AB8B_61CA8E65CB8C__INCLUDED_)
