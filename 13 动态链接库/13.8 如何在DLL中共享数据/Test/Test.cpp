// Test.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "Test.h"

#pragma data_seg(".SharedData")
int nCount = 0;
#pragma data_seg()

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			nCount++;
			break;
		case DLL_PROCESS_DETACH:
			nCount--;
			break;

		default:
			break;
    }

    return TRUE;
}

int GetCount()
{
	return nCount;
}