#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750

int	subject() {
	Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

void	outOfRangeCheck() {
	Array<int> intArray(10);

	for (unsigned int i = 0; i < intArray.size(); ++i)
		intArray[i] = rand();
	try {
		intArray[-1] = 100;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		intArray[intArray.size()] = 5;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}

void	deepCopyCheck() {
	Array<Array<std::string> > strArr(3);
	for (unsigned int i = 0; i < strArr.size(); i++) {
		Array<std::string> arr(2);
		strArr[i] = arr;
		for (unsigned int j = 0; i < strArr[j].size(); j++)
			strArr[i][j] = "hi";
	}
	std::cout << strArr[0][0] << std::endl;

	Array<Array<std::string> > strArrayCopy(strArr);
	strArrayCopy[1][1] = "hi there";
	std::cout << strArrayCopy[1][1] << std::endl;
}

int main(int, char**) {
	std::cout << BLUE << "project page main.cpp" << RESET << std::endl;
	subject();
	std::cout << std::string(40, '-') << std::endl;
	std::cout  << BLUE << "out of range exception" << RESET << std::endl;
	outOfRangeCheck();
	std::cout << std::string(40, '-') << std::endl;
	std::cout << BLUE << "deep copy content test" << RESET << std::endl;
	deepCopyCheck();
}
