// DatagramSocket.cpp : implementation file
//

#include "stdafx.h"
#include "demo.h"
#include "DatagramSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDatagramSocket

CDatagramSocket::CDatagramSocket(HWND hWnd)
{
	m_hWnd = hWnd;
}

CDatagramSocket::~CDatagramSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CDatagramSocket, CSocket)
	//{{AFX_MSG_MAP(CDatagramSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CDatagramSocket member functions

void CDatagramSocket::OnReceive(int nErrorCode) 
{
	SendMessage(m_hWnd, WM_RECEIVE, 0, 0);
	
	CSocket::OnReceive(nErrorCode);
}
