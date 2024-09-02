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

// Qt
#if QT_VERSION
	#include <QString>
#endif
//-------------------------------------------------------------------------------------------------
namespace stdlog
{

//-------------------------------------------------------------------------------------------------
class Log
	/// Log to std::cout
{
public:
///\name ctors, dtor
///\{
	enum class Level
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

	Log();
	Log(const std::string &appName, const Level level, const std::string &delimiter);
   ~Log();

	Log(const Log &) = delete;
	Log(Log &&) = delete;

	Log & operator = (const Log &) = delete;
	Log & operator = (Log &&) = delete;
///\}

///\name operators
///\{
	template<typename T>
	Log & operator << (const T &value);
		///< std, QString
	Log & operator << (std::ostream &(*manipulator)(std::ostream &));
		///< std::endl
///\}

private:
	const std::string _appName;
	const Level       _level {Level::Off};
	const std::string _delimiter;

    std::string _levelString(const Level level) const;
        ///< Level enum as string
	std::string _currentDateTime() const;
		///< current date/time, format is %Y-%m-%d.%X
	std::string _modulePath() const;
		///< Get module path

	bool _isBol {true};
};
//-------------------------------------------------------------------------------------------------

} // stdlog
//-------------------------------------------------------------------------------------------------
#define STD_LOG_FACTORY_IMPL(logType, appName, level, delimiter) \
	class logType final : \
		public stdlog::Log \
	{ \
	public: \
		logType() : \
			Log(appName, level, delimiter) \
		{ \
		} \
	}
	///< Log factory - as base
#define STD_LOG_TRACE(logType, appName) \
	STD_LOG_FACTORY_IMPL(logType, appName, Log::Level::Trace, " ")
	///< Log factory - as trace level
//-------------------------------------------------------------------------------------------------
#include "StdLog.inl"
