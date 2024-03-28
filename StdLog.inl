/**
 * \file  StdLog.inl
 * \brief Logs, using C library and STL
 */


namespace stdlog
{

//-------------------------------------------------------------------------------------------------
inline
Log::Log() :
	_delimiter(" | ")
{
}
//-------------------------------------------------------------------------------------------------
inline void
Log::trace(
	const std::string &a_subject,
	const std::string &a_text
) const
{
	_print(_Level::Trace, a_subject, a_text);
}
//-------------------------------------------------------------------------------------------------
template<typename T>
Log &
Log::operator << (const T &value)
{
	std::cout << value << _delimiter;

	return *this;
}
//-------------------------------------------------------------------------------------------------


/**************************************************************************************************
*    private
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
inline void
Log::_print(
	const _Level       a_level,
	const std::string &a_subject,
	const std::string &a_text
) const
{
	const std::string &module   = "[app]";
	const std::string &dateTime = "14-Mar-2024";
	const std::string &level    = _levelString(a_level);

	if (0) {
		std::cout
			<< "\n"
			<< "--------------------- STD_LOG --------------------" << "\n"
			<< " Module:     " << module                            << "\n"
			<< " Date time:  " << dateTime                          << "\n"
			<< " Level:      " << level                             << "\n"
			<< " Subject:    " << a_subject                         << "\n"
			<< " Text:       " << a_text                            << "\n"
			<< "--------------------------------------------------" << std::endl;
	} else {
		std::cout
			<< module    << _delimiter
			<< dateTime  << _delimiter
			<< level     << _delimiter
			<< a_subject << _delimiter
			<< a_text    << _delimiter
			<< std::endl;
	}
}
//-------------------------------------------------------------------------------------------------
std::string
Log::_levelString(
    const _Level a_level
) const
{
	static const std::map<_Level, std::string> levels
	{
		{_Level::Off,     "Off"},
		{_Level::Trace,   "Trace"},
		{_Level::Debug,   "Debug"},
		{_Level::Info,    "Info"},
		{_Level::Warning, "Warning"},
		{_Level::Error,   "Error"},
		{_Level::Fatal,   "Fatal"}
	};

	auto it = levels.find(a_level);
	if (it == levels.cend()) {
		return {};
	}

	return it->second;
}
//-------------------------------------------------------------------------------------------------

} // stdlog
