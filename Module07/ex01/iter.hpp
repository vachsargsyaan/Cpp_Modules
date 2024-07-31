#pragma  once

#include <iostream>

template <typename T, typename U>
void iter( const T& array, size_t arrayLength,  const U& foo)
{
    for (size_t i = 0; i < arrayLength; i++)
        foo(array[i]);
}

template <typename T>
void printValue(const T& value) {
	std::cout << value << " ";
}