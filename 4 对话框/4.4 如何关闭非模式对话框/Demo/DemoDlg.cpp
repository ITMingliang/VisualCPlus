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

}

BEGIN_MESSAGE_MAP(CDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CDemoDlg)
	ON_BN_CLICKED(IDC_CLOSE_DLG, OnCloseDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoDlg message handlers

void CDemoDlg::PostNcDestroy() 
{
	//ɾ���Ի������
	delete this;		
}

void CDemoDlg::OnCloseDlg() 
{
	AfxMessageBox(_T("�رշ�ģʽ�Ի���"));

	//���ٶԻ��򴰿�
	DestroyWindow();
}
