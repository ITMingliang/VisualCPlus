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
}

CDemoEdit::~CDemoEdit()
{
}


BEGIN_MESSAGE_MAP(CDemoEdit, CEdit)
	//{{AFX_MSG_MAP(CDemoEdit)
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoEdit message handlers

void CDemoEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	//�ж��ַ��Ƿ�Ϊ����
	if ((nChar < '0') || (nChar > '9'))
	{
		if (nChar != VK_BACK)
		{
			AfxMessageBox(_T("���������֡�"));
			return;
		}
	}

	CEdit::OnChar(nChar, nRepCnt, nFlags);
}
