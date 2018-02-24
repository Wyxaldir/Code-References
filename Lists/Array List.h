#pragma once

class arrayList
{
public:
	// initializes list as empty
	arrayList(int maxSize);

	// Function to insert newItem at the start of the list
	void insertFirst(int newItem);

	// Function to insert newItem at the end of the list
	void insertLast(int newItem);

	// destroys the entire list
	void destroyList();

	// inserts newItem at given point in the list
	void insertAt(int loc, const int newItem);

	// remove the first item of the list
	void removeFirst();

	// remove the last item of the list
	void removeLast();

	// remove the second last item in the list
	void removeSecondLast();

	// test function
	void print();

protected:
	// array to hold the list of elements
	int *list;

	// stores the length of the array
	int length;

	// stores the maximum size of the list
	int maxSize;
};