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

CFolderDialog::CFolderDialog(UINT nFlag)
{
	::ZeroMemory(&m_bi, sizeof(BROWSEINFO));
	m_bi.ulFlags = nFlag;
	m_pItemIDList = NULL;
}

CFolderDialog::~CFolderDialog()
{

}

void CFolderDialog::SetTitle(LPCTSTR lpszTitle)
{
	ASSERT(lpszTitle != NULL);
	ASSERT(AfxIsValidString(lpszTitle));
	
	m_bi.lpszTitle  = lpszTitle;
}

int CFolderDialog::DoModal()
{
	int nResult = 0;

	m_pItemIDList = SHBrowseForFolder(&m_bi);

	if (m_pItemIDList != NULL)
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

	if (m_pItemIDList != NULL)
	{
		TCHAR szPathName[MAX_PATH];
		if(::SHGetPathFromIDList(m_pItemIDList, szPathName))
		{
			strPathName = szPathName;
		}
	}

	if (strPathName.Right(1) == _T("\\"))
	{
		strPathName = strPathName.Left(strPathName.GetLength() - 1);
	}

	return strPathName;
}
