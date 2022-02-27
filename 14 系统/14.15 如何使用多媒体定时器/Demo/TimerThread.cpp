// TimerThread.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "TimerThread.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTimerThread

IMPLEMENT_DYNCREATE(CTimerThread, CWinThread)

CTimerThread::CTimerThread()
{
	m_pThreadParam = NULL;
}

CTimerThread::~CTimerThread()
{
}

BOOL CTimerThread::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	return TRUE;
}

int CTimerThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CTimerThread, CWinThread)
	//{{AFX_MSG_MAP(CTimerThread)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTimerThread message handlers

int CTimerThread::Run() 
{	
	while (TRUE)
	{
		//�ȴ���ʱ�¼�
		while (WAIT_TIMEOUT == 
			WaitForSingleObject(m_pThreadParam->hTimerEvent, 200))
		{
			//�ȴ��˳��¼�
			if (WaitForSingleObject(m_pThreadParam->hExitEvent, 0) == WAIT_OBJECT_0)
			{
				::AfxEndThread(0);
			}
		}

		m_pThreadParam->nTime += 100;

		//�����̴߳��ڷ�����Ϣ
		::PostMessage(m_pThreadParam->hWnd, WM_THREADMSG, 0, 0);

		//��λ��ʱ�¼�
		ResetEvent(m_pThreadParam->hTimerEvent);	
	}
}
