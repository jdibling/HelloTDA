// HelloTDA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	std::cout << "Hello, TDA" << std::endl;
	tda::tdaLibMod = LoadLibraryA(tda::tdaLibPath.c_str());
	if (!tda::tdaLibMod)
	{
		const DWORD err = GetLastError();
		std::cerr << "*** ERROR 0x" << std::hex << err << " loading library " << tda::tdaLibPath << " ***" << std::endl;

		LPTSTR errorText = NULL;

		FormatMessage(
			// use system message tables to retrieve error text
			FORMAT_MESSAGE_FROM_SYSTEM
			// allocate buffer on local heap for error text
			| FORMAT_MESSAGE_ALLOCATE_BUFFER
			// Important! will fail otherwise, since we're not 
			// (and CANNOT) pass insertion parameters
			| FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,    // unused with FORMAT_MESSAGE_FROM_SYSTEM
			err,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPTSTR)&errorText,  // output 
			0, // minimum size for output buffer
			NULL);   // arguments - see note 

		const std::wstring errMsg(errorText);
		std::wcerr << "\tError: '" << errMsg << "'" << std::endl;

		HeapFree(GetProcessHeap(), 0, errorText);
	}

	// init the session
	const int sessionHandle = tda::InitSession(5);
	

   return 0;
}

