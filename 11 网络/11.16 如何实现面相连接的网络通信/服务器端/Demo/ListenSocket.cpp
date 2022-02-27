// ListenSocket.cpp : implementation file
//

#include "stdafx.h"
#include "demo.h"
#include "ListenSocket.h"
#include "AcceptSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListenSocket

CListenSocket::CListenSocket(HWND hWnd)
{
	m_hWnd = hWnd;

	m_pAcceptSocket = NULL;
}

CListenSocket::~CListenSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CListenSocket, CSocket)
	//{{AFX_MSG_MAP(CListenSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CListenSocket member functions

void CListenSocket::OnAccept(int nErrorCode) 
{
	CAcceptSocket* pAcceptSocket = new CAcceptSocket(m_hWnd);

	//接受连接
	if (Accept(*pAcceptSocket))
	{
		if (m_pAcceptSocket != NULL)
		{
			delete m_pAcceptSocket;
			m_pAcceptSocket = NULL;
		}
		m_pAcceptSocket = pAcceptSocket;
	}

	CSocket::OnAccept(nErrorCode);
}