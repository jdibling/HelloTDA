#ifndef HELLOTDA_TDA_H
#define HELLOTDA_TDA_H

namespace tda
{
	static const std::string SourceApp = "JODI";

	class Session
	{
	public:
		Session();
		virtual ~Session();

	private:
		const std::string mSourceAppName;
		const int mLogLevel;
			
		int mSessionId;
	};
}

#endif