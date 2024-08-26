#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>


template <typename T>
int easyfinde(const T &array, const int num)
{
	typename T::const_iterator ptr = std::find(array.cbegin(), array.cend(), num);
	if (ptr == array.cend())
		throw std::runtime_error("Number not finde");
	return *ptr;
};
