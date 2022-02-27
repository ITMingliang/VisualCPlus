#if !defined(AFX_CONNECTSOCKET_H__28271647_88A3_42EF_8B5E_2DBDC9F3BEF0__INCLUDED_)
#define AFX_CONNECTSOCKET_H__28271647_88A3_42EF_8B5E_2DBDC9F3BEF0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ConnectSocket.h : header file
//

#define WM_RECEIVE WM_USER+1

/////////////////////////////////////////////////////////////////////////////
// CConnectSocket command target

class CConnectSocket : public CSocket
{
// Attributes
public:

// Operations
public:
	CConnectSocket(HWND hWnd);
	virtual ~CConnectSocket();

// Overrides
public:
	HWND m_hWnd;
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConnectSocket)
	public:
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CConnectSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONNECTSOCKET_H__28271647_88A3_42EF_8B5E_2DBDC9F3BEF0__INCLUDED_)
