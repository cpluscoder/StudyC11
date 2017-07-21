#pragma once

#include <CommonDef.h>
#include <boost/format.hpp>
#include <exception>

class CMyException
{
	DEFINE_BOOST_SHARED_PTR(CMyException)
public:
	
	virtual ~CMyException(void);

	void Test();

protected:
	void Func1(void);
	void Func2(void);
	void Func3(void);

protected:
	explicit CMyException(void);
};

class CStdException : public std::exception
{
public:
	explicit CStdException(const std::string &strError) { m_strError = strError; }
	virtual ~CStdException(void) {}

	const std::string &GetError(void) const { return m_strError; }

protected:
	std::string m_strError;
};

class CMyExceptionData
{
public:
	explicit CMyExceptionData(int nCode = 0) { m_nCode = nCode; }
	virtual ~CMyExceptionData(void) {}

	const std::string &GetErrorDesc(void)
	{
		if(m_strDesc.empty())
		{
			boost::format fmt("%d");
			fmt % m_nCode;
			m_strDesc = fmt.str();
		}

		return m_strDesc;
	}

protected:
	int m_nCode;
	std::string m_strDesc;
};

