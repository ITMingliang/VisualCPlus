// ConnectSocket.cpp : implementation file
//

#include "stdafx.h"
#include "demo.h"
#include "ConnectSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConnectSocket

CConnectSocket::CConnectSocket(HWND hWnd)
{
	m_hWnd = hWnd;
}

CConnectSocket::~CConnectSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CConnectSocket, CSocket)
	//{{AFX_MSG_MAP(CConnectSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CConnectSocket member functions

void CConnectSocket::OnReceive(int nErrorCode) 
{
	SendMessage(m_hWnd, WM_RECEIVE, 0, 0);

	CSocket::OnReceive(nErrorCode);
}