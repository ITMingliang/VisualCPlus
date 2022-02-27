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
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoDlg dialog

CDemoDlg::CDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDemoDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	if (!SUCCEEDED(m_pConnection.CreateInstance(__uuidof(Connection))))
	{
		m_pConnection = NULL;
		TRACE(_T("Database CreateInstance failed"));
	}

	if (!SUCCEEDED(m_pRecordset.CreateInstance(__uuidof(Recordset))))
	{
		m_pRecordset = NULL;
		TRACE(_T("Recordset CreateInstance failed"));
	}

	//�����ݿ�
	CString strConnect = _T("Provider=Microsoft.Jet.OLEDB.4.0;Data Source= Demo.mdb");
	if (!OpenDatabase(strConnect))
	{
		AfxMessageBox(_T("���ݿ��ʧ�ܡ�"));
		return;
	}

	//�򿪼�¼��
	CString strSource = _T("SELECT * FROM DemoTable");
	if (!OpenRecordset(strSource))
	{
		AfxMessageBox(_T("��¼����ʧ�ܡ�"));
		return;
	}
}

CDemoDlg::~CDemoDlg()
{
	m_pRecordset->Close();
	m_pConnection->Close();
}

void CDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDemoDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_MOVEFIRST, OnMoveFirst)
	ON_BN_CLICKED(IDC_MOVELAST, OnMoveLast)
	ON_BN_CLICKED(IDC_MOVEPREVIOUS, OnMovePrevious)
	ON_BN_CLICKED(IDC_MOVENEXT, OnMoveNext)
	ON_BN_CLICKED(IDC_MOVE, OnMove)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoDlg message handlers

BOOL CDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	SetDlgItemInt(IDC_NUM, 0);
	
	return TRUE;
}

void CDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDemoDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BOOL CDemoDlg::OpenDatabase(LPCTSTR lpszConnect, long nOptions)
{
	ASSERT(m_pConnection != NULL);
	ASSERT(lpszConnect != NULL);
	ASSERT(AfxIsValidString(lpszConnect));
	
	//�����ݿ�����
	try
	{
		return SUCCEEDED(m_pConnection->Open(_bstr_t(lpszConnect), 
			_T(""), _T(""), nOptions));
	}
	catch (_com_error& e)
	{
		TRACE(_T("%s\n"), e.ErrorMessage());
		return FALSE;
	}
}

BOOL CDemoDlg::CloseDatabase()
{
	ASSERT(m_pConnection != NULL);

	//�ر����ݿ�����
	try
	{
		if (m_pConnection->State & adStateOpen) 
		{
			return SUCCEEDED(m_pConnection->Close());
		}
		else
		{
			return TRUE;
		}
	}
	catch (_com_error& e)
	{
		TRACE(_T("%s\n"), e.ErrorMessage());
		return FALSE;
	} 
}

BOOL CDemoDlg::OpenRecordset(LPCTSTR lpszSource, long nCursorType, long nLockType, long nOptions)
{
	ASSERT(m_pConnection != NULL);
	ASSERT(m_pRecordset != NULL);
	ASSERT(lpszSource != NULL);
	ASSERT(AfxIsValidString(lpszSource));

	//�򿪼�¼��
	try
	{
		return (SUCCEEDED(m_pRecordset->Open(_variant_t(lpszSource),
										m_pConnection.GetInterfacePtr(),
										(CursorTypeEnum)nCursorType, 
										(LockTypeEnum)nLockType,
										nOptions)));
	}
	catch(_com_error e)
	{
		TRACE(_T("%s\n"), e.ErrorMessage());
		return FALSE;
	}
}

BOOL CDemoDlg::CloseRecorset()
{
	ASSERT(m_pRecordset != NULL);

	//�رռ�¼��
	try
	{
		if (m_pRecordset->State & adStateOpen) 
		{
			return SUCCEEDED(m_pRecordset->Close());
		}
		else
		{
			return TRUE;
		}
	}
	catch (_com_error e)
	{
		TRACE(_T("%s\n"), e.ErrorMessage());
		return FALSE;
	}
}

