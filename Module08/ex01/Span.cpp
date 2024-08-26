#include "Span.hpp"

Span::Span()
{
	this->N = 0;	
}

Span::Span(unsigned int N)
{
	this->N = N;
}

Span::Span(const Span &other)
{
	this->N = other.N;
	this->arr = other.arr;
}

Span::~Span()
{}

Span& Span::operator =(const Span &other)
{
	if (this != &other)
	{
		this->N = other.N;
		this->arr = other.arr;
	}
	return *this;
}

void Span::addNumber(int num)
{
	if (this->arr.size() == this->N)
		throw std::runtime_error("Out of range");
	this->arr.push_back(num);
}

int Span::shortestSpan()
{
	if (this->arr.empty() || this->arr.size() <= 1)
		throw std::runtime_error("No span can be found");
	std::sort(this->arr.begin(), this->arr.end());
	std::vector<int>::iterator p2 = arr.begin() + 1;
	int min_span = INT_MAX;
	for (std::vector<int>::iterator p1 = arr.begin(); p1 < arr.end() && p2 < arr.end(); ++ p1, ++ p2)
		if (min_span > (*p2 - *p1))
			min_span = (*p2 - *p1);
	return min_span;
}

int Span::longestSpan()
{
	if (this->arr.empty() || this->arr.size() <= 1)
		throw std::runtime_error("No span can be found");
	std::vector<int>::iterator max;
	max = std::max_element(this->arr.begin(), this->arr.end());
	std::vector<int>::iterator min;
	min = std::min_element(this->arr.begin(), this->arr.end());
	return *max - *min;
}