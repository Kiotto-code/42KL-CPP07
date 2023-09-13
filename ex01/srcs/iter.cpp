#include "iter.hpp"
#include <iostream>

void upperStr (std::string &word)
{
	for (size_t i = 0; i < word.size(); i++)
		word[i] = std::toupper(word[i]);
}

void testString (void)
{
	std::string arr[] = {"Thor", "Zeus", "Jupyter"};
	size_t arrLen = sizeof(arr) / sizeof(arr[0]);
	iter(arr, arrLen, upperStr);
	for (size_t i = 0; i < arrLen; i++)
		std::cout << "Output :" << arr[i] << std::endl;
}

void numIncre (int &num)
{
	num++;
}

void testNum (void)
{
	int num[] = {5,6,7,8,9};
	size_t arrLen = sizeof(num) / sizeof(num[0]);
	iter(num, arrLen, numIncre);
	for (size_t i = 0; i < arrLen; i++)
		std::cout << "Output :" << num[i] << std::endl;
}

int main()
{
	std::cout << "testString" << std::endl;
	testString();
	std::cout << std::endl;
	std::cout << "testNum" << std::endl;
	testNum();
	return 0;
}