#include "stdafx.h"

#include "include\stringbuilder.hpp"

#include "TDADLL\TDADLL.H"

tda::Session::Session()
	:
	mSourceAppName(tda::SourceApp),
	mLogLevel (5),
	mSessionId(0)
{
	std::clog << "TDADLL Session Initializing..." << std::endl;
	// init connection
	mSessionId = TDAInitSession(mLogLevel);
	if (!mSessionId)
	{
		throw std::runtime_error("Unable to initialize TDA Session");
	}
	// set app name
	int retval = TDASetSourceApp(mSessionId, mSourceAppName.c_str());
	if (retval != 0)
	{
		throw std::runtime_error("Unable to set source application name");
	}

	std::clog << "TDADLL Session Initialized" << std::endl;
}

tda::Session::~Session()
{
	if (mSessionId)
	{
		std::clog << "Terminating TDADLL Session..." << std::endl;
		TDATerminateSession(mSessionId);
		std::clog << "TDADLL Session Terminated" << std::endl;
	}
}

/***
 ***	SUBSCRIBER
 ***/
int tda::Subscriber::mLastSubHandle = 0;

tda::Subscriber::Subscriber(const Session & session)
:
	mSession (session),
	mSubType (0),
	mSubHandle (++mLastSubHandle),
	mSubscriberId (TDARegisterSubscriber (mSession.SessionId(), mSubType, mSubHandle))
{
	if (mSubscriberId < 0)
	{
		throw (std::runtime_error(utility::StringBuilder()
			<< "Error "
			<< mSubscriberId
			<< " Registering Subscriber. [" << tostr() << "]"));
	}
	std::clog << "Registered Subscriber [" << tostr().c_str() << "]" << std::endl;
}

tda::Subscriber::~Subscriber()
{
	if (mSubscriberId >= 0)
	{
		TDAUnregisterSubscriber(mSession.SessionId(), mSubscriberId);
		std::clog << "Unregistered subscriber [" << tostr() << "]" << std::endl;
	}
}

std::string tda::Subscriber::tostr() const
{
	return utility::StringBuilder() 
		<< "SessID:" << mSession.SessionId()
		<< ",SubType:" << mSubType
		<< ",SubHandle:" << mSubHandle;

}
