#include "StdAfx.h"
#include <StudySTL/Algorithm.h>
#include <list>
#include <deque>
#include <set>

using namespace std;

CAlgorithm::CAlgorithm(void)
{
}


CAlgorithm::~CAlgorithm(void)
{
}

void CAlgorithm::Test(void)
{
	// create vector with elements from 1 to 6 in arbitrary order
	int nArray[] = { 2, 5, 4, 1, 6, 3 };
	vector<int> coll;
	for(int i = 0; i < COUNT_OF(nArray); ++i)
	{
		coll.push_back(nArray[i]);
	}

	stringstream strOutStream;
	// find and print minimum and maximum elements
	auto minpos = min_element(coll.cbegin(), coll.cend());
	if(minpos != coll.end())
	{
		strOutStream << "min: "  << *minpos << endl;
	}

	auto maxpos = max_element(coll.cbegin(), coll.cend());
	if(maxpos != coll.end())
	{
		strOutStream << "max: "  << *maxpos << endl;
	}

	// sort all elements
	sort(coll.begin(), coll.end());

	// find the first element with value 3
	// - no cbegin()/cend() because later we modify the elements pos3 refers to
	auto pos3 = find(
		coll.begin(), coll.end(),  // range
		3                          // value
		);
	if(pos3 != coll.end())
	{
		// reverse the order of the found element with value 3 and all following elements
		reverse(pos3, coll.end());
	}

	// print all elements
	for(auto iter = coll.begin(); iter != coll.end(); ++iter)
	{
		strOutStream << *iter << ' ';
	}
	strOutStream << endl;

	PRINT_STREAM(strOutStream);
}

void CAlgorithm::TestFind(void)
{
	list<int> coll;

	// insert elements from 20 to 40
	for(int i = 20; i <= 40; ++i) {
		coll.push_back(i);
	}

	// find position of element with value 3
	// - there is none, so pos3 gets coll.end()
	auto pos3 = find(
		coll.begin(), coll.end(),    // range
		3);                          // value
	if(pos3 != coll.end())
	{
		// reverse the order of elements between found element and the end
		// - because pos3 is coll.end() it reverses an empty range
		reverse(pos3, coll.end());
	}

	// find positions of values 25 and 35
	list<int>::iterator pos25, pos35;
	pos25 = find(
		coll.begin(), coll.end(),  // range
		25);                       // value
	pos35 = find(
		coll.begin(), coll.end(),  // range
		35);                       // value

	stringstream strOutStream;
	// print the maximum of the corresponding range
	// - note: including pos25 but excluding pos35
	strOutStream << "max: " << *max_element(pos25, pos35) << endl;

	// process the elements including the last position
	strOutStream << "max: " << *max_element(pos25, ++pos35) << endl;

	/// 确定 pos25 pos35 的先后顺序
	auto iterPos = find_if(coll.begin(), coll.end(),
	[] (int i)
	{
		return i == 25 || i == 35;
	});
	if(iterPos == coll.end())
	{
		/// 没有 25 35 这两个元素
	}
	else if(*iterPos == 25)
	{
		/// pos25在pos35前
		pos25 = iterPos;
		pos35 = find(++iterPos, coll.end(), 35);
	}
	else
	{
		/// pos35在pos25前
		pos35 = iterPos;
		pos25 = find(++iterPos, coll.end(), 25);
	}

	PRINT_STREAM(strOutStream);
}

void CAlgorithm::TestCopy(void)
{
	//list<int> coll1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int nArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> coll1;
	for(int i = 0; i < COUNT_OF(nArray); ++i)
	{
		coll1.push_back(nArray[i]);
	}

	vector<int> coll2;

	// RUNTIME ERROR:
	// - overwrites nonexisting elements in the destination
	//copy(coll1.cbegin(), coll1.cend(),  // source
	//	coll2.begin());                 // destination

	// resize destination to have enough room for the overwriting algorithm
	coll2.resize(coll1.size());

	// copy elements from first into second collection
	// - overwrites existing elements in destination
	copy(coll1.cbegin(), coll1.cend(),  // source
		coll2.begin());                 // destination

	// create third collection with enough room
	// - initial size is passed as parameter
	deque<int> coll3(coll1.size());

	// copy elements from first into third collection
	copy(coll1.cbegin(), coll1.cend(),  // source
		coll3.begin());                 // destination
}

void CAlgorithm::TestRemove(void)
{
	Remove4();
	Remove3();
	Remove2();
	Remove1();
}

