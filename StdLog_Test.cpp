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

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
