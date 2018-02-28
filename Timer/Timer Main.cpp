#include <time.h>
#include <iostream>

using namespace std;

void example01(int); // put in a different int and see how long it takes 

int main()
{
	clock_t timer = clock();
	
	example01(10000); // anything higher than 

	int results = ((clock() - timer) / ((double)CLOCKS_PER_SEC)) * 1000;

	cout << "Time Taken: " << results << endl << endl;

	system("pause");
	return 0;
}

void example01(int n)
{
	long sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += i;
		for (int x = 0; x < n; x++)
			sum += x;
	}
}