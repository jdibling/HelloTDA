// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <cstdlib>
#include <string>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <sstream>

#include <Windows.h>

namespace detail
{
	const std::string SourceAppID = "JODI";
}

namespace util {
	// ====================================================
	class StringBuilder
	{
	public:
		template <typename T> inline StringBuilder& operator<<(const T& t)
		{
			mStream << t;
			return *this;
		}
		inline std::string get() const
		{
			return mStream.str();
		}
		inline operator std::string() const
		{
			return get();
		}

	private:
		std::stringstream mStream;
	};

	// ====================================================
}

template <typename Str> inline Str& operator<< (Str& str, const util::StringBuilder& builder)
{
	str << builder.get();
	return str;
}


// TODO: reference additional headers your program requires here
#include "TDA.h"