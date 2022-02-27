// MDIClientWnd.h: interface for the CMDIClientWnd class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MDICLIENTWND_H__A285DECB_41B1_42EC_9DDC_5263F66B58F6__INCLUDED_)
#define AFX_MDICLIENTWND_H__A285DECB_41B1_42EC_9DDC_5263F66B58F6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMDIClientWnd : public CWnd  
{
	DECLARE_DYNAMIC(CMDIClientWnd)

public:
	CBrush m_Brush;
	CMDIClientWnd();
	virtual ~CMDIClientWnd();

	//{{AFX_MSG(CWnd)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif // !defined(AFX_MDICLIENTWND_H__A285DECB_41B1_42EC_9DDC_5263F66B58F6__INCLUDED_)
