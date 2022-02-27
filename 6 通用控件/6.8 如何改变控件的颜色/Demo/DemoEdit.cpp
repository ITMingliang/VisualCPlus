// DemoEdit.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "DemoEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoEdit

CDemoEdit::CDemoEdit()
{
	//创建画刷
	m_hBrush = CreateSolidBrush(RGB(0x99, 0xCC, 0xFF));
}

CDemoEdit::~CDemoEdit()
{
}


BEGIN_MESSAGE_MAP(CDemoEdit, CEdit)
	//{{AFX_MSG_MAP(CDemoEdit)
	ON_WM_CTLCOLOR_REFLECT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
// CDemoEdit message handlers

HBRUSH CDemoEdit::CtlColor(CDC* pDC, UINT nCtlColor) 
{
	//设置文本前景色和背景色
	pDC->SetTextColor(RGB(0xFF, 0x00, 0x00));
	pDC->SetBkColor(RGB(0x99, 0xCC, 0xFF));

	return m_hBrush;
}
														