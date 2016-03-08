#include "stdafx.h"
#include "tda.h"
#include "C:\Users\JohnDibling\Desktop\TDA\TDADLL.H"

int tda::InitSession(int loggingLevel)
{
	typedef int(__cdecl *Fn)(int);
	static Fn fn = 0;
	static const std::string fnName = "TDAInitSession";
	if (!fn)
	{
		fn = reinterpret_cast <Fn> (GetProcAddress(tdaLibMod, fnName.c_str()));
		if (!fn)
		{
			std::string err = util::StringBuilder() <<  "*** ERROR Getting Process Address for " << fnName;
			std::cerr << err << std::endl;
			throw std::runtime_error(err);
		}
	}

}