// ProgressStatusBar.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "ProgressStatusBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProgressStatusBar

CProgressStatusBar::CProgressStatusBar()
{
}

CProgressStatusBar::~CProgressStatusBar()
{
}


BEGIN_MESSAGE_MAP(CProgressStatusBar, CStatusBar)
	//{{AFX_MSG_MAP(CProgressStatusBar)
	ON_WM_CREATE()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProgressStatusBar message handlers

int CProgressStatusBar::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CStatusBar::OnCreate(lpCreateStruct) == -1)
		return -1;

	//创建进度条
	m_Progress.Create(WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), 
		this, 1);

	return 0;
}

void CProgressStatusBar::OnSize(UINT nType, int cx, int cy) 
{
	CStatusBar::OnSize(nType, cx, cy);

	//获得指示器大小和位置
	CRect rect;
	GetItemRect(0, &rect);

	//移动进度条窗口
	m_Progress.MoveWindow(rect.left + 1, rect.top, rect.Width() - 2, rect.Height());
}
