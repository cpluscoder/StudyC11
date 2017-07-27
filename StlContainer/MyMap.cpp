#include "StdAfx.h"
#include <StlContainer/MyMap.h>
#include <iomanip>

#include <boost/algorithm/string.hpp>

using namespace std;


void CMyMap::TestLambda(void)
{
	pair<string, double> var1("tim1", 1.1);
	decltype(var1) var2("tim2", 2.2);
	array<map<string, double>::value_type, 4> pairArray = {
		var1,
		map<string, double>::value_type("tim3", 3.3),
		pair<string, double>("tim4", 4.4),
		var2
	};
	map<string, double> coll(pairArray.begin(), pairArray.end());

	/// 注意:pair中的const
	// square the value of each element
	for_each(
		coll.begin(), coll.end(),
		[] (pair<const string, double>& elem)
		{
			elem.second = elem.second * elem.second;
		}
	);

	// print each element
	stringstream strOutStream;
	for_each(
		coll.cbegin(), coll.cend(), 
		[&] (const map<string, double>::value_type& elem)
		{
			strOutStream << elem.first << ": " << elem.second << endl;
		}
	);
	PRINT_STREAM(strOutStream);
}

void CMyMap::TestSubScript(void)
{
	// create map / associative array
	// - keys are strings
	// - values are floats
	typedef map<string, double> StringFloatMap;

	// create empty container
	StringFloatMap stocks;

	// insert some elements
	stocks["BASF"] = 369.50;
	stocks["VW"] = 413.50;
	stocks["Daimler"] = 819.00;
	stocks["BMW"] = 834.00;
	stocks["Siemens"] = 842.20;
	// print all elements
	stringstream strOutStream;
	StringFloatMap::iterator pos;
	strOutStream << left;  // left-adjust values
	for(pos = stocks.begin(); pos != stocks.end(); ++pos)
	{
		strOutStream << "stock: " << setw(12) << pos->first << "price: " << pos->second << endl;
	}
	strOutStream << endl;
	PRINT_STREAM(strOutStream);

	// boom (all prices doubled)
	for(pos = stocks.begin(); pos != stocks.end(); ++pos)
	{
		pos->second *= 2;
	}
	// print all elements
	for(pos = stocks.begin(); pos != stocks.end(); ++pos)
	{
		strOutStream << "stock: " << setw(12) << pos->first << "price: " << pos->second << endl;
	}
	strOutStream << endl;
	PRINT_STREAM(strOutStream);

	// rename key from "VW" to "Volkswagen"
	// - provided only by exchanging element
	stocks["Volkswagen"] = stocks["VW"];
	stocks.erase("VW");
	// print all elements
	for(pos = stocks.begin(); pos != stocks.end(); ++pos)
	{
		strOutStream << "stock: " << setw(12) << pos->first << "price: " << pos->second << endl;
	}
	PRINT_STREAM(strOutStream);
}

void CMyMap::TestMultiMap(void)
{
	// create multimap as string/string dictionary
	multimap<string, string> dict;

	array<map<string, string>::value_type, 9> pairArray = {
		map<string, string>::value_type("day","Tag"), 
		map<string, string>::value_type("strange","fremd"),
		map<string, string>::value_type("car","Auto"), 
		map<string, string>::value_type("smart","elegant"),
		map<string, string>::value_type("trait","Merkmal"), 
		map<string, string>::value_type("strange","seltsam"),
		map<string, string>::value_type("smart","raffiniert"), 
		map<string, string>::value_type("smart","klug"),
		map<string, string>::value_type("clever","raffiniert") 
	};
	// insert some elements in random order
	dict.insert(pairArray.begin(), pairArray.end());

	// print all elements
	stringstream strOutStream;
	strOutStream.setf(ios::left, ios::adjustfield);
	strOutStream << ' ' << setw(10) << "english " << "german " << endl;
	strOutStream << setfill('-') << setw(20) << "" << setfill(' ') << endl;
	for(auto & elem = dict.cbegin(); elem != dict.cend(); ++elem)
	{
		strOutStream << ' ' << setw(10) << elem->first << elem->second << endl;
	}
	strOutStream << endl;
	PRINT_STREAM(strOutStream);

	// print all values for key "smart"
	string word("smart");
	strOutStream << word << ": " << endl;
	for(auto pos = dict.lower_bound(word); pos != dict.upper_bound(word); ++pos)
	{
		strOutStream << "    " << pos->second << endl;
	}
	PRINT_STREAM(strOutStream);

	// print all keys for value "raffiniert"
	word = ("raffiniert");
	strOutStream << word << ": " << endl;
	for(auto & elem = dict.cbegin(); elem != dict.cend(); ++elem)
	{
		if(elem->second == word)
		{
			strOutStream << "    " << elem->first << endl;
		}
	}
	PRINT_STREAM(strOutStream);
}