void CDemoDlg::OnMoveFirst() 
{
	if (!(m_pRecordset->State & adStateOpen))
	{
		AfxMessageBox((_T("��¼��δ�򿪡�")));
		return;
	}

 	//�жϼ�¼���Ƿ�Ϊ��
 	if (m_pRecordset->BOF && m_pRecordset->adoEOF)
 	{
 		return;
 	}
 
	//�ƶ���¼��
	try
	{
		m_pRecordset->MoveFirst();
	}
	catch(_com_error e)
	{
		TRACE(_T("%s\n"), e.ErrorMessage());
		return;
	}
		
 	//��ȡ��¼��
	_variant_t varValue;
	CString strName = _T("");
	int nAge = 0;
	try
	{
 		varValue = m_pRecordset->GetCollect(_variant_t(_T("NAME")));
 		if (varValue.vt != VT_NULL)
 		{
 			strName = varValue.bstrVal;
 		}
 		else
 		{
 			strName = _T("");
 		}
 
 		varValue = m_pRecordset->GetCollect(_variant_t(_T("AGE")));
 		if (varValue.vt != VT_NULL)
 		{
 			nAge = varValue.intVal;
 		}
 		else
 		{
 			nAge = 0;
 		}
	}
	catch(_com_error e)
	{
		TRACE(_T("%s\n"), e.ErrorMessage());
		return;
	}
 
 	//ˢ��
	SetDlgItemText(IDC_NAME, strName);
	SetDlgItemInt(IDC_AGE, nAge);
}

void CDemoDlg::OnMoveLast() 
{
	if (!(m_pRecordset->State & adStateOpen))
	{
		AfxMessageBox((_T("��¼��δ�򿪡�")));
		return;
	}

 	//�жϼ�¼���Ƿ�Ϊ��
 	if (m_pRecordset->BOF && m_pRecordset->adoEOF)
 	{
 		return;
 	}
 
	//�ƶ���¼��
	try
	{
		m_pRecordset->MoveLast();
	}
	catch(_com_error e)
	{
		TRACE(_T("%s\n"), e.ErrorMessage());
		return;
	}
	
 	//��ȡ��¼��
	_variant_t varValue;
	CString strName = _T("");
	int nAge = 0;
	try
	{
 		varValue = m_pRecordset->GetCollect(_variant_t(_T("NAME")));
 		if (varValue.vt != VT_NULL)
 		{
 			strName = varValue.bstrVal;
 		}
 		else
 		{
 			strName = _T("");
 		}
 
 		varValue = m_pRecordset->GetCollect(_variant_t(_T("AGE")));
 		if (varValue.vt != VT_NULL)
 		{
 			nAge = varValue.intVal;
 		}
 		else
 		{
 			nAge = 0;
 		}
	}
	catch(_com_error e)
	{
		TRACE(_T("%s\n"), e.ErrorMessage());
		return;
	}

  	//ˢ��
	SetDlgItemText(IDC_NAME, strName);
	SetDlgItemInt(IDC_AGE, nAge);
}

void CDemoDlg::OnMovePrevious() 
{
	if (!(m_pRecordset->State & adStateOpen))
	{
		AfxMessageBox((_T("��¼��δ�򿪡�")));
		return;
	}
	
	//�жϼ�¼���Ƿ�Ϊ��
 	if (m_pRecordset->BOF && m_pRecordset->adoEOF)
 	{
 		return;
 	}

	//�ƶ���¼��
	try
	{
		m_pRecordset->MovePrevious();

		if (m_pRecordset->BOF)
 		{
			m_pRecordset->MoveLast();
		}
	}
	catch(_com_error e)
	{
		TRACE(_T("%s\n"), e.ErrorMessage());
		return;
	}

 	//��ȡ��¼��
	_variant_t varValue;
	CString strName = _T("");
	int nAge = 0;
	try
	{
 		varValue = m_pRecordset->GetCollect(_variant_t(_T("NAME")));
 		if (varValue.vt != VT_NULL)
 		{
 			strName = varValue.bstrVal;
 		}
 		else
 		{
 			strName = _T("");
 		}
 
 		varValue = m_pRecordset->GetCollect(_variant_t(_T("AGE")));
 		if (varValue.vt != VT_NULL)
 		{
 			nAge = varValue.intVal;
 		}
 		else
 		{
 			nAge = 0;
 		}
	}
	catch(_com_error e)
	{
		TRACE(_T("%s\n"), e.ErrorMessage());
		return;
	}
 
  	//ˢ��
	SetDlgItemText(IDC_NAME, strName);
	SetDlgItemInt(IDC_AGE, nAge);
}

