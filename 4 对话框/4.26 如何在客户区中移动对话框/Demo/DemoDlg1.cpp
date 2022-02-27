// DemoDlg1.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "DemoDlg1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoDlg1 dialog


CDemoDlg1::CDemoDlg1(CWnd* pParent /*=NULL*/)
	: CDialog(CDemoDlg1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDemoDlg1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDemoDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDemoDlg1)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDemoDlg1, CDialog)
	//{{AFX_MSG_MAP(CDemoDlg1)
	ON_WM_NCHITTEST()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoDlg1 message handlers

UINT CDemoDlg1::OnNcHitTest(CPoint point) 
{
	UINT nValue = CDialog::OnNcHitTest(point);

	//·µ»ØHTCAPTION
	if (nValue == HTCLIENT)
	{
		nValue = HTCAPTION;
	}

	return nValue;
}
