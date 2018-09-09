#include <iostream>
#include <string>

// substr will let us select a part of a string
// see the test functions below for more details

#pragma region forward declarations
std::string test01();
std::string test02();
std::string test03();
#pragma endregion

int main()
{
	std::cout << test03() << std::endl;

	system("pause");
	return 0;
}

// Explanation:
// substr(x,y)
// substr will return a string of length y, starting at x
// examples below

std::string test01()
{
	std::string outMsg = "This_is_a_test_message";
	return outMsg.substr(0, 4); // return "This"
}

std::string test02()
{
	std::string outMsg = "This_is_a_test_message";
	return outMsg.substr(5, 2); // return is
}

std::string test03()
{
	std::string outMsg = "This_is_a_test_message";
	return outMsg.substr(5); // return is_a_test_message
}

