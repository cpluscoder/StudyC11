#include "StdAfx.h"
#include "TestLib01.h"

using namespace std;

CTestLib01::CTestLib01(void)
{
}


CTestLib01::~CTestLib01(void)
{
}


bool CTestLib01::Test(void)
{
	OutputDebugString("CTestLib01::Test\n");

	return true;
}

double ReturnDouble(void)
{
	return 1.1f;
}

#include <functional>

std::function<int(int, int)> ReturnLambda(void)
{
	return [] (int x, int y) {
		return x * y;
	};
}


template <typename T1, typename T2>
auto add11(T1 x, T2 y) ->decltype(x + y)
{
	return x + y;
}



void CTestLib01::TestAuto(void)
{
	auto nNum = 42;
	auto fRtn = ReturnDouble();
	//auto i;/// Compile error!

	static auto s_var = 3.14;

	auto lambdaData = [] (int nParam)->bool {
		if(nParam == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

	if(lambdaData(11))
	{
		OutputDebugString("true");
	}
	else
	{
		OutputDebugString("false");
	}

	string strOut = "Out";

	/// 引用传递
	auto lambdaData1 = [&] (string &strParam) {
		if(strParam.empty())
		{
			strParam = "1";
			strOut.clear();
		}
		else
		{
			strParam = "2";
			strOut = "a";
		}
	};
	string strData;
	strData.clear();
	lambdaData1(strData);

	/// 值传递
	auto lambdaData2 = [=] (string &strParam) {
		if(strParam.empty())
		{
			strParam = "1" + strOut;
		}
		else
		{
			strParam = strOut;
		}
	};
	lambdaData2(strData);
	OutputDebugString("\n");

	string strOut1, strOut2;
	auto lambdaFunction1 = [strOut1, &strOut2] (int nTemp) ->bool {
		if(nTemp == 0)
		{
			strOut1.empty();
			strOut2 = "1111";
			return true;
		}
		else
		{
			nTemp = strOut1.size();
			strOut2.clear();
			return false;
		}
	};
	if(lambdaFunction1(0))
	{
		OutputDebugString("true");
	}
	if(lambdaFunction1(1))
	{
		OutputDebugString("true");
	}

	int x = 1, y = 2, z = 3;
	auto lambdaFunction2 = [=, &z] (int nTemp) {
		z = x;
		z = y;
		z = z + 1;
		//x = z;
	};
	lambdaFunction2(0);

	auto lambdaFunction3 = [x, y, z] (int nTemp) mutable {
		z = x;
		z = y;
		z = z + 1;
		x = z;
	};
	lambdaFunction3(0);

	auto lf = ReturnLambda();
	auto autoRtn = lf(11, 2);
	OutputDebugString("\n");

	x = 2;
	y = 4;
	auto nTemp = add11(x, y);
}

