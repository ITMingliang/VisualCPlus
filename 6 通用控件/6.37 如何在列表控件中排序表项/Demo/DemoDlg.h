// DemoDlg.h : header file
//

#if !defined(AFX_DEMODLG_H__047543EC_0F6E_4C44_8425_D45BD3EAA852__INCLUDED_)
#define AFX_DEMODLG_H__047543EC_0F6E_4C44_8425_D45BD3EAA852__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

int CALLBACK CompareFunc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort);

/////////////////////////////////////////////////////////////////////////////
// CDemoDlg dialog

class CDemoDlg : public CDialog
{
// Construction
public:
	void InitList();
	CDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDemoDlg)
	enum { IDD = IDD_DEMO_DIALOG };
	CListCtrl	m_ctrlList;
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
	afx_msg void OnColumnclickList(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMODLG_H__047543EC_0F6E_4C44_8425_D45BD3EAA852__INCLUDED_)
