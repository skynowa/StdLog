/**
 * \file  StdLog_Test.cpp
 * \brief
 */


#include <iostream>
#include "StdLog.h"

using namespace stdlog;
//-------------------------------------------------------------------------------------------------
class CoreTraceLog final :
	public Log
{
public:
	CoreTraceLog() :
		Log("Core", Log::Level::Trace, " ")
	{
	}
};
//-------------------------------------------------------------------------------------------------
STD_LOG_TRACE(TestLog, "AppTest");
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	// CoreTraceLog
	{
		CoreTraceLog() << "Title #1" << "Long message" << 111.0;
		CoreTraceLog() << "Title #2" << "Long message" << 222.0;
		CoreTraceLog() << "Title #3" << "Long message" << 333.0 << std::endl;
	}

	// TestLog
	{
		TestLog() << "Test #1" << "Test message" << 111.0;
		TestLog() << "Test #2" << "Test message" << 222.0;
		TestLog() << "Test #3" << "Test message" << 333.0 << std::endl;
	}

	std::cout << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
