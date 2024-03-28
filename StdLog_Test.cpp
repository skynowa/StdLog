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
		Log().trace("test", "long message now ");
	}

	{
		Log() << "Hello, World!" << 42 << 3.14 << "test" << "long message now ";
	}

	std::cout << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
