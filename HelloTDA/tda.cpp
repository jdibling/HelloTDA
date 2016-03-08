#include "stdafx.h"
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
