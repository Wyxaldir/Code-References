#include <iostream>
#include <vector>

void example01();

using namespace std;

int main()
{
	cout << "EXAMPLE 01: Vector out of Range Handling\n\n";
	example01();

	system("pause");
	return 0;
}

void example01()
{
	// create a vector
	vector<int> vecInt;

	try {
		// vector is empty, this will create an error
		vecInt.at(10) = 0;
	}
	catch (const std::out_of_range orr)
	{
		// it would usually crash, but thanks to this here it will not.
		cout << "OUT OF RANGE" << orr.what() << endl;
	}
}