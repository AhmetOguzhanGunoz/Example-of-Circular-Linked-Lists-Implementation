#include <iostream>
#include "circularLinkedLists.h"

using namespace std;

int main()
{
	int num;

	cout << "Creating list1 with default contstructor(Default Constructor Testing)" << endl;
	cout << endl;

	circularLinkedList<int> list1;

	cout << "After creation list1" << endl;
	cout << endl;

	cout << "list1(printNoValueTesting):";
	list1.print();
	cout << endl;

	
	cout << "Enter integers ending with -999" << endl; 
	cin >> num;

	while (num != -999)
	{
		list1.insertNode(num);
		cout << "list1 (InsertNodeTesting)" << endl;
		cin >> num;
	}

	cout << endl;

	cout << "list1(printWithValueTesting): "; 
	list1.print(); 
	cout << endl;
	cout << endl;


	cout << "Length of list1(lengthTesting): ";
	cout << list1.length();
	cout << endl;
	cout << endl;


	cout << "List1(frontInfoTesting):";
	cout << list1.front();
	cout << endl;
	cout << endl;


	cout << "List1(backInfoTesting):";
	cout << list1.back();
	cout << endl;
	cout << endl;



	if (list1.isEmptyList())
	{
		cout << "list1 is empty(isEmptyTested)" << endl;
		cout << endl;

	}
	else
	{
		cout << "list1 is not empty(isEmptyTested)" << endl;
		cout << endl;

	}

	cout << "Creating list2 with copy contstructor(Copy Constructor Testing)" << endl;
	cout << endl;

	circularLinkedList<int> list2(list1);

	cout << "After creation list2" << endl;
	cout << endl;
	cout << endl;

	if (list2.isEmptyList())
	{
		cout << "list2 is empty(isEmptyTested & copy constructor tested)" << endl;
		cout << endl;

	}
	else
	{
		cout << "list2 is not empty(isEmptyTested & copy constructor tested)" << endl;
		cout << endl;

	}

	cout << "list2(printWithValueTesting): ";
	list2.print();
	cout << endl;
	cout << endl;


	cout << "Length of list2(lengthTesting): ";
	cout << list2.length();
	cout << endl;
	cout << endl;


	cout << "List2(frontInfoTesting):";
	cout << list2.front();
	cout << endl;
	cout << endl;


	cout << "List2(backInfoTesting):";
	cout << list2.back();
	cout << endl;
	cout << endl;



	cout << "List1 prepared to be destroy(Destructor & InitializeList & destroyList Testing)";
	list1.destroyList();
	cout << endl;
	cout << endl;


	cout << "After destroying list1 is:";
	list1.print();
	cout << endl;

	cout << "Enter a number to search in list1 & list2";
	cout << endl;
	cin >> num;
	
	if (list1.search(num))
	{
		cout << "Element is existed in list1 " << num;
		cout << endl;
	}
	else
	{
		cout << "Element is not existed in list1 " << num;
		cout << endl;
	}

	if (list2.search(num))
	{
		cout << "Element is existed in list2 " << num;
		cout << endl;
	}
	else
	{
		cout << "Element is not existed in list2 " << num;
		cout << endl;
	}

	cout << "Enter a number to delete in list1 & list2";
	cout << endl;
	cin >> num;

	list1.deleteNode(num);
	list2.deleteNode(num);

	cout << endl;

	cout << "After deletion from list 2 becomes:";
	list2.print();
	cout << endl;
	cout << endl;


	cout << "Creating list 3 with operator = (Copy List Function & Operator = Overload Testing)";
	cout << endl;
	cout << endl;

	circularLinkedList<int> list3;
	list3 = list2;

	cout << "After creation list 3 becomes:";
	cout << endl;
	cout << "list3(printWithValueTesting): ";
	list3.print();
	cout << endl;
	cout << endl;


	cout << "Length of list3(lengthTesting): ";
	cout << list3.length();
	cout << endl;
	cout << endl;


	cout << "List3(frontInfoTesting):";
	cout << list3.front();
	cout << endl;
	cout << endl;


	cout << "List3(backInfoTesting):";
	cout << list3.back();
	cout << endl;
	cout << endl;
	system("pause");

	return 0;
}



