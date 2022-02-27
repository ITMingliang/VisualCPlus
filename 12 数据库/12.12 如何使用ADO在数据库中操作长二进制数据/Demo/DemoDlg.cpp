// DemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Demo.h"
#include "DemoDlg.h"
#include "FolderDialog.h"
#include <afxdlgs.h>

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
		TRACE(_T("Recordset CreateInstance Failed!"));
	}

	//打开数据库
	CString strConnect = _T("Provider=Microsoft.Jet.OLEDB.4.0;Data Source= Demo.mdb");
	if (!OpenDatabase(strConnect))
	{
		AfxMessageBox(_T("数据库打开失败。"));
		return;
	}

	//打开记录集
	CString strSource = _T("SELECT * FROM DemoTable");
	if (!OpenRecordset(strSource))
	{
		AfxMessageBox(_T("记录集打开失败。"));
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
	ON_BN_CLICKED(IDC_WRITE, OnWrite)
	ON_BN_CLICKED(IDC_MOVENEXT, OnMoveNext)
	ON_BN_CLICKED(IDC_MOVWPREV, OnMovePrev)
	ON_BN_CLICKED(IDC_READ, OnRead)
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

	//读取记录集	
	if (m_pRecordset->BOF && m_pRecordset->adoEOF)
	{
		return FALSE;
	}
	m_pRecordset->MoveFirst();	
	_variant_t varName;
	CString strName = _T("");
	varName = m_pRecordset->GetCollect(_variant_t(_T("NAME")));
	if (varName.vt != VT_NULL)
	{
		strName = varName.bstrVal;
	}
	else
	{
		strName = _T("");
	}

	SetDlgItemText(IDC_NAME, strName);

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
	
	//打开数据库连接
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

	//关闭数据库连接
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

	//打开记录集
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

BOOL CDemoDlg::CloseRecordset()
{
	ASSERT(m_pRecordset != NULL);

	//关闭记录集
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

void CDemoDlg::OnWrite() 
{
	//创建文件对话框
	CString strFilter="二进制文件(*.*)|*.*||";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, strFilter);
	dlg.m_ofn.lpstrTitle = _T("打开二进制文件");

	if(dlg.DoModal() == IDOK)
	{
		//获得文件路径
		CString strFileName = dlg.GetPathName();

		//打开文件
		CFile file;
		if (!file.Open(strFileName, CFile::modeRead))
		{
			AfxMessageBox(_T("文件打开失败。"), MB_ICONINFORMATION);
			return;
		}

		//获得文件名
		CString strName = file.GetFileTitle();

		//获得数据大小
		UINT nLength = file.GetLength();

		//分配缓冲区
		BYTE* pChunk = new BYTE[nLength];

		//读文件
		file.Read(pChunk, nLength);

		//写数据库
		m_pRecordset->AddNew();
		m_pRecordset->PutCollect(_variant_t(_T("NAME")), 
			_variant_t(strName));
		SetFieldChunk(_T("Data"), pChunk, nLength);
		m_pRecordset->Update();
		m_pRecordset->MoveLast();
		
		//释放缓冲区
		delete []pChunk;

		//关闭文件
		file.Close();
		
		//刷新
		SetDlgItemText(IDC_NAME, strName);
		
		AfxMessageBox(_T("文件写入完成。"));
	}
}

void CDemoDlg::OnRead() 
{
	if (!(m_pRecordset->State & adStateOpen))
	{
		AfxMessageBox((_T("记录集未打开。")));
		return;
	}

 	//判断记录集是否为空
 	if (m_pRecordset->BOF && m_pRecordset->adoEOF)
 	{
 		return;
 	}
	
	//创建目录对话框
	CFolderDialog dlg(BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE | BIF_EDITBOX);

	if (dlg.DoModal() == IDOK)
	{
		//获得文件路径
		CString strFolderName = dlg.GetPathName();

		//读数据库
		variant_t varName;
		CString strName = _T("");
		varName = m_pRecordset->GetCollect(_variant_t(_T("NAME")));
		if (varName.vt != VT_NULL)
		{
			strName = varName.bstrVal;
		}
		else
		{
			strName = _T("");
		} 

		//打开文件
		CFile file;
		CString strFileName = _T("");
		strFileName.Format(_T("%s\\%s"), strFolderName, strName);
		if (!file.Open(strFileName, CFile::modeCreate | CFile::modeWrite))
		{
			AfxMessageBox(_T("文件打开失败。"), MB_ICONINFORMATION);
			return;
		}

		//获得数据大小
		UINT nLength = m_pRecordset->Fields->GetItem(_variant_t(_T("Data")))->ActualSize;

		//分配缓冲区
		BYTE* pChunk = new BYTE[nLength];

		//读数据库
		GetFieldChunk(_T("Data"), pChunk, nLength);

		//写文件
		file.Write(pChunk, nLength);

		//释放缓冲区
		delete []pChunk;

		//关闭文件
		file.Close();

		AfxMessageBox(_T("文件读出完成。"));
	}	
}

void CDemoDlg::OnMoveNext() 
{
	if (!(m_pRecordset->State & adStateOpen))
	{
		AfxMessageBox((_T("记录集未打开。")));
		return;
	}

 	//判断记录集是否为空
 	if (m_pRecordset->BOF && m_pRecordset->adoEOF)
 	{
 		return;
 	}

	//移动记录集
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

 	//读取记录集
	_variant_t varName;
	CString strName = _T("");
	varName = m_pRecordset->GetCollect(_variant_t(_T("NAME")));
	if (varName.vt != VT_NULL)
	{
		strName = varName.bstrVal;
	}
	else
	{
		strName = _T("");
	}

	//刷新
	SetDlgItemText(IDC_NAME, strName);
}

void CDemoDlg::OnMovePrev() 
{
	if (!(m_pRecordset->State & adStateOpen))
	{
		AfxMessageBox((_T("记录集未打开。")));
		return;
	}

 	//判断记录集是否为空
 	if (m_pRecordset->BOF && m_pRecordset->adoEOF)
 	{
 		return;
 	}

	//移动记录集
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

	//读取记录集
	_variant_t varName;
	CString strName = _T("");
	varName = m_pRecordset->GetCollect(_variant_t(_T("NAME")));
	if (varName.vt != VT_NULL)
	{
		strName = varName.bstrVal;
	}
	else
	{
		strName = _T("");
	}

	//刷新
	SetDlgItemText(IDC_NAME, strName);
}

BOOL CDemoDlg::SetFieldChunk(LPCTSTR lpszName, LPVOID pChunk, long nChunkSize)
{
	ASSERT(m_pRecordset != NULL);
	ASSERT(lpszName != NULL);
	ASSERT(AfxIsValidString(lpszName));
	ASSERT(pChunk != NULL);
	ASSERT(nChunkSize > 0);
	ASSERT(AfxIsValidAddress(pChunk, nChunkSize));

	SAFEARRAY* pSafeArray = NULL;
	SAFEARRAYBOUND rgsabound[1];
	rgsabound[0].lLbound = 0;
	rgsabound[0].cElements = nChunkSize;

	pSafeArray = SafeArrayCreate(VT_UI1, 1, rgsabound);

	for (long n = 0; n < nChunkSize; n++)
	{
		BYTE* pData = &(((BYTE*)pChunk)[n]);
		SafeArrayPutElement(pSafeArray, &n, pData);
	}

	_variant_t vtChunk;
	vtChunk.vt = VT_ARRAY | VT_UI1;
	vtChunk.parray = pSafeArray;

	try
	{
		return SUCCEEDED(m_pRecordset->Fields->GetItem(_variant_t(lpszName))->AppendChunk(vtChunk));
	}
	catch (_com_error e)
	{
		TRACE(_T("%s\n"), e.ErrorMessage());
		return FALSE;
	}
}

int CDemoDlg::GetFieldChunk(LPCTSTR lpszName, LPVOID pChunk, long nChunkSize)
{
	ASSERT(m_pRecordset != NULL);
	ASSERT(lpszName != NULL);
	ASSERT(AfxIsValidString(lpszName));
	ASSERT(pChunk != NULL);
	ASSERT(nChunkSize > 0);
	ASSERT(AfxIsValidAddress(pChunk, nChunkSize));

	int nActualSize = m_pRecordset->Fields->GetItem(_variant_t(lpszName))->ActualSize;
	if (nActualSize < 0)
	{
		return -1;
	}

	int nSize = min(nActualSize, nChunkSize);

	_variant_t vtChunk;

	try
	{
		vtChunk = m_pRecordset->Fields->GetItem(_variant_t(lpszName))->GetChunk(nSize);
	}
	catch (_com_error e)
	{
		TRACE(_T("%s\n"), e.ErrorMessage());
		return -1;
	}

	if (vtChunk.vt == (VT_ARRAY | VT_UI1))
	{
		BYTE* p =new BYTE;
		for (long n = 0; n < nSize; n++)
		{
			::SafeArrayGetElement(vtChunk.parray, &n, p);
			((BYTE*)pChunk)[n] = *p;          
		}
		delete p;
	}

	return nSize;
}

