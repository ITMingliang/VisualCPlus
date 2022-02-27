#if !defined(AFX_MYTHREAD1_H__54D6EAA3_FB00_4C03_A783_A6C048BF83EB__INCLUDED_)
#define AFX_MYTHREAD1_H__54D6EAA3_FB00_4C03_A783_A6C048BF83EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyThread1.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CMyThread1 thread

class CMyThread1 : public CWinThread
{
	DECLARE_DYNCREATE(CMyThread1)
public:
	CMyThread1();           // protected constructor used by dynamic creation
	virtual ~CMyThread1();
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyThread1)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	// Generated message map functions
	//{{AFX_MSG(CMyThread1)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYTHREAD1_H__54D6EAA3_FB00_4C03_A783_A6C048BF83EB__INCLUDED_)
