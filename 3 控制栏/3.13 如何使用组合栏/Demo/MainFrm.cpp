// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Demo.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_TEST, OnTest)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	//������Ͽ�
	if (!m_ComboBox.Create(WS_CHILD | WS_VISIBLE | WS_VSCROLL | 
		CBS_DROPDOWN, CRect(0, 0, 100, 200), this, IDC_COMBOBOX))
    {
		return FALSE;
    }

	//������ť
	m_Button.Create(_T("ȷ��"), WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON, 
		CRect(0, 0, 50, 20), this, IDC_TEST);

	//����Rebar
	if (!m_wndReBar.Create(this))
	{
		return -1;
	}

	//��ӹ���������Ͽ򡢰�ť��ӵ�Rebar��
	m_wndReBar.AddBar(&m_wndToolBar);
	m_wndReBar.AddBar(&m_ComboBox, NULL, NULL,  
		RBBS_NOGRIPPER | RBBS_BREAK);
	m_wndReBar.AddBar(&m_Button, NULL, NULL, RBBS_NOGRIPPER);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

void CMainFrame::OnTest()
{
	CString strText = _T("");
	m_ComboBox.GetWindowText(strText);

	if ((!strText.IsEmpty()) && (CB_ERR == m_ComboBox.FindString(-1, strText)))
	{
		m_ComboBox.AddString(strText);
	}

	AfxMessageBox(strText);
}
