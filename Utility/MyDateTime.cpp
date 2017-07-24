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
	std::stringstream strOutStream;
	// print the epoch of this system clock:
	boost::chrono::system_clock::time_point tp;
	strOutStream << "epoch: " << timePoint2Str(tp) << std::endl;

	// print current time:
	tp = boost::chrono::system_clock::now();
	strOutStream << "now:   " << timePoint2Str(tp) << std::endl;

	// print minimum time of this system clock:
	//tp = boost::chrono::time_point<boost::chrono::system_clock>::min();
	//strOutStream << "min:   " << timePoint2Str/*asString*/(tp) << std::endl;

	// print maximum time of this system clock:
	//tp = boost::chrono::system_clock::time_point::max();
	//strOutStream << "max:   " << timePoint2Str/*asString*/(tp) << std::endl;

	strOut = strOutStream.str();
	OutputDebugString(strOut.c_str());
	}


//////////////////////////////////////////////////////////////////////////
///
	{
	std::stringstream strOutStream;

	// define type for durations that represent day(s):
	typedef boost::chrono::duration<int, boost::ratio<3600 * 24>> Days;

	// process the epoch of this system clock
	boost::chrono::time_point<boost::chrono::system_clock> timePoint;
	strOutStream << "epoch:     " << timePoint2Str/*asString*/(timePoint) << endl;

	// add one day, 23 hours, and 55 minutes
	timePoint += Days(1) + boost::chrono::hours(23) + boost::chrono::minutes(55);
	strOutStream << "later:     " << timePoint2Str/*asString*/(timePoint) << endl;

	/// 将时间变量转换为较精确类型时，总是可以成
	/// 将时间变量转换为较粗糙类型时，会发生舍入导致误差，需要使用duration_cast
	// process difference from epoch in minutes and days:
	auto diff = timePoint - boost::chrono::system_clock::time_point();
	strOutStream << "diff:      " << boost::chrono::duration_cast<boost::chrono::minutes>(diff).count() << " minute(s)" << endl;
	Days days = boost::chrono::duration_cast<Days>(diff);
	strOutStream << "diff:      " << days.count() << " day(s)" << endl;

	// subtract one year (hoping it is valid and not a leap year)
	timePoint -= boost::chrono::hours(24 * 365);
	strOutStream << "-1 year:   " << /*timePoint2Str*/asString(timePoint) << endl;

	// subtract 50 years (hoping it is valid and ignoring leap years)
	timePoint -= boost::chrono::duration<int, boost::ratio<3600 * 24 * 365>>(50);
	strOutStream << "-50 years: " << /*timePoint2Str*/asString(timePoint) << endl;

	// subtract 50 years (hoping it is valid and ignoring leap years)
	timePoint -= boost::chrono::duration<int, boost::ratio<3600 * 24 * 365>>(50);
	strOutStream << "-50 years: " << /*timePoint2Str*/asString(timePoint) << endl;

	strOut = strOutStream.str();
	OutputDebugString(strOut.c_str());
	}

//////////////////////////////////////////////////////////////////////////
///
	std::stringstream strOutStream4;
	auto tp1 = makeTimePoint(2010, 01, 01, 00, 00);
	strOutStream4 << timePoint2Str/*asString*/(tp1) << std::endl;
	auto tp2 = makeTimePoint(2011, 05, 23, 13, 44);
	strOutStream4 << timePoint2Str/*asString*/(tp2) << std::endl;
	strOut = strOutStream4.str();
	OutputDebugString(strOut.c_str());

	std::stringstream strOutStream1;
	strOutStream1 << "system_clock: " << std::endl;
	strOut = strOutStream1.str();
	OutputDebugString(strOut.c_str());
	printClockData<boost::chrono::system_clock>();

	std::stringstream strOutStream2;
	strOutStream2 << "\nhigh_resolution_clock: " << std::endl;
	strOut = strOutStream2.str();
	OutputDebugString(strOut.c_str());
	printClockData<boost::chrono::high_resolution_clock>();

	std::stringstream strOutStream3;
	strOutStream3 << "\nsteady_clock: " << std::endl;
	strOut = strOutStream3.str();
	OutputDebugString(strOut.c_str());
	printClockData<boost::chrono::steady_clock>();
}