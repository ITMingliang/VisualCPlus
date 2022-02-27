// AddConnectionDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "AddConnectionDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddConnectionDlg dialog


CAddConnectionDlg::CAddConnectionDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddConnectionDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddConnectionDlg)
	m_strRemoteName = _T("");
	m_strLocalName = _T("");
	m_strUserName = _T("");
	m_strPassword = _T("");
	//}}AFX_DATA_INIT
}


void CAddConnectionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddConnectionDlg)
	DDX_Text(pDX, IDC_REMOTENAME, m_strRemoteName);
	DDX_Text(pDX, IDC_LOCALNAME, m_strLocalName);
	DDX_Text(pDX, IDC_USERNAME, m_strUserName);
	DDX_Text(pDX, IDC_PASSWORD, m_strPassword);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddConnectionDlg, CDialog)
	//{{AFX_MSG_MAP(CAddConnectionDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddConnectionDlg message handlers
