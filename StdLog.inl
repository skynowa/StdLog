/**
 * \file  StdLog.inl
 * \brief Logs, using C library and STL
 */


namespace stdlog
{

//-------------------------------------------------------------------------------------------------
inline
Log::Log(
	const std::string &a_appName,
	const Level        a_level,
	const std::string &a_delimiter
) :
	_appName  (a_appName),
	_level    (a_level),
	_delimiter(a_delimiter)
{
}
//-------------------------------------------------------------------------------------------------
inline
Log::Log() :
	Log("App", Level::Trace, "|")
{
}
//-------------------------------------------------------------------------------------------------
inline
Log::~Log()
{
	std::cout << std::endl;
}
//-------------------------------------------------------------------------------------------------


/**************************************************************************************************
*    operators
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
template<typename T>
inline Log &
Log::operator << (const T &a_value)
{
	if (_isBol) {
		_isBol = false;

		const std::string &module   = "[" + _modulePath() + "]";
		const std::string &app      = "[" + _appName + "]";
		const std::string &dateTime = _currentDateTime() ;
		const std::string &level    = _levelString(_level);

		std::cout
			<< module   << _delimiter
			<< app      << _delimiter
			<< dateTime << _delimiter
			<< level;
	}

	std::cout << _delimiter << a_value;

	return *this;
}
//-------------------------------------------------------------------------------------------------


/**************************************************************************************************
*    private
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
inline std::string
Log::_levelString(
    const Level a_level
) const
{
	static const std::map<Level, std::string> levels
	{
		{Level::Off,     "Off"},
		{Level::Trace,   "Trace"},
		{Level::Debug,   "Debug"},
		{Level::Info,    "Info"},
		{Level::Warning, "Warning"},
		{Level::Error,   "Error"},
		{Level::Fatal,   "Fatal"}
	};

	auto it = levels.find(a_level);
	if (it == levels.cend()) {
		return {};
	}

	return it->second;
}
//-------------------------------------------------------------------------------------------------
inline std::string
Log::_currentDateTime() const
{
    std::string sRv;

    constexpr std::size_t buffSize           {80};
    char                  buff[buffSize + 1] {};

    const time_t timeNow = std::time(nullptr);

    const std::tm *timeLocal = std::localtime(&timeNow);
    if (timeLocal == nullptr) {
        return {};
    }

    size_t uiRv = std::strftime(buff, buffSize, "%Y-%m-%d.%X", timeLocal);
    if (uiRv == 0) {
        return {};
    }

    sRv.assign(&buff[0], uiRv);

    return sRv;
}
//-------------------------------------------------------------------------------------------------
inline std::string
Log::_modulePath() const
{
    std::string sRv;

#if   defined(_WIN32)
    sRv.resize(MAX_PATH);

    DWORD stored = ::GetModuleFileName(nullptr, &sRv.at(0), static_cast<DWORD>( sRv.size() ));
    if (stored == 0UL) {
        return "<unknown>";
    }

    sRv.resize(stored);
#elif defined(__linux__)
	const std::string procFile = "/proc/" + std::to_string(::getpid()) + "/exe";

	int         readed {- 1};
	std::string filePath(PATH_MAX, '\0');

	for ( ; ; ) {
		readed = ::readlink(procFile.c_str(), &filePath.at(0), filePath.size());
		if (readed == - 1) {
			return "<unknown>";
		}

		if (filePath.size() > static_cast<size_t>(readed)) {
			break;
		}

		filePath.resize(filePath.size() * 2);
	}

	filePath.resize( static_cast<size_t>(readed) );

	sRv.assign(
		std::find(filePath.crbegin(), filePath.crend(), '/').base(),
		filePath.cend());
#elif defined(__FreeBSD__)
    constexpr u_int mibSize            {4};
    int             mib[mibSize]       {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, - 1};
    char            buff[PATH_MAX + 1] {};
    std::size_t     buffSize           {sizeof(buff) - 1};

    int iRv = ::sysctl(mib, mibSize, buff, &buffSize, nulptr, 0U);
    if (iRv == - 1) {
        return "<unknown>";
    }

    sRv.assign(buff);
#elif defined(__APPLE__)
    constexpr auto buffSize = static_cast<std::uint32_t>(PATH_MAX);
	std::tstring_t buff(buffSize + 1, {});

	int_t iRv = ::_NSGetExecutablePath(&buff[0], &buffSize);
	if (iRv != 0) {
		buff.resize(buffSize);

		iRv = ::_NSGetExecutablePath(&buff[0], &buffSize);
		if (iRv != 0) {
			return "<unknown>";
		}
	}

	sRv = buff.c_str();	// Trim '\0'
#else
    sRv = "<unknown>";
#endif

    return sRv;
}
//-------------------------------------------------------------------------------------------------

} // stdlog
