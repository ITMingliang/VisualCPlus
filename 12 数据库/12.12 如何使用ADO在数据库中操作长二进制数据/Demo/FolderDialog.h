// FolderDialog.h: interface for the CFolderDialog class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(FOLDERDIALOG_H__INCLUDED_)
#define AFX_FOLDERDIALOG_H__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef	BIF_NEWDIALOGSTYLE
#define	BIF_NEWDIALOGSTYLE	0x0040
#endif

#ifndef	BIF_USENEWUI
#define	BIF_USENEWUI		0x0050
#endif

class CFolderDialog : public CObject  
{
public:
	CFolderDialog(UINT nFlag);
	virtual ~CFolderDialog();

	void SetTitle(LPCTSTR lpszTitle);
	int DoModal();
	CString GetPathName();
	
private:
	ITEMIDLIST* m_pItemIDList;
	BROWSEINFO m_bi;
};

#endif // !defined(FOLDERDIALOG_H__INCLUDED_)
