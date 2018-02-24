#include <iostream>
#include <time.h>

#define MAX_SIZE 50

void example01(); // generic rand example

int main()
{
	example01();

	system("pause");
	return 0;
}

void example01()
{
	// create seed
	srand(time(NULL));

	// array that we will fill up
	int ar[MAX_SIZE];

	for (int i = 0; i < MAX_SIZE; i++)
		ar[i] = rand() % 100 + 5; // generates a number between 5 and 100
}