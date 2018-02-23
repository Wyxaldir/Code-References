#include <iostream>
#include <vector>

using namespace std;

void example01();	// vector-based range loops
void example02();	// array-based range loops

int main()
{
	cout << "EXAMPLE 01: Vector-Based Range Loops\n\n";
	example01();

	cout << endl;

	cout << "EXAMPLE 02: Array-Based Range Loops\n\n";
	example02();

	system("pause");
	return 0;
}

void example01()
{
	vector<int> v = { 0,1,2,3,4,5 };
	for (const int& i : v) // access by const reference
		cout << i << " ";
	cout << endl;

	for (auto i : v) // access by value, the type of i is int
		cout << i << " ";
	cout << endl;

	for (auto&& i : v) // access by forwarding reference, the type of i is i&
		cout << i << " ";
	cout << endl;

	const auto& cv = v;

	for (auto &&i : cv) // access by f-d reference, the type of i is const int&
		cout << i << " ";
	cout << endl;
}

void example02()
{
	for (int n : {0, 1, 2, 3, 4, 5}) // the initializer may be a braced-init-list
		std::cout << n << ' ';
	std::cout << '\n';

	int a[] = { 0, 1, 2, 3, 4, 5 };
	for (int n : a) // the initializer may be an array
		std::cout << n << ' ';
	std::cout << '\n';

	for (int n : a)
		std::cout << 1 << ' '; // the loop variable need not be used
	std::cout << '\n';
}