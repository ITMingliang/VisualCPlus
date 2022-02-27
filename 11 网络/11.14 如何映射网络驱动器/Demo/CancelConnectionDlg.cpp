// CancelConnectionDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "CancelConnectionDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCancelConnectionDlg dialog


CCancelConnectionDlg::CCancelConnectionDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCancelConnectionDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCancelConnectionDlg)
	m_strLocalName = _T("");
	//}}AFX_DATA_INIT
}


void CCancelConnectionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCancelConnectionDlg)
	DDX_Text(pDX, IDC_LOCALNAME, m_strLocalName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCancelConnectionDlg, CDialog)
	//{{AFX_MSG_MAP(CCancelConnectionDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCancelConnectionDlg message handlers
