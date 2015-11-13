#include <iostream>
#include <list>
#include <string>

#include "linkedlist.h"
#include "binary_tree.h"
#include "number_utils.h"
#include "stringfunctions.h"
//#include "IndustryClassifications.h"
#include "sort.h"
#include "misc.h"
#include "stack.h"
#include "my_class.h"
#include "Socket.h"
#include "Thread.h"

void compareDoublesTest();
void printDoubleResult(bool result);
void testBinaryTree();
void testLargestCommonStr();

void testStack();
void testSortinglist();
void testSort();
void testStrings();
void testFizzBuzz();
void testLinkedList();
void testSockets();
void testNumbers();


#define PLUS1(a) ((a) + 1)

using std::cout;

int main()
{
	char pause = {0};

	//compareDoublesTest();
	//testStack();

	//testSortinglist();

	//testBinaryTree();
	//testLargestCommonStr();

	//testSort();
	//testStrings();
	//testFizzBuzz();
	//testLinkedList();
	//testSockets();
	//testNumbers();

	//bool even = sd::evenDivide(10, 5);
	

	struct Object_t { char h[9]; short a; short b; };
	cout << sizeof(Object_t);

	Object_t object;
	cout<<sizeof(object);
	
	cout << std::endl<< "Press Any key to exit" << std::endl;
	std::cin.get(&pause, 1);
	return 0;
}

void testNumbers()
{
	int reverse = sd::number_utils::reverseNumber(123654);
	sd::number_utils::fibonacci(15);
	cout << sd::number_utils::FindFirtSignedInt("adlkjflk-123adslf098234");
	cout << "sqrt of .321: " << sd::number_utils::sqrt(.321) << std::endl;
	cout << "sqrt of 589.21: " << sd::number_utils::sqrt(589.21) << std::endl;
}

void testSockets()
{
#ifdef __linux__
	sd::SocketThread servThread;
	sd::SocketThread clientThread;
	clientThread.SetClient();
	clientThread.StartInternalThread();
	servThread.SetServer();
	servThread.StartInternalThread();
	servThread.WaitForInternalThreadToExit();
#endif
}

void testConstructor()
{
	/*
	kc::MyClass();

	kc::MyClass mc1;
	kc::MyClass mc2(mc1);
	kc::MyClass mc3(MyClass());
	kc::MyClass mc4 = MyClass(MyClass());
	*/

}

void testFizzBuzz()
{
	sd::number_utils test;
	test.printFizzBuzz();
}

void testSort()
{
	int test[] = {1,12,5,26,7,14,3,7,2};
	int size = sizeof(test) / sizeof(test[0]);
	sd::printArray(test,0, size);
	sd::QuickSort(test, 0, size-1);
	//sd::printArray(test, 0, size);
}

/*
void testIndustryTaxonomy()
{
	try
	{
		sd::readInput();
		sd::printClassification();
		sd::findCompanies("Health Care", "CompanyName");
		sd::findCompanies("Large Pharmaceuticals", "MarketCap");
		sd::findCompanies("Aerospace & Defense", "IndustryRevenue");
		sd::findCompanies("Early Commercial Biotech", "CompanyName");
		sd::findIndustries("Gemvax & Kael");
	}
	catch(std::bad_alloc& exc)
	{
	  cout<<"Exception: std::bad_alloc"<<std::endl;
	}
}*/

void testBinaryTree()
{
	sd::BTNode<int> * bt = NULL;
	sd::GenNodeBinaryTree<int>(&bt,0);
	sd::BreadthFirstTraversalPreOrder(bt);
	cout<<std::endl;
	sd::GenNodeBinaryTree<int>(&bt,1);
	sd::BreadthFirstTraversalPreOrder(bt);
	cout<<std::endl;
	sd::GenNodeBinaryTree<int>(&bt,2);
	sd::BreadthFirstTraversalPreOrder(bt);
	cout<<std::endl;
	sd::GenNodeBinaryTree<int>(&bt,3);
	sd::BreadthFirstTraversalPreOrder(bt);
	cout<<std::endl;

	//custome code, replace when BT class is done
	sd::BTNode<char> *btc = new sd::BTNode<char>('F');
	sd::BTNode<char> *curr = btc;
	sd::BTNode<char> *prev = NULL;
	curr->left = new sd::BTNode<char>('B');
	curr = curr->left;
	curr->left = new sd::BTNode<char>('A');
	curr->right = new sd::BTNode<char>('D');
	curr = curr->right;
	curr->left = new sd::BTNode<char>('C');
	curr->right = new sd::BTNode<char>('E');
	curr = btc;
	curr->right = new sd::BTNode<char>('G');
	curr = curr->right;
	curr->right = new sd::BTNode<char>('I');
	curr = curr->right;
	curr->left = new sd::BTNode<char>('H');


	cout <<"Depth first Pre order"<< std::endl;
	sd::DepththFirstTraversal(btc);

	cout << "Depth first In order" << std::endl;
	sd::DepththFirstTraversalInOrder(btc);

	cout << "Depth first In order No recursion" << std::endl;
	sd::DepththFirstTraversalInOrderNR(btc);

	cout << "Depth first In order No recursion 2" << std::endl;
	sd::DepththFirstTraversalInOrderNR2(btc);

	cout << "Depth first Post order No recursion" << std::endl;
	sd::DepththFirstTraversalPostOrderNR(btc);
}

