#include "StdAfx.h"
#include <Utility/MyException.h>
#include <system_error>

using namespace std;

template <typename T>
void ProcessCodeException(const T & exp)
{
	auto errorCode = exp.code();
	string str1 = errorCode.category().name();
	OutputDebugString(str1.c_str());
	string str2 = errorCode.value;
	OutputDebugString(str2.c_str());
	string str3 = errorCode.message();
	OutputDebugString(str3.c_str());
	string str4 = errorCode.default_error_condition().category().name();
	OutputDebugString(str4.c_str());
	string str5 = errorCode.default_error_condition().value();
	OutputDebugString(str5.c_str());
	string str6 = errorCode.default_error_condition().message();
	OutputDebugString(str6.c_str());
}

CMyException::CMyException(void)
{
}


CMyException::~CMyException(void)
{
}

void CMyException::Func3(void)
{
	OutputDebugString("Func3 In\n");
	//throw "1";
	//throw std::out_of_range("out_of_range(somewhere, somehow)");
	throw CStdException("CStdException");
	throw CMyExceptionData(3);
	
	OutputDebugString("Func3 Out\n");
}

void CMyException::Func2(void)
{
	OutputDebugString("Func2 In\n");
	Func3();
	OutputDebugString("Func2 Out\n");
}

void CMyException::Func1(void)
{
	OutputDebugString("Func1 In\n");
	Func2();
	OutputDebugString("Func1 Out\n");
}


void CMyException::Test()
{
	try
	{
		Func1();
	}
	//catch (...)
	//{
	//	OutputDebugString("catch exception\n");
	//}
	catch(exception &exp)
	{
		CStdException *pObj = dynamic_cast<CStdException *>(&exp);
		if(nullptr != pObj)
		{
			OutputDebugString(pObj->GetError().c_str());
		}
		else
		{
			OutputDebugString(exp.what());
		}
		OutputDebugString("\ncatch exception\n");
	}
	catch(CMyExceptionData &exp)
	{
		OutputDebugString(exp.GetErrorDesc().c_str());
		OutputDebugString("\ncatch exception\n");
	}
}
