// Test.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "Test.h"


BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    return TRUE;
}

int fnTest(void)
{
	return 100;
}