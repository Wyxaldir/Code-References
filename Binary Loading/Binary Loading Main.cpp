#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// We will store this in a file with binary.
struct testStruct
{
	std::vector<int> vec;
	int b;
	float c;
	std::string name;
};

// writing to file example
void example01();

// get the size of a data structure
int getSizeOfFile(std::string path);

// write the size of a data structure into a file
void writeSizeInFile(std::string path, int size);

// using templates to allow for any data type
template <typename c>
int getSizeOfObject(c data);

// use this to write things to a binary file
template <typename c>
void writeToFileBin(c data, std::string path);

void HWriteToFileBin(testStruct &data, std::string path);

// use this to get data from a binary file
template <typename c>
void readFromFileBin(c &data, std::string path);

int main()
{
	example01();

	return 0;
}


void example01()
{
	// == DATA DEFINITION == //

	// create data to store in file
	testStruct to_store;

	// struct to read from file into
	testStruct to_read;

	// assign values
	for (int i = 0; i < 500; i++)
		to_store.vec.push_back(i);
	to_store.b = 22; 
	to_store.c = 100.255;
	to_store.name = "Pierre-Luc Morin";

	// we will write this in the file
	testStruct testStructArray[1];
	testStructArray[0] = to_store;

	// we will read to this later.
	testStruct testStructArrayEMPTY[1];

	// == DATA DEFINITION END == // 
	//HWriteToFileBin(to_store, "test.bin");

	std::string to_save = "Hello World";

	writeToFileBin(to_save, "str.bin");

	std::string to_load;

	readFromFileBin(to_load, "str.bin");

	// the commented code below is the code in the function.

	// create the file pointer
	//FILE* fp;
	//
	//// open the file in write mode (binary)
	//fp = fopen("test.bin", "wb"); // wb = write binary
	//
	//// write the size of the object at the beginning of the file
	//int temp[1];
	//temp[0] = getSizeOfObject(to_store);
	//fwrite(temp, 4, 1, fp);
	//
	//// put the cursor after the data we just put in
	//fseek(fp, 4, 0);
	//
	//// Need to un-hardcode
	//fwrite(testStructArray, 48, 1, fp);
	//
	//// always close files
	//fclose(fp);
	//

	readFromFileBin(to_read, "test.bin");
}

int getSizeOfFile(std::string path)
{
	int intBuf[1];

	// define file pointer
	FILE* fp;
	// open file under read binary
	fp = fopen(path.c_str(), "rb");

	// load the first four bytes into an int
	// we always store the size in a single int, so we can just put 1
	fread(intBuf, sizeof *intBuf, 1, fp);

	// close file
	fclose(fp);

	// return result
	return intBuf[0];
}

// write the size of a data structure into a file
void writeSizeInFile(std::string path, int size)
{
	int buffer[1];
	buffer[0] = size;

	// create file pointer
	FILE* fp;

	// we're writing to file, so we'll use wb
	fp = fopen(path.c_str(), "wb");

	fwrite(buffer, sizeof *buffer, 1, fp);

	// always close files
	fclose(fp);
}

// using templates to allow for any data type
template <typename c>
int getSizeOfObject(c data) 
{
	return sizeof data;
}

template <typename c>
void writeToFileBin(c data, std::string path)
{
	// create a buffer
	c buffer[1];
	buffer[0] = data;

	// create the file pointer
	FILE* fp;

	// open the file in write mode (binary)
	fp = fopen(path.c_str(), "wb"); // wb = write binary

	// write the size of the object at the beginning of the file
	int temp[1];
	temp[0] = getSizeOfObject(data);
	fwrite(temp, 4, 1, fp);

	// put the cursor after the data we just put in
	fseek(fp, 4, 0);

	// Need to un-hardcode
	fwrite(buffer, sizeof *buffer, 1, fp);

	// always close files
	fclose(fp);
}

// hardcoded version of the code, for debugging.
void HWriteToFileBin(testStruct &data, std::string path)
{
	// == DATA DEFINITION == //

	// create data to store in file
	testStruct to_store;

	// struct to read from file into
	testStruct to_read;

	// assign values
	for (int i = 0; i < 500; i++)
		to_store.vec.push_back(i);
	to_store.b = 22;
	to_store.c = 100.255;
	to_store.name = "Pierre-Luc Morin";

	// we will write this in the file
	testStruct testStructArray[1];
	testStructArray[0] = to_store;

	// we will read to this later.
	testStruct testStructArrayEMPTY[1];

	// == DATA DEFINITION END == // 
	//HWriteToFileBin(to_store, "test.bin");

	// create the file pointer
	FILE* fp;
	
	// open the file in write mode (binary)
	fp = fopen("test.bin", "wb"); // wb = write binary
	
	// write the size of the object at the beginning of the file
	int temp[1];
	temp[0] = getSizeOfObject(to_store);
	fwrite(temp, 4, 1, fp);
	
	// put the cursor after the data we just put in
	fseek(fp, 4, 0);
	
	// Need to un-hardcode
	fwrite(testStructArray, 48, 1, fp);
	
	// always close files
	fclose(fp);
	
}

template <typename c>
void readFromFileBin(c &data, std::string path)
{
	c buffer[1];
	buffer[0] = data;

	FILE* fp;
	// reopen the file in read more (binary)
	fp = fopen(path.c_str(), "rb"); // rb = read binary

	int temp2[1];
	fread(temp2, 4, 1, fp);

	fseek(fp, 4, 0);

	fread(buffer, temp2[0], 1, fp);

	data = buffer[0];

	// close file.
	fclose(fp);
}