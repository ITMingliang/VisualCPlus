// MyThread1.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "MyThread1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyThread1

IMPLEMENT_DYNCREATE(CMyThread1, CWinThread)

CMyThread1::CMyThread1()
{
}

CMyThread1::~CMyThread1()
{
}

BOOL CMyThread1::InitInstance()
{
	//退出线程，退出码1000。
	AfxEndThread(1000);

	return TRUE;
}

int CMyThread1::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CMyThread1, CWinThread)
	//{{AFX_MSG_MAP(CMyThread1)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyThread1 message handlers
