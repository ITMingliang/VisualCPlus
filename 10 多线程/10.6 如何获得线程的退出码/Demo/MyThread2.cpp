// MyThread2.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "MyThread2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyThread2

IMPLEMENT_DYNCREATE(CMyThread2, CWinThread)

CMyThread2::CMyThread2()
{
}

CMyThread2::~CMyThread2()
{
}

BOOL CMyThread2::InitInstance()
{
	//退出线程，退出码2000。
	AfxEndThread(2000);

	return TRUE;
}

int CMyThread2::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CMyThread2, CWinThread)
	//{{AFX_MSG_MAP(CMyThread2)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyThread2 message handlers
