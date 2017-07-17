#include "StdAfx.h"
#include "RValueReferences.h"
#include <set>

using namespace std;


CRValueReferences::CRValueReferences(void)
{
}


CRValueReferences::~CRValueReferences(void)
{
}

class CCopyData
{
public:
	CCopyData(void)
	{
		OutputDebugString("标准构造\n");
	}
	virtual ~CCopyData(void)
	{
		OutputDebugString("析构\n");
	}

	CCopyData(const CCopyData &)
	{
		OutputDebugString("拷贝构造\n");
	}
	CCopyData(const CCopyData &&)
	{
		OutputDebugString("右值引用拷贝构造\n");
	}
	CCopyData &operator= (const CCopyData &)
	{
		OutputDebugString("赋值运算符\n");
		return *this;
	}
	CCopyData &operator= (const CCopyData &&)
	{
		OutputDebugString("右值引用赋值运算符\n");
		return *this;
	}


protected:
	string m_strData;
};

void CreateAndInsert(std::vector<CCopyData> &inParam)
{
	CCopyData obj1;
	inParam.push_back(obj1);
	OutputDebugString("\n");

	CCopyData obj2;
	inParam.push_back(std::move(obj2));
	OutputDebugString("\n");
}

void CRValueReferences::Test()
{
	std::vector<CCopyData> inParam;
	CreateAndInsert(inParam);
}