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
		OutputDebugString("��׼����\n");
	}
	virtual ~CCopyData(void)
	{
		OutputDebugString("����\n");
	}

	CCopyData(const CCopyData &)
	{
		OutputDebugString("��������\n");
	}
	CCopyData(const CCopyData &&)
	{
		OutputDebugString("��ֵ���ÿ�������\n");
	}
	CCopyData &operator= (const CCopyData &)
	{
		OutputDebugString("��ֵ�����\n");
		return *this;
	}
	CCopyData &operator= (const CCopyData &&)
	{
		OutputDebugString("��ֵ���ø�ֵ�����\n");
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