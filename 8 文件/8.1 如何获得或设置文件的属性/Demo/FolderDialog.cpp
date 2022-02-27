// FolderDialog.cpp: implementation of the CFolderDialog class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "shlobj.h"
#include "FolderDialog.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFolderDialog::CFolderDialog(LPCITEMIDLIST pidlRoot, LPTSTR lpszDisplayName, 
	LPCTSTR lpszTitle, UINT nFlags) 
{
	memset(&m_bi, 0, sizeof(BROWSEINFO));
	m_bi.pidlRoot = pidlRoot;
	m_bi.pszDisplayName = lpszDisplayName;
	m_bi.lpszTitle = lpszTitle;
	m_bi.ulFlags = nFlags;

	m_pidl = NULL;
}

CFolderDialog::~CFolderDialog()
{

}

int CFolderDialog::DoModal()
{
	int nResult = 0;

	m_pidl = SHBrowseForFolder(&m_bi);

	if (m_pidl != NULL)
	{
		nResult = IDOK;
	}
	else
	{
		nResult = IDCANCEL;
	}

	return nResult;
} 

CString CFolderDialog::GetPathName()
{
	CString strPathName = _T("");
	TCHAR szPathName[MAX_PATH];

	if(::SHGetPathFromIDList(m_pidl, szPathName))
	{
		strPathName = szPathName;
	}

	return strPathName;
}
