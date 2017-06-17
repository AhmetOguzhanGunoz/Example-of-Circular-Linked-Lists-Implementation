#pragma once
#ifndef H_CircularLinkedListType
#define H_CircularLinkedListType

#include <iostream>
#include<stdlib.h>

using namespace std;

//Definition of the node
template <class Type>
class nodeType
{
public:
	Type info;
	nodeType<Type> *link;
};

template <class Type>
class circularLinkedList
{
protected:

	int count; //variable to store the number of elements in the list
	nodeType<Type> *first; //pointer to the first node of the list

private:

	void copyList(const circularLinkedList<Type>& otherList);
	//Function to make a copy of otherList.

public:
	const circularLinkedList<Type>& operator=(const circularLinkedList<Type>&);
	//Overloads the assignment operator.
	void initializeList(); //Initializes the list to an empty state.
	bool isEmptyList(); //Function to determine whether the list is empty.
	void print() const;
	int length(); //Function to return the number of nodes in the list.
	void destroyList(); //Function to delete all the nodes from the list.
	Type front(); //Function to return the first element of the list.
	Type back(); //Function to return the last element of the list.
	bool search(const Type& searchItem);
	void insertNode(const Type& newitem);
	void deleteNode(const Type& deleteItem);//Function to delete deleteItem from the list
	circularLinkedList(); //Default constructor
	circularLinkedList(const circularLinkedList<Type>& otherList); //Copy constructor
	~circularLinkedList(); //Destructor
};

template <class Type>
circularLinkedList<Type>::circularLinkedList() //default constructor
{
	first = NULL;
	count = 0;
}

template <class Type>
circularLinkedList<Type>::~circularLinkedList()
{
	destroyList();
}

template <class Type>
void circularLinkedList<Type>::destroyList()
{
	nodeType<Type> *temp = first;

	while (first != NULL)
	{
		if (temp->link == first)
		{
			delete first;
			first = NULL;
			temp = NULL;
		}
		else
		{
			while (temp->link != first)
			{
				temp = temp->link;
				first->link = temp->link;
				delete temp;
				temp = first;
			}
		}
	}
	count = 0;
}


template <class Type>
void circularLinkedList<Type>::insertNode(const Type& newitem)
{
	nodeType<Type> *current, *newNode;

	newNode = new nodeType<Type>;
	newNode->info = newitem;
	newNode->link = NULL;

	if (first == NULL)
	{
		first = newNode;
		first->link = first;
		count++;
	}
	else
	{
		newNode->link = first;
		count++;
		current = first;
		while (current->link != first)
		{
			current = current->link;
		}

		current->link = newNode;
	}
}

template <class Type>
void circularLinkedList<Type>::print() const
{
	nodeType<Type> *current;
	int countTrail = 0;

	if (count == 0)
	{
		cout << "There is no info from empty list";
		cout << endl;
	}

	current = first;

	while (countTrail != count)
	{
		cout << current->info << " ";
		current = current->link;
		countTrail++;
	}
}


template <class Type>
bool circularLinkedList<Type>::isEmptyList()
{
	return (first == NULL);
}

template <class Type>
void circularLinkedList<Type>::initializeList()
{
	destroyList();
}


template <class Type>
int circularLinkedList<Type>::length()
{
	return count;
}

template <class Type>
Type circularLinkedList<Type>::front()
{
	if (first != NULL)
	{
		return first->info;
	}
	else
	{
		cout << "There is no front info from empty list";
		cout << endl;
		return NULL;
	}

}

template <class Type>
Type circularLinkedList<Type>::back()
{
	nodeType<Type> *current;
	current = first;
	int countTrail = 1;

	if (first == NULL)
	{
		cout << "There is no back info from empty list";
		cout << endl;
		return NULL;
	}
	else if (count == 1)
		return current->info;
	else
	{
		while (countTrail != count)
		{
			current = current->link;
			countTrail++;
		}
		return current->info;
	}
}

template <class Type>
bool circularLinkedList<Type>::search(const Type& searchItem)
{
	bool found = false;
	nodeType<Type> *current;
	current = first;

	if (first == NULL)
	{
		cout << "There can not be searching in empty list";
		cout << endl;
		return found;
	}
	else
	{
		do
		{
			if (current->info >= searchItem)
				found = true;
			else
				current = current->link;
		} while (current != first && !found);
	}

	return found;
}

template <class Type>
void circularLinkedList<Type>::deleteNode(const Type& deleteItem)
{
	nodeType<Type> *current, *trailCurrent;

	current = first;
	trailCurrent = first;

	if (first == NULL)
		cout << "Cannot delete from an empty list." << endl;
	else if(!(this->search(deleteItem)))
		cout << "Element is not in the list." << endl;
	else
	{
		if (trailCurrent->info == deleteItem)
		{
			while (current->link != first)
			{
				current = current->link;
			}
			first = trailCurrent->link;
			current->link = first;
			delete trailCurrent;
			trailCurrent = NULL;
			count--;
		}
		else
		{
			current = current->link;
			do
			{
				if (current->info == deleteItem)
				{
					trailCurrent->link = current->link;
					delete current;
					current = NULL;
					count--;
					break;
				}
				current = current->link;
				trailCurrent = trailCurrent->link;
			} while (current != first);
		}
	}
}


template <class Type>
void circularLinkedList<Type>::copyList(const circularLinkedList<Type>& otherList)
{
	nodeType<Type> *current;

	if (first != NULL)
		destroyList();

	if (otherList.first == NULL)
	{
		first = NULL;
		count = 0;
	}
	else
	{
		current = otherList.first;
		do
		{
			this->insertNode(current->info);
			current = current->link;
		}
		while (current != otherList.first);
	}
}

template <class Type>
circularLinkedList<Type>::circularLinkedList(const circularLinkedList<Type>& otherList)
{
	first = NULL;
	copyList(otherList);
}

template <class Type>
const circularLinkedList<Type>& circularLinkedList<Type>::operator=(const circularLinkedList<Type>& otherList)
{
	if (this != &otherList)
	{
		copyList(otherList);
	}

	return *this;
}

#endif