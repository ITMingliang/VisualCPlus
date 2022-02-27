// DemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "demo.h"
#include "DemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoDlg dialog


CDemoDlg::CDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDemoDlg)
	m_nEdit = 0;
	//}}AFX_DATA_INIT
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
	//��ò�����Ի�������
	if (!UpdateData(TRUE))
	{
		return;
	}

	if (m_nEdit <= 1)
	{
		AfxMessageBox(_T("������һ������1������"));
		return;
	}
	
	AfxMessageBox(_T("IDOK"));

	//�رնԻ���
	EndDialog(IDOK);
}

void CDemoDlg::OnCancel() 
{
	AfxMessageBox(_T("IDCANCEL"));

	//�رնԻ���
	EndDialog(IDCANCEL);	
}
