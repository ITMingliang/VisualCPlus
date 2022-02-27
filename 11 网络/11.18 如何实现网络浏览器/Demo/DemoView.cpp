// DemoView.cpp : implementation of the CDemoView class
//

#include "stdafx.h"
#include "Demo.h"

#include "DemoDoc.h"
#include "DemoView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoView

IMPLEMENT_DYNCREATE(CDemoView, CHtmlView)

BEGIN_MESSAGE_MAP(CDemoView, CHtmlView)
	//{{AFX_MSG_MAP(CDemoView)
	ON_COMMAND(ID_GO_BACK, OnGoBack)
	ON_COMMAND(ID_GO_FORWARD, OnGoForward)
	ON_COMMAND(ID_STOP, OnStop)
	ON_COMMAND(ID_GO_REFRESH, OnGoRefresh)
	ON_COMMAND(ID_GO_HOME, OnGoHome)
	ON_COMMAND(ID_GO_SERACH, OnGoSerach)
	ON_COMMAND(IDOK, OnEnterAddress)
	ON_CBN_SELENDOK(IDC_ADDRESS, OnSelendokAddress)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CHtmlView::OnFilePrint)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoView construction/destruction

CDemoView::CDemoView()
{
	// TODO: add construction code here

}

CDemoView::~CDemoView()
{
}

BOOL CDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CHtmlView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView drawing

void CDemoView::OnDraw(CDC* pDC)
{
	CDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CDemoView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	// TODO: This code navigates to a popular spot on the web.
	//  change the code to go where you'd like
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView printing


/////////////////////////////////////////////////////////////////////////////
// CDemoView diagnostics

#ifdef _DEBUG
void CDemoView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CDemoView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CDemoDoc* CDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemoDoc)));
	return (CDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDemoView message handlers

void CDemoView::OnGoBack() 
{
	//����
	GoBack();
}

void CDemoView::OnGoForward() 
{
	//ǰ��
	GoForward();
}

void CDemoView::OnStop() 
{
	//ֹͣ
	Stop();
}

void CDemoView::OnGoRefresh() 
{
	//ˢ��
	Refresh();
}

void CDemoView::OnGoHome() 
{
	//��ҳ
	GoHome();
}

void CDemoView::OnGoSerach() 
{
	//����
	GoSearch();
}

void CDemoView::OnEnterAddress()
{
	//�����ַ
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	CComboBoxEx* pAddressBar = &pMainFrame->m_wndAddressBar;
	CString strURL = _T("");
	pAddressBar->GetWindowText(strURL);

	//�����ҳ
	Navigate2(strURL, 0, NULL);

	//��ӵ�ַ�б�
	COMBOBOXEXITEM item;
	item.mask = CBEIF_TEXT;
	item.iItem = -1;
	item.pszText = (LPTSTR)(LPCTSTR)strURL;
	pAddressBar->InsertItem(&item);
}

void CDemoView::OnSelendokAddress()
{
	//�����ַ
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	CComboBoxEx* pAddressBar = &pMainFrame->m_wndAddressBar;
	CString strURL = _T("");
	pAddressBar->GetLBText(pAddressBar->GetCurSel(), strURL);

	//�����ҳ
	Navigate2(strURL, 0, NULL);
}



