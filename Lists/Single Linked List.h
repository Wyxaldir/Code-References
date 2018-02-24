#pragma once
#include <iostream>

struct node
{
	int info;
	node *link;
};

class singleLinkedList
{
public:
	// Constructor, initializes list as empty
	singleLinkedList();

	// Inserts item at the start of the list
	void insertFirst(const int& newItem);

	// Inserts item at the end of the list
	void insertLast(const int& newItem);

	// destroys the entire list
	void destroyList();

	// inserts newItem at a given location
	void insertAt(int loc, const int& newItem);

	// removes the first element in the list
	void removeFirst();

	// removes the last element in the list
	void removeLast();

	// removes the second last item it the list
	void removeSecondLast();

	// test function
	void print();
protected:
	// variable to store the amount of elements in the list
	int count;

	// pointer to first node 
	node *first;

	// pointer to last node
	node *last;
};