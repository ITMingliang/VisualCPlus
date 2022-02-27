// DemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "DemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoDlg dialog

CDemoDlg::CDemoDlg()
{
	m_nEdit = 0;
}

void CDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDemoDlg)
	DDX_Text(pDX, IDC_EDIT, m_nEdit);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CDemoDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoDlg message handlers


void CDemoDlg::OnOK() 
{
	//获得并检验对话框数据
	if (!UpdateData(TRUE))
	{
		return;
	}

	if (m_nEdit <= 1)
	{
		AfxMessageBox(_T("请输入一个大于1的数。"));
		return;
	}

	AfxMessageBox(_T("IDOK"));

	//销毁对话框窗口
	DestroyWindow();
}

void CDemoDlg::OnCancel() 
{
	AfxMessageBox(_T("IDCANCEL"));

	//销毁对话框窗口
	DestroyWindow();
}

void CDemoDlg::PostNcDestroy() 
{
	//删除对话框对象
	delete this;
}
