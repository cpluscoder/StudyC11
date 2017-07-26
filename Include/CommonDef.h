#pragma once

#include <string>
#include <array>
#include <map>
#include <vector>
#include <tuple>
#include <boost/shared_ptr.hpp>
#include <boost/interprocess/sync/interprocess_semaphore.hpp>


/*!< ����BOOST����ָ�� */
#define DECLARE_BOOST_SHARED_PTR(ClassName)	\
public: \
	typedef boost::shared_ptr<ClassName> Pointer;	\
protected:	\
	ClassName(const ClassName &);	\
	ClassName &operator= (const ClassName &);


/*!< ����BOOST����ָ�� */
#define DEFINE_BOOST_SHARED_PTR(ClassName)	\
public:	\
	typedef boost::shared_ptr<ClassName> Pointer;	\
	static ClassName::Pointer Create()	\
	{	\
		return ClassName::Pointer(new ClassName);	\
	}	\
protected:	\
	ClassName(const ClassName &);	\
	ClassName &operator= (const ClassName &);


/************************************************************************/
/* ����Windows��Ϣ                                                      */
/************************************************************************/


/************************************************************************/
/* ����ʱ��                                                             */
/************************************************************************/

/************************************************************************/
/* ���������������                                                     */
/************************************************************************/



/************************************************************************/
/* ���峣�ò���                                                         */
/************************************************************************/
#define COUNT_OF(arr)   (sizeof(arr) / sizeof(arr[0]))

#define PRINT_STREAM(strOutStream) 	{	\
	std::string strOut = strOutStream.str();	\
	OutputDebugString(strOut.c_str());	\
	}


template <typename T>
inline void PRINT_ELEMENTS(const T& collection, const char *pszData = nullptr)
{
	std::stringstream strOutStream;

	if(pszData != nullptr)
	{
		strOutStream << pszData;
	}
	
	for(auto iter = collection.begin(); iter != collection.end(); ++iter)
	{
		strOutStream << *iter << ' ';
	}
	strOutStream << std::endl;

	PRINT_STREAM(strOutStream);
}

template <typename T1, typename T2>
inline void CopySrcToDst(const T1& src, T2& dst)
{
	dst.clear();
	for(auto iter = src.begin(); iter != src.end(); ++iter)
	{
		dst.push_back(*iter);
	}
}


/************************************************************************/
/* ���峣��                                                             */
/************************************************************************/
#define STRING_TRUE						"TRUE"
#define STRING_FALSE					"FALSE"



/************************************************************************/
/* ���嵥������                                                         */
/************************************************************************/



/************************************************************************/
/* ������                                                             */
/************************************************************************/



/************************************************************************/
/* �ź���                                                               */
/************************************************************************/
class CMySemaphore
{
public:
	typedef boost::shared_ptr<CMySemaphore> pointer;
	static CMySemaphore::pointer Create(unsigned int nInitialCount = 0)
	{
		return CMySemaphore::pointer(new CMySemaphore(nInitialCount));
	}

	virtual ~CMySemaphore(void) {}

	void Post(void)
	{
		m_semaphore.post();
	}

	void Wait(void)
	{
		m_semaphore.wait();
	}

protected:
	explicit CMySemaphore(unsigned int nInitialCount = 0) : m_semaphore(nInitialCount)
	{
	}

protected:
	boost::interprocess::interprocess_semaphore m_semaphore;
};
