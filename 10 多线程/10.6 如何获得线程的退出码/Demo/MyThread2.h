#if !defined(AFX_MYTHREAD2_H__13A24ED6_A63A_474A_A574_66271C1B9357__INCLUDED_)
#define AFX_MYTHREAD2_H__13A24ED6_A63A_474A_A574_66271C1B9357__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyThread2.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CMyThread2 thread

class CMyThread2 : public CWinThread
{
	DECLARE_DYNCREATE(CMyThread2)
protected:
	CMyThread2();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyThread2)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMyThread2();

	// Generated message map functions
	//{{AFX_MSG(CMyThread2)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYTHREAD2_H__13A24ED6_A63A_474A_A574_66271C1B9357__INCLUDED_)
