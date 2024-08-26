#include "PmergeMe.hpp"

template <typename Cont>
	static void print_cont(const Cont& container)
	{
		typename Cont::const_iterator it;
		for (it = container.begin(); it != container.end(); ++ it)
		{
				std::cout << *it;
			if (it + 1 != container.end())
				std::cout << " ";
		}
		std::cout << std::endl;
	}

template <typename Cont>
	static bool is_sorted_cont(const Cont& container)
	{
		typename Cont::const_iterator it;
		for (it = container.begin(); it != container.end() - 1; ++ it)
		{
			if (*it > *(it + 1))
			{
				std::cout << *it << std::endl;
				return false;
			}
		}
		return true;
	}

std::deque<int> PmergeMe::deq;
std::vector<int> PmergeMe::vect;

PmergeMe::PmergeMe()
{ }

PmergeMe::PmergeMe(const PmergeMe & other)
{ (void)other; }

PmergeMe& PmergeMe::operator=(const PmergeMe & other)
{ (void)other; return *this; }

PmergeMe::~PmergeMe()
{ }

bool PmergeMe::isPulusDigit(const std::string & arg)
{
	std::string::const_iterator it = arg.begin();
	while (it != arg.end() && *it == ' ')
		it++;
	if (*it == '+')
		++it;
	while (it != arg.end())
	{
		if (*it == ' ')
			++ it;
		else if (*it < '0' || *it > '9')
			return false;
		else
			++ it;
	}
	return true;
}

void PmergeMe::valid_args(int ac, char **av)
{
	if (ac < 2)
			throw std::runtime_error(_ERROR_ARG_);
	for (int i = 1; av[i]; ++ i)
	{
		std::string arg(av[i]);
		if (arg.find('-', 0) != std::string::npos)
			throw std::runtime_error(_ERROR_NEGATIVE_);
		if (arg.empty())
			throw std::runtime_error(_ERROR_EMPTY_);
		if (!PmergeMe::isPulusDigit(arg))
			throw std::runtime_error(_ERROR_ARG_);
		try
		{
			PmergeMe::fill_cont(arg);
		}
		catch(...)
		{
			PmergeMe::vect.clear();
			PmergeMe::deq.clear();
			throw std::runtime_error(_ERROR_OVERFLOW_);
		}
	}
}
void PmergeMe::fill_cont(const std::string& arg)
{
	std::stringstream ss(arg);
    std::string token;
    while (std::getline(ss, token, ' '))
	{
		if (!token.empty())
		{
			if (std::strtoll(token.c_str(), NULL, 0) > INT_MAX)
				throw std::runtime_error("");
			PmergeMe::vect.push_back(std::atoi(token.c_str()));
			PmergeMe::deq.push_back(std::atoi(token.c_str()));
		}
    }
}

//////////////
/*	SORTING	*/
/////////////

template <typename Cont>
	void PmergeMe::RunSort(Cont& arr, const size_t size)
	{
		Cont	x;
		Cont 	y;

		size_t i = 0;
		if (size <= 2)
		{
			if (arr[0] > arr[1])
				std::swap(arr[0], arr[1]);
			return;
		}
		while (i + 1 < size)
		{
			if (arr[i] < arr[i + 1])
			{
				x.push_back(arr[i]);
				y.push_back(arr[i + 1]);
			}
			else
			{
				x.push_back(arr[i + 1]);
				y.push_back(arr[i]);
			}
			i += 2;
		}
		if (i < size)
			y.push_back(arr[i]);

		PmergeMe::RunSort(x, x.size());
		PmergeMe::BlockInsert(x, y);
		arr = x;
	}

template <typename Cont>
	void PmergeMe::BlockInsert(Cont& x, Cont& y)
	{
		size_t Y_Size = y.size();
		size_t i = 0;

		int val = 0;
		while (i < Y_Size)
		{
			val = PmergeMe::BlockSearch(x,y[i]);
			x.insert(x.begin() + val, y[i]);
			i++;
		}
	}

template <typename Cont>
	int PmergeMe::BlockSearch(const Cont& arr, const int val)
	{
		int low = 0;
		int MidIndex = low;
		int high = arr.size() - 1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			
			if (arr[mid] == val)
				return mid;
			if (arr[mid] < val)
			{
				low = mid + 1;
				MidIndex = low;
			}
			else
			{
				high = mid - 1;
				MidIndex = mid;
			}
		}
		// return MidIndex == 0 ? 0 : MidIndex == static_cast<int>(arr.size()) ? arr.size() : MidIndex;
			if (MidIndex == 0)
			return 0;
		// If value is greater than all elements, return the last index
		else if (MidIndex == static_cast<int>(arr.size()))
			return arr.size();
		else
			return MidIndex;
}


void PmergeMe::_PmergeMe_()
{
	/* VECTOR SORT TIME */
	std::cout << "Before: ";
	::print_cont(PmergeMe::vect);
	std::clock_t vstart = std::clock();
	if (PmergeMe::vect.size() > 1)
		PmergeMe::RunSort(PmergeMe::vect, PmergeMe::vect.size());
	std::clock_t vend = std::clock();


	/* DEQUE SORT TIME */
	std::clock_t dstart = std::clock();
	if (PmergeMe::deq.size() > 1)
		PmergeMe::RunSort(PmergeMe::deq, PmergeMe::deq.size());
	std::clock_t dend = std::clock();
	double VectorMicroSec = static_cast<double>(vend - vstart) / CLOCKS_PER_SEC * 1e6;
	double DequeMicroSec = static_cast<double>(dend - dstart) / CLOCKS_PER_SEC * 1e6;
	if (::is_sorted_cont(PmergeMe::vect) && ::is_sorted_cont(PmergeMe::deq))
	{
		std::cout << "After:  ";
		::print_cont(PmergeMe::vect);
		std::cout << "Time to process a range of " << PmergeMe::vect.size();
		std::cout << " elements with PmergeMe::vect : " << VectorMicroSec << " us" <<  std::endl;

		std::cout << "Time to process a range of " << PmergeMe::deq.size();
		std::cout << " elements with PmergeMe::deq : " << DequeMicroSec << " us" << std::endl;
	}
}