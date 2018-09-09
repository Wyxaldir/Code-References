// ======= INTRO ======= // 
// This is a bas look at macros based off of:
// http://www.cplusplus.com/doc/tutorial/preprocessor/
//
// For more in-depth info, please look at  
// https://gcc.gnu.org/onlinedocs/cpp/Macros.html

// to cout stuff
#include <iostream>

using namespace std;

// region example
#pragma region forward declarations
void test01();
void test02();
void test03();
void test04();
void test05();
void test06();
void test07();
void test08();
void test09();
#pragma endregion

// macros example
int main()
{
	test09();

#pragma region pause
	std::cout << std::endl;
	system("Pause");
#pragma endregion

}

// basic define test
#define TABLE_SIZE01 100
void test01()
{
	int ar[TABLE_SIZE01];
	std::cout << "Table size of ar is: " << TABLE_SIZE01 << endl;

	// define statements do not care about blocks. See v
	
	// just some while loop
	while (true)
	{
#define TABLE_SIZE01_2 200
		break;
	}

	// it is still defined and 200
	std::cout << "TABLE_SIZE01_2's value is :" << TABLE_SIZE01_2 << endl;
}

// function macro test
#define getmax(a,b) ((a)>(b)?(a):(b))
void test02()
{
	// getmax is now just like a function that returns the greater between a and b
	int i = 0;
	int b = 2;

	int c = getmax(i, b);
	std::cout << c << endl;
}

// undef test
void test03()
{
	// if you want to re-define something, you do not need to #undef it first
#define TEST03VAL 1
	std::cout << "TEST03VAL is: " << TEST03VAL << endl;

#define TEST03VAL 2
	// as you can see, it does change
	std::cout << "TEST03VAL is: " << TEST03VAL << endl;

#undef TEST03VAL 
#define TEST03VAL 2
	// it is now 2
	std::cout << "TEST03VAL is: " << TEST03VAL << endl;

}

// using # in a function macro is like taking in a string
void test04()
{
#define str(x) #x
	std::cout << str("using function macro") << std::endl;
}

// using ## will glue two parameters together without spaces
void test05()
{
#define glue(a,b) a ## b
	glue(c, out) << "using glue macro" << std::endl;
}

// conditional inclusion
void test06()
{
#ifdef TABLE_SIZE06
	char ar[TABLE_SIZE06];
#endif // remember the endif!

#define TABLE_SIZE06_2 100
#ifdef TABLE_SIZE06_2
	char ar2[TABLE_SIZE06_2];
#endif

	// the following are valid if statements
#ifndef TABLE_SIZE06
	std::cout << "TABLE_SIZE06 not defined!\n";
#elif TABLE_SIZE06_2 > 200
	std::cout << "TABLE_SIZE06_2 > 200\n";
#endif

// undefining something 
#undef TABLE_SIZE06_2
#ifdef TABLE_SIZE06_2
	std::cout << "Error undefining.\n";
#else
	std::cout << "Undefined TABLE_SIZE06_2\n";
#endif

// you can also use defined and !defined in if statement blocks
#define YESNO
#ifdef YESNO
	std::cout << "YESNO defined\n";
#elif !defined YESNO
	std::cout << "YESNO not defined!\n";
#endif
}

// custom error messages
void test07()
{
	// uncomment the below line to see the example
	// the error should pop up as normal, but under line 137/Error in test07
// #define EXAMPLE

#line 137 "Error in test07!"
#ifdef EXAMPLE
	int a? ;
#endif
}

// #error
void test08()
{
// undefine this to see the error
#define ERROR_

#ifndef ERROR_
#error WHERE IS MY ERROR DEF?
#endif
}

// predefined macros
void test09()
{
	std::cout << "This is the line number " << __LINE__;
	std::cout << " of file " << __FILE__ << ".\n";
	std::cout << "Its compilation began " << __DATE__;
	std::cout << " at " << __TIME__ << ".\n";
	std::cout << "The compiler gives a __cplusplus value of " << __cplusplus;
}