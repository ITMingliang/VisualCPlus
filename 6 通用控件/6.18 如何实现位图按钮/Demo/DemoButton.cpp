// DemoButton.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "DemoButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoButton

CDemoButton::CDemoButton()
{
}

CDemoButton::~CDemoButton()
{
}


BEGIN_MESSAGE_MAP(CDemoButton, CButton)
	//{{AFX_MSG_MAP(CDemoButton)
	ON_WM_MOUSEMOVE()
	ON_MESSAGE(WM_MOUSELEAVE,OnMouseLeave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoButton message handlers

void CDemoButton::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	static int n = 0;
	n++;
	TRACE("OnMouseMove%d\n",n);
	CButton::OnMouseMove(nFlags, point);
}

void CDemoButton::OnMouseLeave() 
{
	TRACE("OnMouseLeave\n");
}