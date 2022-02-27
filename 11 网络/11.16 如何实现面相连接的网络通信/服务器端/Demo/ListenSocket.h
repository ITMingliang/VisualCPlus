#if !defined(AFX_LISTENSOCKET_H__CA85DA85_8828_4999_AFBE_796C2FC7E4A4__INCLUDED_)
#define AFX_LISTENSOCKET_H__CA85DA85_8828_4999_AFBE_796C2FC7E4A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ListenSocket.h : header file
//


class CAcceptSocket;
/////////////////////////////////////////////////////////////////////////////
// CListenSocket command target

class CListenSocket : public CSocket
{
// Attributes
public:

// Operations
public:
	CListenSocket(HWND hWnd);
	virtual ~CListenSocket();

// Overrides
public:
	HWND m_hWnd;
	CAcceptSocket* m_pAcceptSocket;
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListenSocket)
	public:
	virtual void OnAccept(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CListenSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTENSOCKET_H__CA85DA85_8828_4999_AFBE_796C2FC7E4A4__INCLUDED_)
