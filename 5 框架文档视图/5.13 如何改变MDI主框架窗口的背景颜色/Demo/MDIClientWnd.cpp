// MDIClientWnd.cpp: implementation of the CMDIClientWnd class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Demo.h"
#include "MDIClientWnd.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNAMIC(CMDIClientWnd, CWnd)

BEGIN_MESSAGE_MAP(CMDIClientWnd, CWnd)
	//{{AFX_MSG_MAP(CWnd)
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMDIClientWnd::CMDIClientWnd()
{
	//������ˢ
	m_Brush.CreateSolidBrush(RGB(0x99, 0xCC, 0xFF));
}

CMDIClientWnd::~CMDIClientWnd()
{
}

BOOL CMDIClientWnd::OnEraseBkgnd(CDC* pDC) 
{
	//��ÿͻ�����С
	CRect rect;
	GetClientRect(rect);				

	//��䱳��
	pDC->FillRect(rect, &m_Brush);

	return TRUE;
}
