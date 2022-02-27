#if !defined(AFX_ACCEPTSOCKET_H__B9F17E0C_236C_4048_8C4C_F8E75F206462__INCLUDED_)
#define AFX_ACCEPTSOCKET_H__B9F17E0C_236C_4048_8C4C_F8E75F206462__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AcceptSocket.h : header file
//

#define WM_RECEIVE WM_USER+1

/////////////////////////////////////////////////////////////////////////////
// CAcceptSocket command target

class CAcceptSocket : public CSocket
{
// Attributes
public:

// Operations
public:
	CAcceptSocket(HWND hWnd);
	virtual ~CAcceptSocket();

// Overrides
public:
	HWND m_hWnd;
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAcceptSocket)
	public:
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CAcceptSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACCEPTSOCKET_H__B9F17E0C_236C_4048_8C4C_F8E75F206462__INCLUDED_)
