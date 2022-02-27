// DemoDlg2.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "DemoDlg2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoDlg2 dialog


CDemoDlg2::CDemoDlg2(CWnd* pParent /*=NULL*/)
	: CDialog(CDemoDlg2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDemoDlg2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDemoDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDemoDlg2)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDemoDlg2, CDialog)
	//{{AFX_MSG_MAP(CDemoDlg2)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoDlg2 message handlers

void CDemoDlg2::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CDialog::OnLButtonDown(nFlags, point);  
	
	//·¢ËÍWM_NCLBUTTONDOWNÏûÏ¢
	PostMessage(WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(point.x, point.y));
}