void CAlgorithm::Remove1(void)
{
	list<int> coll;

	// insert elements from 6 to 1 and 1 to 6
	for(int i = 1; i <= 6; ++i) {
		coll.push_front(i);
		coll.push_back(i);
	}

	stringstream strOutStream;
	// print all elements of the collection
	strOutStream << "pre:  ";
	copy(coll.cbegin(), coll.cend(),         // source
		ostream_iterator<int>(strOutStream, " "));   // destination
	strOutStream << endl;

	// remove all elements with value 3
	remove(coll.begin(), coll.end(),      // range
		3);                               // value

	// print all elements of the collection
	strOutStream << "post: ";
	copy(coll.cbegin(), coll.cend(),         // source
		ostream_iterator<int>(strOutStream, " "));   // destination
	strOutStream << endl;

	PRINT_STREAM(strOutStream);
}

void CAlgorithm::Remove2(void)
{
	list<int> coll;

	// insert elements from 6 to 1 and 1 to 6
	for(int i = 1; i <= 6; ++i) {
		coll.push_front(i);
		coll.push_back(i);
	}

	stringstream strOutStream;
	// print all elements of the collection
	copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(strOutStream, " "));
	strOutStream << endl;

	// remove all elements with value 3
	// - retain new end
	list<int>::iterator end = remove(coll.begin(), coll.end(), 3);

	// print resulting elements of the collection
	copy(coll.begin(), end, ostream_iterator<int>(strOutStream, " "));
	strOutStream << endl;

	// print number of removed elements
	strOutStream << "number of removed elements: " << distance(end, coll.end()) << endl;

	// remove "removed" elements
	coll.erase(end, coll.end());

	// print all elements of the modified collection
	copy(coll.cbegin(), coll.cend(),
		ostream_iterator<int>(strOutStream, " "));
	strOutStream << endl;

	PRINT_STREAM(strOutStream);
}

void CAlgorithm::Remove3(void)
{
	stringstream strOutStream;
	
	// unordered set with elements from 1 to 9
	//set<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int nArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	set<int> coll;
	for(int i = 0; i < COUNT_OF(nArray); ++i)
	{
		coll.insert(nArray[i]);
	}

	// print all elements of the collection
	copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(strOutStream, " "));
	strOutStream << endl;

	// Remove all elements with value 3
	// - algorithm remove() does not work
	// - instead member function erase() works
	int num = coll.erase(3);

	// print number of removed elements
	strOutStream << "number of removed elements: " << num << endl;

	// print all elements of the modified collection
	copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(strOutStream, " "));
	strOutStream << endl;

	PRINT_STREAM(strOutStream);
}

void CAlgorithm::Remove4(void)
{
	list<int> coll;

	// insert elements from 6 to 1 and 1 to 6
	for(int i = 1; i <= 6; ++i) {
		coll.push_front(i);
		coll.push_back(i);
	}
	PRINT_ELEMENTS(coll);

	// remove all elements with value 3 (poor performance)
	auto iterEnd = remove(coll.begin(), coll.end(), 3);
	if(iterEnd != coll.end())
	{
		coll.erase(iterEnd, coll.end());
		PRINT_ELEMENTS(coll);
	}

	// remove all elements with value 4 (good performance)
	coll.remove(4);
	PRINT_ELEMENTS(coll);
}

// function that test the passed argument
void TestValue(int elem)
{
	elem = elem;
}

void CAlgorithm::TestForEach(void)
{
	vector<int> coll;

	// insert elements from 1 to 9
	for(int i = 1; i <= 9; ++i) {
		coll.push_back(i);
	}

	// test all elements
	for_each(
		coll.cbegin(), coll.cend(),  // range
		TestValue);                  // operation

	PRINT_ELEMENTS(coll);
}

//////////////////////////////////////////////////////////////////////////
///	Transform(容器复制)
int Square(int value)
{
	return value * value;
}

void CAlgorithm::TestTransform(void)
{
	set<int>    coll1;
	vector<int> coll2;

	// insert elements from 1 to 9 into coll1
	for(int i = 1; i <= 9; ++i) {
		coll1.insert(i);
	}
	PRINT_ELEMENTS(coll1, "initialized: ");

	// transform each element from coll1 to coll2
	// - square transformed values
	transform(coll1.cbegin(), coll1.cend(),	// source
		back_inserter(coll2),				// destination
		Square);							// operation

	PRINT_ELEMENTS(coll2, "squared:     ");
}

template <class Type>
class MultValue
{
private:
	Type Factor;   // The value to multiply by
public:
	// Constructor initializes the value to multiply by
	MultValue(const Type& _Val) : Factor(_Val) {
	}

	// The function call for the element to be multiplied
	Type operator () (Type& elem) const 
	{
		return elem * Factor;
	}
};

