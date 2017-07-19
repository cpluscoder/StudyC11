#include "StdAfx.h"
#include "MySmartPtr.h"
#include <memory>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>


CMySmartPtr::CMySmartPtr(void)
{
	/// 执行了两次构造 1、开辟内存空间（new） 2、构造智能指针上下文
	/// 可能开辟内存空间(new)失败 
	std::shared_ptr<CClassForTest> pTest(new CClassForTest("1", 1));

	/// 只执行一次构造，且较安全
	std::shared_ptr<CClassForTest> pMakeShared = std::make_shared<CClassForTest>("222", 3);

	/// 运行时类型转换
	std::shared_ptr<void> sp(new char[8], [](char *pInt) {
		if(pInt != nullptr)
		{
			delete [] pInt;
			pInt = nullptr;
		}
	});
	std::shared_ptr<char *> spNew(std::static_pointer_cast<char *>(sp));

	std::shared_ptr<void> pData(new CClassForTest("45678", 5));
	std::shared_ptr<CClassForTest> pDataNew(std::static_pointer_cast<CClassForTest>(pData));

}

CMySmartPtr::~CMySmartPtr(void)
{
}

void CMySmartPtr::CreateSharedPtr(void)
{
	/// STD方法1
	std::shared_ptr<CClassForTest> pData1(new CClassForTest("12", 2));
	if(pData1->Data() != nullptr)
	{
		OutputDebugString(pData1->Data());
	}

	/// STD方法2
	std::shared_ptr<CClassForTest> pData2 = std::make_shared<CClassForTest>("234", 3);
	if(pData2->Data() != nullptr)
	{
		OutputDebugString(pData2->Data());
	}

	/// STD方法3
	std::shared_ptr<CClassForTest> pData3;
	pData3.reset(new CClassForTest("3456", 4));
	if(pData3->Data() != nullptr)
	{
		OutputDebugString(pData3->Data());
	}

	/// BOOST方法1
	boost::shared_ptr<CClassForTest> pData4(new CClassForTest("45678", 5));
	if(pData4->Data() != nullptr)
	{
		OutputDebugString(pData4->Data());
	}

	/// BOOST方法2
	boost::shared_ptr<CClassForTest> pData5 = boost::make_shared<CClassForTest>("567890", 6);
	if(pData5->Data() != nullptr)
	{
		OutputDebugString(pData5->Data());
	}
	
	/// BOOST方法3
	boost::shared_ptr<CClassForTest> pData6;
	pData6.reset(new CClassForTest("6789012", 7));
	if(pData6->Data() != nullptr)
	{
		OutputDebugString(pData6->Data());
	}
}

void CMySmartPtr::DefineDeleteOperator(void)
{
	std::shared_ptr<CClassForTest> pData1(new CClassForTest("12", 2), [](CClassForTest *p) {
		if(p != nullptr)
		{
			delete [] p;
			p = nullptr;
		}
	});
	if(pData1->Data() != nullptr)
	{
		OutputDebugString(pData1->Data());
	}

	//std::shared_ptr<CClassForTest> pData2 = std::make_shared<CClassForTest>("234", 3), [](CClassForTest *p) {
	//	if(p != nullptr)
	//	{
	//		delete [] p;
	//		p = nullptr;
	//	}
	//});
	//if(pData2->Data() != nullptr)
	//{
	//	OutputDebugString(pData2->Data());
	//}

	std::shared_ptr<CClassForTest> pData3;
	pData3.reset(new CClassForTest("3456", 4), [](CClassForTest *p) {
		if(p != nullptr)
		{
			delete [] p;
			p = nullptr;
		}
	});
	if(pData3->Data() != nullptr)
	{
		OutputDebugString(pData3->Data());
	}


	boost::shared_ptr<CClassForTest> pData4(new CClassForTest("45678", 5), [](CClassForTest *p) {
		if(p != nullptr)
		{
			delete [] p;
			p = nullptr;
		}
	});
	if(pData4->Data() != nullptr)
	{
		OutputDebugString(pData4->Data());
	}

	boost::shared_ptr<CClassForTest> pData6;
	pData6.reset(new CClassForTest("6789012", 7), [](CClassForTest *p) {
		if(p != nullptr)
		{
			delete [] p;
			p = nullptr;
		}
	});
	if(pData6->Data() != nullptr)
	{
		OutputDebugString(pData6->Data());
	}
}