void CMyMap::TestFindIf(void)
{
	// map with floats as key and value
	// - initializing keys and values are automatically converted to float
	array<map<float, float>::value_type, 9> pairArray = {
		map<float, float>::value_type(1.0f, 7.0f), 
		map<float, float>::value_type(2.0f, 4.0f), 
		map<float, float>::value_type(3.0f, 2.0f), 
		map<float, float>::value_type(4.0f, 3.0f),
		map<float, float>::value_type(5.0f, 6.0f), 
		map<float, float>::value_type(6.0f, 1.0f), 
		map<float, float>::value_type(7.0f, 3.0f)
	};

	map<float, float> mapTest(pairArray.begin(), pairArray.end());

	stringstream strOutStream;
	// search an element with key 3.0  (logarithmic complexity)
	auto posKey = mapTest.find(3.0);
	if(posKey != mapTest.end())
	{
		strOutStream << "key 3.0 found (" << posKey->first << ":" << posKey->second << ")" << endl;
	}
	PRINT_STREAM(strOutStream);

	// search an element with value 3.0 (linear complexity)
	auto posVal = find_if(
		mapTest.begin(), mapTest.end(),
		[] (const pair<float, float>& elem)
		{
			return elem.second == 3.0;
		}
	);
	if(posVal != mapTest.end())
	{
		strOutStream << "value 3.0 found (" << posVal->first << ":" << posVal->second << ")" << endl;
	}
	PRINT_STREAM(strOutStream);
}









// function object to compare strings
// - allows you to set the comparison criterion at runtime
// - allows you to compare case insensitive
class CRuntimeStringCmp
{
public:
	// constants for the comparison criterion
	enum cmp_mode {Normal, NoCase};

public:  
	// constructor: initializes the comparison criterion
	explicit CRuntimeStringCmp(cmp_mode emMode = Normal) : _emMode(emMode) {}
	virtual ~CRuntimeStringCmp(void) {}

	// the comparison
	bool operator() (const string& s1, const string& s2) const
	{
		if(_emMode == Normal)
		{
			return s1 < s2;
		}
		else
		{
			return lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(), NoCaseCompare);
			//return boost::algorithm::ilexicographical_compare(s1, s2);/// 也行
		}
	}

private:
	// auxiliary function to compare case insensitive
	static bool NoCaseCompare(char c1, char c2)
	{
		return toupper(c1) < toupper(c2);
	}

private:
	// actual comparison mode
	const cmp_mode _emMode;
};

// container type:
// - map with
//       - string keys
//       - string values
//       - the special comparison object type
typedef map<string, string, CRuntimeStringCmp> StringStringMap;

// function that fills and prints such containers
void fillAndPrint(StringStringMap& coll)
{
	// insert elements in random order
	coll["Deutschland"] = "Germany";
	coll["deutsch"] = "German";
	coll["Haken"] = "snag";
	coll["arbeiten"] = "work";
	coll["Hund"] = "dog";
	coll["gehen"] = "go";
	coll["Unternehmen"] = "enterprise";	/// 忽略大小写时，value被下一个覆盖
	coll["unternehmen"] = "undertake";	/// 忽略大小写时，覆盖了上一个value
	coll["gehen"] = "walk";
	coll["Bestatter"] = "undertaker";

	// print elements
	stringstream strOutStream;
	strOutStream.setf(ios::left, ios::adjustfield);
	for(auto &elem = coll.cbegin(); elem != coll.cend(); ++elem)
	{
		strOutStream << setw(15) << elem->first << " " << elem->second << endl;
	}
	strOutStream << endl;
	PRINT_STREAM(strOutStream);
}

void CMyMap::TestRunTimeCmp()
{
	// create a container with the default comparison criterion
	StringStringMap coll1;
	fillAndPrint(coll1);

	// create an object for case-insensitive comparisons
	CRuntimeStringCmp ignoreCase(CRuntimeStringCmp::NoCase);

	// create a container with the case-insensitive comparisons criterion
	StringStringMap coll2(ignoreCase);
	fillAndPrint(coll2);
}
