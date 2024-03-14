/**
 * \file  StdLog.inl
 * \brief Logs, using C library and STL
 */


namespace stdlog
{

//-------------------------------------------------------------------------------------------------
inline
Log::Log()
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
	const std::string &module    = "[app]";
	const std::string &dateTime  = "14-Mar-2024";
	const std::string &level     = _levelString(a_level);

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
		const std::string delimiter = " | ";

		std::cout
			<< module    << delimiter
			<< dateTime  << delimiter
			<< level     << delimiter
			<< a_subject << delimiter
			<< a_text    << delimiter
			<< std::endl;
	}
}
//-------------------------------------------------------------------------------------------------
std::string
Log::_levelString(
    const _Level a_level
) const
{
	std::string sRv;

	switch (a_level) {
	case _Level::Off:
		sRv = "Off";
		break;
	case _Level::Trace:
		sRv = "Trace";
		break;
	case _Level::Debug:
		sRv = "Debug";
		break;
	case _Level::Info:
		sRv = "Info";
		break;
	case _Level::Warning:
		sRv = "Warning";
		break;
	case _Level::Error:
		sRv = "Error";
		break;
	case _Level::Fatal:
		sRv = "Fatal";
		break;
	}

	return sRv;
}
//-------------------------------------------------------------------------------------------------

} // stdlog