void CMySmartPtr::DeleteArrayPtr(void)
{
	const int c_nArraySize = 10;
	std::shared_ptr<int> pIntArray1(new int [c_nArraySize], 
		[] (int *pArray)
		{
			if(nullptr != pArray)
			{
				delete [] pArray;
				pArray = nullptr;
			}
		}
	);
	int nTemp = 0;
	for(int i = 0; i < c_nArraySize; i++)
	{
		pIntArray1.get()[i] = i + 1;
		nTemp = pIntArray1.get()[i];
	}

	std::shared_ptr<int> pIntArray2(new int [c_nArraySize], std::default_delete<int[]>());
	for(int i = 0; i < c_nArraySize; i++)
	{
		pIntArray2.get()[i] = i + 2;
		nTemp = pIntArray2.get()[i];
	}
}


/// 1:正确 0:错误
#define WEAK_PTR_USE_OK	 1

/// 循环引用(Cyclic Reference)
/// 共享对象,但不拥有
class CPersonCyclicReference 
{
public:
	explicit CPersonCyclicReference(const std::string & strName, 
		std::shared_ptr<CPersonCyclicReference> pMother = nullptr,
		std::shared_ptr<CPersonCyclicReference> pFather = nullptr)
	{
		m_strName = strName;
		m_pMother = pMother;
		m_pFather = pFather;
	}
	virtual ~CPersonCyclicReference(void)
	{
		OutputDebugString("delete person\n");
	}

	void PrintData(void)
	{
		std::string strData;
		strData = "\n";
		strData.append(m_strName);
		strData.append("\n");
		strData.append(m_pMother->m_strName);
		strData.append("\n");
		strData.append(m_pFather->m_strName);
		strData.append("\n");
		for(auto iter = m_vctChild.begin(); iter != m_vctChild.end(); iter++)
		{
#if WEAK_PTR_USE_OK
			std::weak_ptr<CPersonCyclicReference> & pChild = *iter;
			strData.append(pChild.lock()->m_strName);/// 注意弱指针成员访问方式
#else
			std::shared_ptr<CPersonCyclicReference> & pChild = *iter;
			strData.append(pChild->m_strName);
#endif
		}
		
		OutputDebugString(strData.c_str());
	}

	void AddChild(std::shared_ptr<CPersonCyclicReference> pChild)
	{
		m_vctChild.push_back(pChild);
	}

protected:
	std::string m_strName;
	std::shared_ptr<CPersonCyclicReference> m_pMother;
	std::shared_ptr<CPersonCyclicReference> m_pFather;
#if WEAK_PTR_USE_OK
	std::vector<std::weak_ptr<CPersonCyclicReference>> m_vctChild;
#else
	std::vector<std::shared_ptr<CPersonCyclicReference>> m_vctChild;
#endif
};

void CMySmartPtr::WeakPtr(void)
{
	auto lambdaCreate = [&] (const std::string &strName) ->std::shared_ptr<CPersonCyclicReference> {
		std::shared_ptr<CPersonCyclicReference> pMother(new CPersonCyclicReference(strName + "'s mother"));
		std::shared_ptr<CPersonCyclicReference> pFather(new CPersonCyclicReference(strName + "'s father"));
		std::shared_ptr<CPersonCyclicReference> pChild(new CPersonCyclicReference(strName, pMother, pFather));
		pMother->AddChild(pChild);
		pFather->AddChild(pChild);
		return pChild;
	};

	std::string strName = "Jack";
	std::shared_ptr<CPersonCyclicReference> pFamily = lambdaCreate(strName);
	pFamily->PrintData();

	//pFamily.reset();
	pFamily = lambdaCreate("小王");/// pFamily原有对象过期,自动释放!!! 同pFamily.reset();
	pFamily->PrintData();
}

/// 明确希望共享,但不希望拥有
class CPersonSharedFromThis : public std::enable_shared_from_this<CPersonSharedFromThis>
{
public:
	explicit CPersonSharedFromThis(const std::string & strName, 
		std::shared_ptr<CPersonSharedFromThis> pMother = nullptr,
		std::shared_ptr<CPersonSharedFromThis> pFather = nullptr)
	{
		m_strName = strName;
		m_pMother = pMother;
		m_pFather = pFather;
		m_vctChild.clear();
	}

	virtual ~CPersonSharedFromThis(void)
	{
		OutputDebugString("delete person\n");
	}

protected:
	std::string m_strName;
	std::shared_ptr<CPersonSharedFromThis> m_pMother;
	std::shared_ptr<CPersonSharedFromThis> m_pFather;
	std::vector<std::shared_ptr<CPersonSharedFromThis>> m_vctChild;
};

