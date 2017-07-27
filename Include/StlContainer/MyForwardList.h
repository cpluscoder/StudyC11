#pragma once

#include <CommonDef.h>

class CMyForwardList
{
	DEFINE_BOOST_SHARED_PTR(CMyForwardList)
public:
	
	virtual ~CMyForwardList(void) {}

	void Test(void);

	void TestSplice(void);

protected:
	explicit CMyForwardList(void) {}
};

template <typename InputIterator, typename Tp>
inline InputIterator find_before(InputIterator first, InputIterator last, const Tp& val)
{
	if(first == last) {
		return first;
	}
	InputIterator next(first);
	++next;
	while(next != last && !(*next == val)) {
		++next;
		++first;
	}
	return first;
}

template <typename InputIterator, typename Pred>
inline InputIterator find_before_if(InputIterator first, InputIterator last, Pred pred)
{
	if(first == last) {
		return first;
	}
	InputIterator next(first);
	++next;
	while(next != last && !pred(*next)) {
		++next;
		++first;
	}
	return first;
}
