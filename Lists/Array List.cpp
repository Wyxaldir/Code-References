#include "Array List.h"
#include <iostream>

arrayList::arrayList(int maxSize)
{
	this->maxSize = maxSize;
	list = new int[maxSize];
	for (int i = 0; i < maxSize; i++) // initialize everything to 0
	{
		list[i] = 0;
	}
}

void arrayList::insertFirst(int newItem)
{
	if (length >= maxSize) // the list is full
		std::cerr << "Cannot insert in a full list." << std::endl;
	else
	{
		for (int i = length+1; i >= 0; i--)
		{
			list[i + 1] = list[i];
		} // shift all items by 1
		list[0] = newItem;
		length++; // increment length
	}
}

void arrayList::insertLast(int newItem)
{
	if (length >= maxSize)  //the list is full
		std::cerr << "Cannot insert in a full list." << std::endl;
	else
	{
		list[length] = newItem;	//insert the item at the end
		length++;	//increment length
	}
}

void arrayList::insertAt(int loc, const int newItem)
{
	if (length >= maxSize) // the list is full
		std::cerr << "Cannot insert in a full list." << std::endl;
	else if (loc < length)
	{
		for (int i = length - 1; i > loc - 1; i--)
		{
			list[i + 1] = list[i];
		} // shift all items by 1
		list[loc] = newItem;
		length++; // increment length
	}
	else
	{
		std::cerr << "cannot insert outside of list";
	}
}

void arrayList::removeFirst()
{
	for (int i = 1; i < length; i++) // shift all elements in the array by 1
	{
		list[i - 1] = list[i];
	}
	length--; // we deleted an element, so reduce lenght by 1
}

void arrayList::removeLast()
{
	list[length - 1] = NULL; // make the last element null
	length--; // reduce length
}

void arrayList::removeSecondLast()
{
	if (length > 1) // cannot remove second last if there is only 1 element
	{
		list[length - 2] = list[length - 1]; // make the second last element the same as the last

		removeLast(); // remove the last
	} // No need to reduce length, as removeLast will
}

void arrayList::destroyList() // remove all elements in the list
{
	int temp = length; // length is reduced each time we call this, 
	for (int i = 0; i < temp; i++)
		removeLast();
}

void arrayList::print() // utility function
{
	if (length == 0)
	{
		std::cout << "Empty\n";
		return;
	}

	for (int i = 0; i < length; i++)
	{
		std::cout << list[i] << " ";
	}
	std::cout << "\n";
}