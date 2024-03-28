/**
 * \file  StdLog.h
 * \brief Logs, using C library and STL
 */


#pragma once

#if   defined(_WIN32)
    #include <windows.h>
#elif defined(__linux__)
    #include <unistd.h>
    #include <linux/limits.h>
#elif defined(__FreeBSD__)
    #include <sys/sysctl.h>
#elif defined(__APPLE__)
    #include <mach-o/dyld.h> // ::_NSGetExecutablePath
#else
    #warning StdTest: unsupported OS environment
#endif

// C library
#include <cerrno>
#include <ctime>
#include <cstring>

// STL
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
//-------------------------------------------------------------------------------------------------
namespace stdlog
{

//-------------------------------------------------------------------------------------------------
class Log final
	/// Log to std::cout
{
public:
///\name ctors, dtor
///\{
	Log();
	Log(const std::string &app_name, const std::string &delimiter);
   ~Log() = default;

	Log(const Log &) = delete;
	Log(Log &&) = delete;

	Log & operator = (const Log &) = delete;
	Log & operator = (Log &&) = delete;
///\}

///\name Send alerts
///\{
	void trace(const std::string &title, const std::string &text) const;
///\}

	template<typename T>
	Log & operator << (const T &value);

private:
	enum class _Level
		/// log level
	{
		Off     = 0,
		Trace   = 1,
		Debug   = 2,
		Info    = 3,
		Warning = 4,
		Error   = 5,
		Fatal   = 6
	};

	const std::string _delimiter;
	const std::string _app_name;

	void        _print(const _Level level, const std::string &subject, const std::string &text) const;
    std::string _levelString(const _Level level) const;

	std::string _currentDateTime() const;
		///< current date/time, format is %Y-%m-%d.%X
	std::string _modulePath() const;
		///< Get module path
};
//-------------------------------------------------------------------------------------------------

} // stdlog
//-------------------------------------------------------------------------------------------------
#include "StdLog.inl"
