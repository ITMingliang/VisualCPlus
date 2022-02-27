// DemoToolBar.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "DemoToolBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoToolBar

CDemoToolBar::CDemoToolBar()
{
}

CDemoToolBar::~CDemoToolBar()
{
}

BEGIN_MESSAGE_MAP(CDemoToolBar, CToolBar)
	//{{AFX_MSG_MAP(CDemoToolBar)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoToolBar message handlers

BOOL CDemoToolBar::CreateComboBox(CComboBox* pComboBox, UINT nID, int nWidth)
{
	ASSERT(pComboBox != nWidth);

	int nIndex = 0;
	CRect rect;

	//找到指定的工具
	while(GetItemID(nIndex) != nID)
	{
		nIndex;
	}

    //设置指定工具的宽度并获取新的区域
    SetButtonInfo(nIndex, nID, TBBS_SEPARATOR, nWidth);
    GetItemRect(nIndex, &rect);

    //设置位置
	rect.top+=2;
	rect.bottom += 200;

    // 创建ComboBox
	if (!pComboBox->Create(WS_CHILD | WS_VISIBLE | CBS_AUTOHSCROLL | 
		CBS_DROPDOWNLIST | CBS_HASSTRINGS, rect, this, nID))
    {
       TRACE0("Failed to create combo-box\n");
       return FALSE;
    }

	//显示ComboBox
    pComboBox->ShowWindow(SW_SHOW);
	
	return TRUE;
}