void testLargestCommonStr()
{
		std::string a = "cancabc";
		std::string b = "cabcan";
		std::string result;

		result = sd::longestCommonStr(a,b);
		cout<<result;
}

void compareDoublesTest()
{
	bool result = false;
	
	result = sd::number_utils::compare(3.502, 3.504, .0001);

	printDoubleResult(result);

	result = sd::number_utils::compare(3.50127, 3.50121, .0001);

	printDoubleResult(result);
}

void printDoubleResult(bool result)
{
	if(false == result)
	{
		cout<<"Doubles are NOT equal"<<std::endl;
	}
	else
	{
		cout<<"Doubles are equal"<<std::endl;
	}
}

bool single_digit(void * const& value) { return ((int)value<10); }

void testLinkedList()
{
	int elements[10] = { 10, 9, 8, 7, 16, 5, 3, 3, 12, 1 };
	int elements2[13] = { 8, 11, 10, 9, 8, 7, 16, 5, 3, 3, 12, 1, 8 };
	//int elements[2] = {2,1};
	int arraySize = sizeof(elements) / sizeof(int);
	int arraySize2 = sizeof(elements2) / sizeof(int);
	sd::LinkedList ll, ll2;

	for (int i = 0; i < arraySize; i++)
	{
		ll.push_back((void *)elements[i]);
	}

	cout << "Linked List Created: ";
	ll.print();
	cout << std::endl;

	for (int i = 0; i < arraySize2; i++)
	{
		ll2.push_front((void *)elements2[i]);
	}

	cout << "Linked List2 Created: ";
	ll2.print();
	cout << std::endl;

	ll2.remove((void*)8);
	cout << "LL2 removed 8s ";
	ll2.print();
	cout << std::endl;

	ll = ll2;
	cout << "L replaced with LL2: ";
	ll.print();
	cout << std::endl;

	ll.reverse();
	cout << "L reversed ";
	ll.print();
	cout << std::endl;

	ll.remove((void*)3);
	cout << "L removed 3s ";
	ll.print();
	cout << std::endl;

	ll.resize(20);
	cout << "L resized to 20 ";
	ll.print();
	cout << std::endl;

	ll.remove_if(single_digit);
	cout << "L single digits ";
	ll.print();
	cout << std::endl;

	ll.resize(10);
	cout << "L resized to 10 ";
	ll.print();
	cout << std::endl;

	class is_odd {
	public:
		bool operator() (void* const& value) { return ((int)value % 2) == 1; }
	};

	/*ll.remove_if<is_odd>(is_odd());
	cout << "L removed odds ";
	ll.print();
	cout << std::endl;*/

}

void testStack()
{
	int elements[10] = { 10, 9, 8, 7, 16, 5, 3, 3, 12, 1 };
	//int elements[1] = {1};
	//int elements[2] = {2,1};
	void * data;
	int arraySize = sizeof(elements) / sizeof(int);
	sd::Stack s;

	for (int i = 0; i < arraySize; i++)
	{
		s.push((void *)elements[i]);
	}

	cout << "Stack Created: ";
	s.print();
	cout << std::endl;

	data = s.top();
	cout << "Stack top is now: " << (int)data << std::endl;

	for (int j = 0; j < 4; j++)
	{
		s.pop();
	}
	cout << "Stack after being popped 4 times: ";
	s.print();

	data = s.top();
	cout << "Stack top is now: " << (int)data << std::endl;

	s.erase();

	cout << "Stack erased: ";
	s.print();

	data = s.top();
	cout << "Stack top is now: " << (int)data << std::endl;
}

void testStrings()
{  

    char hello[] = "HELLOOH";
    sd::ReverseString(hello);

    cout<< "HELL reversed = "<< hello <<std::endl;

    cout<< "unique:"<<sd::UniqueElements(hello)<<std::endl;
	
	cout << "Num of substrings:" << sd::substringCaculator(std::string("kincenvizh")) << std::endl;

	cout << sd::reverseStringNotWords("Reverse this string  please")<<std::endl;

	char test[] = "this string";
	std::string teststr = test;
	cout << "Reversing " << test << " =";
	sd::ReverseString(test);
	cout << test << std::endl;
	cout << "Reversing " << teststr << " =";
	sd::ReverseString(teststr);
	cout << teststr << std::endl;
}


void testSortinglist()
{
	std::list<std::string> test0, test1, test2, test3;
	std::list<std::string>::iterator it;

	//no elements
	test0.clear();

	//only one lement
	test1.push_back("one");

	//even number of elements
	test2.push_back("one");
	test2.push_back("two");
	test2.push_back("three");
	test2.push_back("four");

	//off number of elements
	test3.push_back("one");
	test3.push_back("4");
	test3.push_back("three");
	test3.push_back("1");
	test3.push_back("two");
	test3.push_back("3");
	test3.push_back("four");
	test3.push_back("3");
	test3.push_back("five");

	// Sort the std::list
	test0.sort();

	// Dump the std::list to check the result
	for (it = test0.begin();
		 it != test0.end(); ++it)
	{
		cout << "test0:" << *it<< std::endl;
	}

	// Sort the std::list
	test1.sort();

	// Dump the std::list to check the result
	for (it = test1.begin();
		 it != test1.end(); ++it)
	{
		cout << "test1:" << *it<< std::endl;
	}

}
