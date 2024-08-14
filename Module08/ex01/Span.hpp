#pragma once

#include <iostream>
#include <vector>
#include <iterator>

class Span
{
    public:
    	Span();
    	Span(unsigned int N);
    	Span(const Span &other);
    	~Span();
    public:
    	Span& operator =(const Span &other);
    public:
        void addNumber(int num);
	    int shortestSpan();
	    int longestSpan();
    private:
	    unsigned int N;
	    std::vector<int> arr;
};