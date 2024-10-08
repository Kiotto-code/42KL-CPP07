#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "Array.hpp"

#define MAX_VAL 750
int fundamental_test(void)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
		std::cout << LIGHT_GREEN"numbers[" << std::setw(3) <<  i << "] = " << std::setw(20) <<  numbers[i] << " | ";
		std::cout << LIGHT_YELLOW"mirror[" << std::setw(3) << i << "] = " << std::setw(20) <<  mirror[i] << std::endl;
		std::cout << RESET;
        if (mirror[i] != numbers[i])
        {
            std::cerr << "the value different!" << std::endl;
            return 1;
        }
    }
    std::cout << ("OK, The value is the same\n") << std::endl;
    try
    {
        numbers[-1] = 0;
        std::cout << ("wrong success\n");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
        std::cout << ("wrong success\n");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    std::cout << ("array modified Success\n");
    delete [] mirror;//
	cterm();
	system("leaks a.out");
    return 0;
}

void emptyArrayLeaksTest()
{
    // int *arr = new int[0];
    Array<int> *arr = new Array<int>();
    (void)arr;
    delete arr;
}

int main(void)
{
	fundamental_test();
	cterm();
    {
        TEST_TITLE("Test 0: Empty array");
        TEST_DESC("Creates an empty array using default constructor.");
        TEST_DESC_CONT("Accessing an empty array is an undefined behavior.");
        TEST_NL();

        Array<int> intArr;
        int intArrReal[0];
        TEST_DESC_CONT("Try accessing intArr and intArrReal");
        try
        {
            std::cout << "intArr[0]: " << intArr[0] << std::endl;
        }
        catch (const std::exception &ex)
        {
            std::cout << ex.what() << std::endl;
        }
        std::cout << "intArrReal[0]: " << intArrReal[0] << std::endl;
        TEST_NL();

        Array<float> floArr;
        float floArrReal[0];
        TEST_DESC_CONT("Try accessing floArr and floArrReal");
        try
        {
            std::cout << "floArr[0]: " << floArr[0] << std::endl;
        }
        catch (const std::exception &ex)
        {
            std::cout << ex.what() << std::endl;
        }
        std::cout << "floArrReal[0]: " << floArrReal[0] << std::endl;
        TEST_NL();

        Array<double> douArr;
        double douArrReal[0];
        TEST_DESC_CONT("Try accessing douArr and douArrReal");
        try
        {
            std::cout << "douArr[0]: " << douArr[0] << std::endl;
        }
        catch (const std::exception &ex)
        {
            std::cout << ex.what() << std::endl;
        }
        std::cout << "douArrReal[0]: " << douArrReal[0] << std::endl;
        TEST_NL();

        Array<bool> boolArr;
        bool boolArrReal[0];
        TEST_DESC_CONT("Try accessing boolArr and boolArrReal");
        try
        {
            std::cout << "boolArr[0]: " << boolArr[0] << std::endl;
        }
        catch (const std::exception &ex)
        {
            std::cout << ex.what() << std::endl;
        }
        std::cout << "boolArrReal[0]: " << boolArrReal[0] << std::endl;
        TEST_NL();

        Array<std::string> strArr;
        std::string strArrReal[0];
        TEST_DESC_CONT("Try accessing strArr and strArrReal");
        try
        {
            std::cout << "strArr[0]: " << strArr[0] << std::endl;
        }
        catch (const std::exception &ex)
        {
            std::cout << ex.what() << std::endl;
        }
        std::cout << "strArrReal[0]: " << strArrReal[0] << std::endl;
        TEST_NL();

        emptyArrayLeaksTest();

        TEST_NL();
        TEST_LEAKS(0);
    }
    {
        TEST_TITLE("Test 1: Copy constructor - Deep copy");
        TEST_DESC("Check if deep copy is performed in copy constructor");
        TEST_NL();
        
        TEST_DESC_CONT("Create an array named 'arr' with 5 elements");
        Array<int> arr(5);
        for (int i = 0; i < 5; i++)
        {
            arr[i] = i + 3;
            std::cout << "arr[" << i << "]: " << arr[i] << std::endl;
        }
        TEST_NL();

        TEST_DESC_CONT("Copy an array named 'copy' with 'arr' as its source");
        Array<int> copy(arr);
        TEST_NL();

        TEST_DESC_CONT("Modified arr[1] to 625, arr[4] to 2000");
        arr[1] = 625;
        arr[4] = 2000;
        TEST_NL();

        TEST_DESC_CONT("arr should be updated. copy should remain the same. (proof of deep copy)");
        for (int i = 0; i < 5; i++)
            std::cout << "arr[" << i << "]: " << std::setw(5) << arr[i] << " | copy[" << i << "]: " << std::setw(5) << copy[i] << std::endl;
        TEST_LEAKS(1);
    }
    {
        TEST_TITLE("Test 2: Assignment operator - Deep copy");
        TEST_DESC("Check if deep copy is perform in assignment operator");
        TEST_NL();

        TEST_DESC_CONT("Create an array named 'arr' with 5 elements");
        Array<int> arr(5);
        for (int i = 0; i < 5; i++)
        {
            arr[i] = i + 3;
            std::cout << "arr[" << i << "]: " << arr[i] << std::endl;
        }
        TEST_NL();

        TEST_DESC_CONT("Create an array named 'yooo' with 5 elements");
        Array<int> yooo(5);
        for (int i = 0; i < 5; i++)
        {
            yooo[i] = i + 10;
            std::cout << "arr[" << i << "]: " << yooo[i] << std::endl;
        }
        TEST_NL();

        TEST_DESC_CONT("Print them out");
        for (int i = 0; i < 5; i++)
            std::cout << "arr[" << i << "]: " << std::setw(5) << arr[i] << " | yooo[" << i << "]: " << std::setw(5) << yooo[i] << std::endl;
        TEST_NL();

        TEST_DESC_CONT("Assign arr to yooo");
        yooo = arr;
        TEST_NL();
        
        TEST_DESC_CONT("Print them out again");
        for (int i = 0; i < 5; i++)
            std::cout << "arr[" << i << "]: " << std::setw(5) << arr[i] << " | yooo[" << i << "]: " << std::setw(5) << yooo[i] << std::endl;
        
        TEST_DESC_CONT("Modify arr[2] to 65 arr[3] to 300");
        arr[2] = 65;
        arr[3] = 300;
        TEST_DESC_CONT("arr should be updated. yooo should remain the same. (proof of deep copy)");
        for (int i = 0; i < 5; i++)
            std::cout << "arr[" << i << "]: " << std::setw(5) << arr[i] << " | yooo[" << i << "]: " << std::setw(5) << yooo[i] << std::endl;
        TEST_LEAKS(2);
    }
    {
        TEST_TITLE("Test 3: Size member function");
        TEST_DESC("Test if size() is working");
        TEST_NL();

        Array<int> empty;
        Array<std::string> five(5);
        Array<double> hundred(100);
        Array<float> negative(-100);

        std::cout << "size of empty: " << empty.size() << std::endl;
        std::cout << "size of five: " << five.size() << std::endl;
        std::cout << "size of hundred: " << hundred.size() << std::endl;
        std::cout << "size of negative: " << negative.size() << std::endl;
    }
}