// ExtClass.cpp: implementation of the CExtClass class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#include "ExtClass.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CExtClass::CExtClass()
{

}

CExtClass::~CExtClass()
{

}

void CExtClass::Test()
{
	AfxMessageBox(_T("DLLÖÐµÄÀà¡£"));
}