void CDemoDlg::OnMoveNext()
{
	if (!(m_pRecordset->State & adStateOpen))
	{
		AfxMessageBox((_T("��¼��δ�򿪡�")));
		return;
	}

 	//�жϼ�¼���Ƿ�Ϊ��
 	if (m_pRecordset->BOF && m_pRecordset->adoEOF)
 	{
 		return;
 	}

	//�ƶ���¼��
	try
	{
		m_pRecordset->MoveNext();

		if (m_pRecordset->adoEOF)
		{
			m_pRecordset->MoveFirst();
		}
	}
	catch(_com_error e)
	{
		TRACE(_T("%s\n"), e.ErrorMessage());
		return;
	}

 	//��ȡ��¼��
	_variant_t varValue;
	CString strName = _T("");
	int nAge = 0;
	try
	{
 		varValue = m_pRecordset->GetCollect(_variant_t(_T("NAME")));
 		if (varValue.vt != VT_NULL)
 		{
 			strName = varValue.bstrVal;
 		}
 		else
 		{
 			strName = _T("");
 		}
 
 		varValue = m_pRecordset->GetCollect(_variant_t(_T("AGE")));
 		if (varValue.vt != VT_NULL)
 		{
 			nAge = varValue.intVal;
 		}
 		else
 		{
 			nAge = 0;
 		}
	}
	catch(_com_error e)
	{
		TRACE(_T("%s\n"), e.ErrorMessage());
		return;
	}
 
  	//ˢ��
	SetDlgItemText(IDC_NAME, strName);
	SetDlgItemInt(IDC_AGE, nAge);
}

void CDemoDlg::OnMove() 
{
	if (!(m_pRecordset->State & adStateOpen))
	{
		AfxMessageBox((_T("��¼��δ�򿪡�")));
		return;
	}

	//�жϼ�¼���Ƿ�Ϊ��
 	if (m_pRecordset->BOF && m_pRecordset->adoEOF)
 	{
 		return;
 	}

	//�ƶ���¼��
	int nNum = GetDlgItemInt(IDC_NUM);
	try
	{
		m_pRecordset->Move(nNum);
	}
	catch(_com_error e)
	{
		TRACE(_T("%s\n"), e.ErrorMessage());
		return;
	}
	
	if (m_pRecordset->BOF || m_pRecordset->adoEOF)
 	{
 		return;
 	}

 	//��ȡ��¼��
	_variant_t varValue;
	CString strName = _T("");
	int nAge = 0;
	try
	{
 		varValue = m_pRecordset->GetCollect(_variant_t(_T("NAME")));
 		if (varValue.vt != VT_NULL)
 		{
 			strName = varValue.bstrVal;
 		}
 		else
 		{
 			strName = _T("");
 		}
 
 		varValue = m_pRecordset->GetCollect(_variant_t(_T("AGE")));
 		if (varValue.vt != VT_NULL)
 		{
 			nAge = varValue.intVal;
 		}
 		else
 		{
 			nAge = 0;
 		}
	}
	catch(_com_error e)
	{
		TRACE(_T("%s\n"), e.ErrorMessage());
		return;
	}
 
  	//ˢ��
	SetDlgItemText(IDC_NAME, strName);
	SetDlgItemInt(IDC_AGE, nAge);
}
