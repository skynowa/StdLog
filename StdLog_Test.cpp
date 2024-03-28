/**
 * \file  main.cpp
 * \brief
 */


#include <iostream>
#include "StdLog.h"
//-------------------------------------------------------------------------------------------------
class CoreLog final :
	public stdlog::Log
{
public:
	CoreLog() :
		stdlog::Log("Core", "|")
	{
	}
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	using namespace  stdlog;

	{
		CoreLog().trace("Title", "Long message");
	}

	{
		CoreLog() << "Title" << "Long message";
	}

	std::cout << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
