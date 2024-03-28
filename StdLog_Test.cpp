/**
 * \file  main.cpp
 * \brief
 */


#include <iostream>
#include "StdLog.h"
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	using namespace  stdlog;

	{
		Log().trace("Title", "Long message");
	}

	{
		Log() << "Title" << "Long message";
	}

	std::cout << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
