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
		int SessionId() const { return mSessionId;  }

	private:
		const std::string mSourceAppName;
		const int mLogLevel;
			
		int mSessionId;
	};

	class Subscriber
	{
	public:
		Subscriber(const Session& session);
		virtual ~Subscriber();
		std::string tostr() const;
	private:
		const Session & mSession;
		const int mSubType;
		const int mSubHandle;
		const int mSubscriberId;
		static int mLastSubHandle;
	};
}

#endif