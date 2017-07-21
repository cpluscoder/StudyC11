#pragma once

#include <CommonDef.h>

/// vs2010 不支持std::chrono, 使用boost::chrono
#include <boost/chrono.hpp>
#include <boost/ratio.hpp>
#include <boost/format.hpp>


class CMyDateTime
{
	DEFINE_BOOST_SHARED_PTR(CMyDateTime)

public:
	
	virtual ~CMyDateTime(void);

	void Test(void);

protected:

	// convert timepoint of system clock to calendar time string
	inline std::string asString(const boost::chrono::system_clock::time_point& tp)
	{
		// convert to system time:
		std::time_t t = boost::chrono::system_clock::to_time_t(tp);

		//std::string ts = ctime(&t);    // convert to calendar time
		//ts.resize(ts.size()-1);        // skip trailing newline

		char szBuf[64];
		ZeroMemory(szBuf, 64);
		errno_t err = ctime_s(szBuf, 64, &t);
		if(err == 0)
		{
			std::string strDateTime = szBuf;
			strDateTime.resize(strDateTime.size() - 1);
			return strDateTime; 
		}

		return std::string("");
	}

	inline std::string timePoint2Str(const boost::chrono::system_clock::time_point& tp)
	{
		// convert to system time:
		std::time_t t = boost::chrono::system_clock::to_time_t(tp);
		tm dtTemp;
		if(0 == ::localtime_s(&dtTemp, &t))
		{
			//ptime dt = ptime_from_tm(dtTemp);

			//strDateTime = to_iso_string(dt);

			std::string strFormat = "%04d-%02d-%02d %02d:%02d:%02d";
			boost::format formatStr = boost::format(strFormat.c_str())
				% (dtTemp.tm_year + 1900) % (dtTemp.tm_mon + 1) % dtTemp.tm_mday
				% dtTemp.tm_hour % dtTemp.tm_min % dtTemp.tm_sec;

			std::string strDateTime = formatStr.str();

			return std::string(formatStr.str());
		}

		return "";
	}


	explicit CMyDateTime(void);

	// convert calendar time to timepoint of system clock
	inline boost::chrono::system_clock::time_point makeTimePoint(int year, int mon, int day, int hour, int min, int sec = 0)
	{
		struct std::tm t;
		t.tm_sec = sec;          // second of minute (0 .. 59 and 60 for leap seconds)
		t.tm_min = min;          // minute of hour (0 .. 59)
		t.tm_hour = hour;        // hour of day (0 .. 23)
		t.tm_mday = day;         // day of month (1 .. 31)
		t.tm_mon = mon - 1;      // month of year (0 .. 11)
		t.tm_year = year - 1900; // year since 1900
		t.tm_isdst = -1;         // determine whether daylight saving time
		std::time_t tt = std::mktime(&t);
		
		if(tt == -1)
		{
			throw "no valid system time";
		}
		
		return boost::chrono::system_clock::from_time_t(tt);
	}

};

template <typename C>
void printClockData(void)
{
	using std::endl;
	std::stringstream strStream;
	std::string strOut;

	strStream << "- precision: ";
	//strOut = strStream.str();
	//OutputDebugString(strOut.c_str());

	// if time unit is less than or equal to one millisecond
	typedef typename C::period P;   // type of time unit
	if(boost::ratio_less_equal<P, boost::milli>::value)
	{
		// convert to and print as milliseconds
		typedef typename boost::ratio_multiply<P, boost::kilo>::type TT;
		strStream << std::fixed << double(TT::num)/TT::den << " milliseconds" << endl;
		//strOut = strStream.str();
		//OutputDebugString(strOut.c_str());
	}
	else
	{
		// print as seconds
		strStream << std::fixed << double(P::num)/P::den << " seconds" << endl;
		//strOut = strStream.str();
		//OutputDebugString(strOut.c_str());
	}
	strStream << "- is_steady: " << std::boolalpha << C::is_steady << endl;
	strOut = strStream.str();
	OutputDebugString(strOut.c_str());
}

