#pragma once

#include <string>
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
