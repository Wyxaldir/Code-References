#include "Array List.h"
#include "Single Linked List.h"

void example01(); // array list example
void example02(); // linked list example

using namespace std;

int main()
{
	cout << "EXAMPLE01: ARRAY LIST\n\n";
	example01();
	cout << "\n\n";
	cout << "EXAMPLE02: SINGLE-LINKED LIST\n\n";
	example02();
	cout << "\n";

	system("pause");
	return 0;
}

void example01()
{
	arrayList al(50); // create a list with a size of 50

	cout << "Adding 1 through 5 to the list\n";

	al.insertLast(1);
	al.insertLast(2);
	al.insertLast(3);
	al.insertLast(4);
	al.insertLast(5); // add 1 2 3 4 5 to the list

	cout << "List: ";
	al.print();

	cout << "\nAdding 6 to the start of the list\n";
	
	al.insertFirst(6); // add 6 to the start, now it's 6 1 2 3 4 5
	
	cout << "List: ";
	al.print();

	cout << "\nAdding 7 to the 3rd slot in the list\n";

	al.insertAt(3, 7); // add 7 to the 3rd slot of the list
	
	cout << "List: ";
	al.print();

	cout << "\nRemoving the first and last items\n";

	al.removeFirst();
	al.removeLast();

	cout << "List: ";
	al.print();

	cout << "\nRemoving the second last element\n";

	al.removeSecondLast();

	cout << "List: ";
	al.print();

	cout << "\nDestroying list\n";

	al.destroyList();

	cout << "List: ";
	al.print();
}

void example02()
{
	singleLinkedList sLL;

	cout << "Insert 1 through 5 to the list\n";

	sLL.insertLast(1);
	sLL.insertLast(2);
	sLL.insertLast(3);
	sLL.insertLast(4);
	sLL.insertLast(5);

	cout << "List: ";
	sLL.print();

	cout << "\nInsert 6 at the start of the list\n";

	sLL.insertFirst(6);

	cout << "List: ";
	sLL.print();

	cout << "\nInsert 7 at the position 3 of the list\n";

	sLL.insertAt(3, 7);

	cout << "List: ";
	sLL.print();

	cout << "\nRemove the first and last elements of the list\n";

	sLL.removeFirst();
	sLL.removeLast();

	cout << "List: ";
	sLL.print();

	cout << "\nRemove the second last element of the list\n";

	sLL.removeSecondLast();

	cout << "List: ";
	sLL.print();

	cout << "\nDestroy List\n";

	sLL.destroyList();

	cout << "List: ";
	sLL.print();
}