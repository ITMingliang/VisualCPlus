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
	//���ַ�ת��Ϊ��д�ַ�
	if (!IsCharUpper((TCHAR)nChar))
	{	
		nChar = (UINT)CharUpper((TCHAR*)nChar);
	}

//	//���ַ�ת��ΪСд�ַ�
// 	if (!IsCharLower((TCHAR)nChar))
// 	{
// 		nChar = (UINT)CharLower((TCHAR*)nChar);
// 	}

	//������Ϣ
	DefWindowProc(WM_CHAR, nChar, MAKELPARAM(nRepCnt, nFlags));
}
