// AcceptSocket.cpp : implementation file
//

#include "stdafx.h"
#include "demo.h"
#include "AcceptSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAcceptSocket

CAcceptSocket::CAcceptSocket(HWND hWnd)
{
	m_hWnd = hWnd;
}

CAcceptSocket::~CAcceptSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CAcceptSocket, CSocket)
	//{{AFX_MSG_MAP(CAcceptSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CAcceptSocket member functions

void CAcceptSocket::OnReceive(int nErrorCode) 
{
	SendMessage(m_hWnd, WM_RECEIVE, 0, 0);
	
	CSocket::OnReceive(nErrorCode);
}
