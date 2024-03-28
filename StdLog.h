/**
 * \file  StdLog.h
 * \brief Logs, using C library and STL
 */


#pragma once

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
	~Log() = default;

	Log(const Log &) = delete;
	Log(Log &&) = delete;

	Log & operator = (const Log &) = delete;
	Log & operator = (Log &&) = delete;
///\}

///\name Send alerts
///\{
	void trace(const std::string &subject, const std::string &text) const;
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

	void        _print(const _Level level, const std::string &subject, const std::string &text) const;
    std::string _levelString(const _Level level) const;
};
//-------------------------------------------------------------------------------------------------

} // stdlog
//-------------------------------------------------------------------------------------------------
#include "StdLog.inl"
