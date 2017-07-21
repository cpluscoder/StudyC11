#include "StdAfx.h"
#include <Utility/MyDateTime.h>




CMyDateTime::CMyDateTime(void)
{
}


CMyDateTime::~CMyDateTime(void)
{
}


void CMyDateTime::Test(void)
{
	std::string strOut;
	using std::endl;

//////////////////////////////////////////////////////////////////////////
///
	{
	std::stringstream strStream;
	// print the epoch of this system clock:
	boost::chrono::system_clock::time_point tp;
	strStream << "epoch: " << timePoint2Str(tp) << std::endl;

	// print current time:
	tp = boost::chrono::system_clock::now();
	strStream << "now:   " << timePoint2Str(tp) << std::endl;

	// print minimum time of this system clock:
	//tp = boost::chrono::time_point<boost::chrono::system_clock>::min();
	//strStream << "min:   " << timePoint2Str/*asString*/(tp) << std::endl;

	// print maximum time of this system clock:
	//tp = boost::chrono::system_clock::time_point::max();
	//strStream << "max:   " << timePoint2Str/*asString*/(tp) << std::endl;

	strOut = strStream.str();
	OutputDebugString(strOut.c_str());
	}


//////////////////////////////////////////////////////////////////////////
///
	{
	std::stringstream strStream;

	// define type for durations that represent day(s):
	typedef boost::chrono::duration<int, boost::ratio<3600 * 24>> Days;

	// process the epoch of this system clock
	boost::chrono::time_point<boost::chrono::system_clock> timePoint;
	strStream << "epoch:     " << timePoint2Str/*asString*/(timePoint) << endl;

	// add one day, 23 hours, and 55 minutes
	timePoint += Days(1) + boost::chrono::hours(23) + boost::chrono::minutes(55);
	strStream << "later:     " << timePoint2Str/*asString*/(timePoint) << endl;

	/// 将时间变量转换为较精确类型时，总是可以成
	/// 将时间变量转换为较粗糙类型时，会发生舍入导致误差，需要使用duration_cast
	// process difference from epoch in minutes and days:
	auto diff = timePoint - boost::chrono::system_clock::time_point();
	strStream << "diff:      " << boost::chrono::duration_cast<boost::chrono::minutes>(diff).count() << " minute(s)" << endl;
	Days days = boost::chrono::duration_cast<Days>(diff);
	strStream << "diff:      " << days.count() << " day(s)" << endl;

	// subtract one year (hoping it is valid and not a leap year)
	timePoint -= boost::chrono::hours(24 * 365);
	strStream << "-1 year:   " << /*timePoint2Str*/asString(timePoint) << endl;

	// subtract 50 years (hoping it is valid and ignoring leap years)
	timePoint -= boost::chrono::duration<int, boost::ratio<3600 * 24 * 365>>(50);
	strStream << "-50 years: " << /*timePoint2Str*/asString(timePoint) << endl;

	// subtract 50 years (hoping it is valid and ignoring leap years)
	timePoint -= boost::chrono::duration<int, boost::ratio<3600 * 24 * 365>>(50);
	strStream << "-50 years: " << /*timePoint2Str*/asString(timePoint) << endl;

	strOut = strStream.str();
	OutputDebugString(strOut.c_str());
	}

//////////////////////////////////////////////////////////////////////////
///
	std::stringstream strStream4;
	auto tp1 = makeTimePoint(2010, 01, 01, 00, 00);
	strStream4 << timePoint2Str/*asString*/(tp1) << std::endl;
	auto tp2 = makeTimePoint(2011, 05, 23, 13, 44);
	strStream4 << timePoint2Str/*asString*/(tp2) << std::endl;
	strOut = strStream4.str();
	OutputDebugString(strOut.c_str());

	std::stringstream strStream1;
	strStream1 << "system_clock: " << std::endl;
	strOut = strStream1.str();
	OutputDebugString(strOut.c_str());
	printClockData<boost::chrono::system_clock>();

	std::stringstream strStream2;
	strStream2 << "\nhigh_resolution_clock: " << std::endl;
	strOut = strStream2.str();
	OutputDebugString(strOut.c_str());
	printClockData<boost::chrono::high_resolution_clock>();

	std::stringstream strStream3;
	strStream3 << "\nsteady_clock: " << std::endl;
	strOut = strStream3.str();
	OutputDebugString(strOut.c_str());
	printClockData<boost::chrono::steady_clock>();
}