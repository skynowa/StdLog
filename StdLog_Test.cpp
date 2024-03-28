/**
 * \file  StdLog_Test.cpp
 * \brief
 */


#include <iostream>
#include "StdLog.h"

using namespace stdlog;
//-------------------------------------------------------------------------------------------------
class CoreLineLog final :
	public Log
{
public:
	CoreLineLog() :
		Log(Log::OutputType::Line, "Core", "|")
	{
	}
};
//-------------------------------------------------------------------------------------------------
class CoreMsgBoxLog final :
	public Log
{
public:
	CoreMsgBoxLog() :
		Log(Log::OutputType::MsgBox, "Core", "|")
	{
	}
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	{
		CoreLineLog().trace("Title", "Long message");
	}

	{
		CoreMsgBoxLog().trace("Title", "Long message");
	}

	{
		CoreLineLog() << "Title" << "Long message";
	}

	std::cout << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
