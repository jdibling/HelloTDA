#ifndef UTILITY_STRINGBUILDER_HPP
#define UTILITY_STRINGBUILDER_HPP

#include <cstdlib>
#include <string>
#include <sstream>

namespace utility {
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

template <typename Str> inline Str& operator<< (Str& str, const utility::StringBuilder& builder)
{
	str << builder.get();
	return str;
}

#endif