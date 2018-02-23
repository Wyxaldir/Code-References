#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

const unsigned int SIZE = 7;
const unsigned int numPeople = 4;
struct Person;

void example01(); // basic  array  example
void example02(); // basic  vector example
void example03(); // string vector example
void example04(); // using the third parameter
void example05(); // complex types sorting
void example06(); // exception handling

				  // sorting fuctions
				  // remember, always needs to return a bool!
bool descendingOrder(int i, int j); // will make the sort sort in descending order ( 10, 7 , 3 , 1, -4 )
bool sortByName(const Person &lhs, const Person &rhs);
bool sortByAge(const Person &lhs, const Person &rhs);
bool sortByColor(const Person &lhs, const Person &rhs);

struct Person {
	string name;
	int age;
	string favoriteColor;
};

int main()
{
	cout << "EXAMPLE 01 - array sort\n";
	example01();

	cout << "\n\nEXAMPLE 02 - vector sort\n";
	example02();

	cout << "\n\nEXAMPLE 03 - string vector sort\n";
	example03();

	cout << "\n\nEXAMPLE 04 - defined sort\n";
	example04();

	cout << "\n\nEXAMPLE 05 - struct sort(s)\n";
	example05();

	cout << "\n\nEXAMPLE 06 - Exception Handling\n";
	example06();

	cout << "\n\n\n";
	system("pause");
	return 0;
}

void example01()
{
	int intArray[SIZE] = { 5,3,32,-1,1,104,53 };

	sort(intArray, intArray + SIZE);

	for (size_t i = 0; i != SIZE; ++i)
		cout << intArray[i] << " ";
}

void example02()
{
	vector<int> vecInt;
	vecInt.push_back(1);
	vecInt.push_back(55);
	vecInt.push_back(10);
	vecInt.push_back(2);
	vecInt.push_back(-1);
	vecInt.push_back(23);

	sort(vecInt.begin(), vecInt.end());

	for (int i = 0; i < vecInt.size(); i++)
		cout << vecInt[i] << " ";
}

void example03()
{
	vector<string> stringVec = { "John", "Bob", "Joe", "Zack", "Randy" };

	sort(stringVec.begin(), stringVec.end());

	for (string &s : stringVec)
		cout << s.c_str() << " ";
}

void example04()
{
	vector<int> intVec = { 56, 32, -43, 23, 12, 93, 132, -154 };

	sort(intVec.begin(), intVec.end(), descendingOrder);

	for (int i : intVec)
		cout << i << " ";
}

void example05()
{
	// Make a vector of numPeople size
	vector<Person> people(numPeople);

	// define people
	people[0].name = "John";
	people[0].age = 32;
	people[0].favoriteColor = "Red";
	people[1].name = "Jack";
	people[1].age = 12;
	people[1].favoriteColor = "Blue";
	people[2].name = "Joe";
	people[2].age = 1;
	people[2].favoriteColor = "Blue";
	people[3].name = "Bob";
	people[3].age = 2;
	people[3].favoriteColor = "Green";

	// Sort by name
	sort(people.begin(), people.end(), sortByName);
	for (Person &n : people)
		cout << n.name.c_str() << " ";

	cout << endl;

	sort(people.begin(), people.end(), sortByAge);
	for (Person &n : people)
		cout << n.age << " ";

	cout << endl;

	sort(people.begin(), people.end(), sortByColor);
	for (Person &n : people)
		cout << n.favoriteColor.c_str() << " ";

	cout << endl;
}

void example06()
{
	vector<int> vecInt;
	try {
		vecInt.at(10) = 0;
	}
	catch (const std::out_of_range orr)
	{
		cout << "OUT OF RANGE" << orr.what() << endl;
	}

}

bool descendingOrder(int i, int j)
{
	return i > j;
}

bool sortByName(const Person &lhs, const Person &rhs)
{
	return lhs.name < rhs.name;
}

bool sortByAge(const Person &lhs, const Person &rhs)
{
	return lhs.age < rhs.age;
}

bool sortByColor(const Person &lhs, const Person &rhs)
{
	return lhs.favoriteColor < rhs.favoriteColor;
}