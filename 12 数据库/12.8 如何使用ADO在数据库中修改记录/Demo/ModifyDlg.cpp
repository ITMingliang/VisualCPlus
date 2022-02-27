// ModifyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "demo.h"
#include "ModifyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CModifyDlg dialog


CModifyDlg::CModifyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CModifyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CModifyDlg)
	m_strName = _T("");
	m_nAge = 0;
	//}}AFX_DATA_INIT
}


void CModifyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CModifyDlg)
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDX_Text(pDX, IDC_AGE, m_nAge);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CModifyDlg, CDialog)
	//{{AFX_MSG_MAP(CModifyDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CModifyDlg message handlers

void CModifyDlg::OnOK() 
{
	//更新数据
	UpdateData(TRUE);
	if (m_strName.IsEmpty())
	{
		AfxMessageBox((_T("姓名不能为空。")));
		return;
	}
	
	CDialog::OnOK();
}
