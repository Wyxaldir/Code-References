#include "Single Linked List.h"
#include <assert.h>

singleLinkedList::singleLinkedList()
{
	first = NULL;
	last = NULL;
	count = 0;
}

void singleLinkedList::insertFirst(const int& newItem)
{
	node *newNode; //pointer to create the new node

	newNode = new node; //create the new node

	assert(newNode != NULL);	//If unable to allocate memory, 
							    //terminate the program
	newNode->info = newItem; 	  //store the new item in the node
	newNode->link = first;        //insert newNode before first
	first = newNode;              //make first point to the actual first node
	count++; 				    //increment count

	if (last == NULL)   //if the list was empty, newNode is also 
						//the last node in the list
		last = newNode;
}

void singleLinkedList::insertLast(const int& newItem)
{
	node *newNode; //pointer to create the new node
	newNode = new node; //create the new node
	assert(newNode != NULL);	//If unable to allocate memory, terminate the program

	newNode->info = newItem;      //store the new item in the node
	newNode->link = NULL;         //set the link field of newNode to NULL
	if (first == NULL)	//if the list is empty, newNode is both the first and last node
	{
		first = newNode;
		last = newNode;
		count++;		//increment count
	}
	else			//the list is not empty, insert newNode after last
	{
		last->link = newNode; //insert newNode after last
		last = newNode;   //make last point to the actual last node
		count++;		//increment count
	}
}

void singleLinkedList::insertAt(int loc, const int& newItem)
{
	if (count == 0)
	{
		insertLast(newItem);
		return;
	}
	if (loc == 0)
		insertFirst(newItem);
	else if (loc == count+1)
		insertLast(newItem);
	else if (count > loc) // if user tries to insert outside of the list, no point in doing any of this
	{
		node *newNode; // pointer to create new node
		newNode = new node; // create said node
		assert(newNode != NULL); // make sure to have memory left

		newNode->info = newItem;
		newNode->link = NULL;

		node *linkNode; // creating node to navigate the nodes
		linkNode = new node;
		assert(linkNode != NULL); // make sure to have memory left
		
		linkNode->info = 0;
		linkNode->link = first;

		for (int i = 0; i < loc - 1; i++)
		{
			linkNode->link = linkNode->link->link;
		}

		newNode->link = linkNode->link->link;

		linkNode->link->link = newNode;

		count++;
	}
}

void singleLinkedList::destroyList()
{
	node *temp; 	//pointer to deallocate the memory 
					//occupied by the node
	while (first != NULL)   		 //while there are nodes in the list
	{
		temp = first;       	 //set temp to the current node
		first = first->link; 	//advance first to the next node
		delete temp;         	//deallocate memory occupied by temp
	}
	last = NULL;		//initialize last to NULL; first has already
						//been set to NULL by the while loop
	count = 0;
}

void singleLinkedList::removeFirst()
{
	node *temp; // create temp node
	temp = first; // make it the same as the first node
	first = first->link; // set the first node to be the second
	delete temp; // free memory from first 
	count--; // decrement count, as we have 1 less element now
}

void singleLinkedList::removeLast()
{
	node *travelNode;
	travelNode = new node;
	travelNode->link = first;

	count--;

	for (int i = 0; i < count - 1; i++)
	{
		travelNode->link = travelNode->link->link;
	}

	delete last;
	last = travelNode->link;
	last->link = NULL; // it's the last one so it does not have a link
}

void singleLinkedList::removeSecondLast()
{
	node *travelNode;
	travelNode = new node;
	travelNode->link = first;

	count--;

	for (int i = 0; i < count - 2; i++)
	{
		travelNode->link = travelNode->link->link;
	}

	delete travelNode->link->link;

	travelNode->link->link = last;
}

void singleLinkedList::print()
{
	if (first == NULL)
	{
		std::cout << "Empty\n";
		return;
	}
	node *linkNode; // creating node to navigate the nodes
	linkNode = new node;
	assert(linkNode != NULL); // make sure to have memory left

	linkNode->link = first;
	linkNode->info = linkNode->link->info;

	for (int i = 0; i < count; i++)
	{
		std::cout << linkNode->link->info << " ";
		linkNode->link = linkNode->link->link;
	}
	std::cout << std::endl;
}