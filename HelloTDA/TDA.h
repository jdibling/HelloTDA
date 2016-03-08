#ifndef HELLO_TDA_TDA_H
#define HELLO_TDA_TDA_H

namespace tda
{
	const std::string tdaLibPath = "C:\\Users\\JohnDibling\\Desktop\\TDA\\TDADLL.DLL";
	const std::string SourceAppId = "JODI";
	static HMODULE tdaLibMod = 0;

	int InitSession(int logginLevel);

}
#endif