void CAlgorithm::TestTransformMsdn()
{
	stringstream strOutStream;
	vector <int> v1, v2(7), v3(7);
	vector <int>::iterator Iter1, Iter2 , Iter3;

	// Constructing vector v1
	for(int i = -4; i <= 2; ++i)
	{
		v1.push_back(i);
	}

	strOutStream << "Original vector  v1 = ( " ;
	for(Iter1 = v1.begin() ; Iter1 != v1.end() ; ++Iter1)
	{
		strOutStream << *Iter1 << " ";
	}
	strOutStream << ")." << endl;

	// Modifying the vector v1 in place
	transform(v1.begin(), v1.end(), v1.begin(), MultValue<int>(2));
	strOutStream << "The elements of the vector v1 multiplied by 2 in place gives:" << "\n v1mod = ( " ;
	for(Iter1 = v1.begin(); Iter1 != v1.end(); ++Iter1)
	{
		strOutStream << *Iter1 << " ";
	}
	strOutStream << ")." << endl;

	// Using transform to multiply each element by a factor of 5
	transform(v1.begin(), v1.end(), v2.begin(), MultValue<int>(5));
	strOutStream << "Multiplying the elements of the vector v1mod\n " <<  "by the factor 5 & copying to v2 gives:\n v2 = ( " ;
	for(Iter2 = v2.begin(); Iter2 != v2.end(); ++Iter2)
	{
		strOutStream << *Iter2 << " ";
	}
	strOutStream << ")." << endl;

	// The second version of transform used to multiply the 
	// elements of the vectors v1mod & v2 pairwise
	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), multiplies<int>());
	strOutStream << "Multiplying elements of the vectors v1mod and v2 pairwise " <<  "gives:\n v3 = ( " ;
	for(Iter3 = v3.begin(); Iter3 != v3.end(); Iter3++)
	{
		strOutStream << *Iter3 << " ";
	}
	strOutStream << ")." << endl;

	PRINT_STREAM(strOutStream);
}

//////////////////////////////////////////////////////////////////////////
/// Predicate(判断表达式)
// predicate, which returns whether an integer is a prime number
bool isPrime(int number)
{
	// ignore negative sign
	number = abs(number);

	// 0 and 1 are no prime numbers
	if(number == 0 || number == 1)
	{
		return false;
	}

	// find divisor that divides without a remainder
	int divisor;
	for(divisor = number / 2; number % divisor != 0; --divisor)
	{
		;
	}

	// if no divisor greater than 1 is found, it is a prime number
	return divisor == 1;
}

void CAlgorithm::TestPredicate(void)
{
	list<int> coll;

	// insert elements from 24 to 30
	for(int i = 24; i <= 30; ++i) {
		coll.push_back(i);
	}

	stringstream strOutStream;
	// search for prime number
	auto pos = find_if(
		coll.cbegin(), coll.cend(),  // range
		isPrime);                    // predicate
	if(pos != coll.end())
	{
		// found
		strOutStream << *pos << " is first prime number found" << endl;
	}
	else
	{
		// not found
		strOutStream << "no prime number found" << endl;
	}

	PRINT_STREAM(strOutStream);
}

//////////////////////////////////////////////////////////////////////////
/// DoublePredicate(双参数判断表达式)
class CPerson
{
public:
	CPerson(void) {}
	CPerson(const string& f, const string& n) : fn(f), ln(n) {}

	string firstName() const { return fn; }
	string lastName() const { return ln; }

private:
	string fn;    // first name
	string ln;    // last name
};

ostream& operator<< (ostream& s, const CPerson& p)
{
    s << "[" << p.firstName() << " " << p.lastName() << "]";
    return s;
}


/* binary function predicate:
 * - returns whether a person is less than another person
 */
bool personSortCriterion(const CPerson& p1, const CPerson& p2)
{
    /* a person is less than another person
     * - if the last name is less
     * - if the last name is equal and the first name is less
     */
    return p1.lastName() < p2.lastName() || (p1.lastName() == p2.lastName() && p1.firstName() < p2.firstName());
}

void CAlgorithm::TestDoublePredicate(void)
{
    // create some persons
    CPerson p1("nicolai", "josuttis");
    CPerson p2("ulli", "josuttis");
    CPerson p3("anica", "josuttis");
    CPerson p4("lucas", "josuttis");
    CPerson p5("lucas", "otto");
    CPerson p6("lucas", "arm");
    CPerson p7("anica", "holle");
    
    // insert person into collection coll
    deque<CPerson> coll;
    coll.push_back(p1);
    coll.push_back(p2);
    coll.push_back(p3);
    coll.push_back(p4);
    coll.push_back(p5);
    coll.push_back(p6);
    coll.push_back(p7);

	stringstream strOutStream;
    // print elements
    strOutStream << "deque before sort():" << endl;
    deque<CPerson>::iterator pos;
    for(pos = coll.begin(); pos != coll.end(); ++pos) {
        strOutStream << *pos << endl;
    }

    // sort elements
    sort(coll.begin(),coll.end(),    // range
         personSortCriterion);       // sort criterion

    // print elements
    strOutStream << "deque after sort():" << endl;
    for(pos = coll.begin(); pos != coll.end(); ++pos) {
        strOutStream << *pos << endl;
    }

	PRINT_STREAM(strOutStream);
}

