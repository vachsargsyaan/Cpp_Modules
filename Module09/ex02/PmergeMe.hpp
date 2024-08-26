#pragma once

# define _ERROR_ARG_ "Error: Invalid arguments."
# define _ERROR_EMPTY_ "Error: Empty arguments."
# define _ERROR_NEGATIVE_ "Error: Negative arguments."
# define _ERROR_OVERFLOW_ "Error: An overflowing argument."

# include <iostream>
# include <vector>
# include <deque>
# include <list>
# include <sstream>
# include <algorithm>
# include <climits>
# include <ctime>
# include <sys/time.h>

class PmergeMe
{
    public:
    	static void valid_args(int ac, char **av);
    	static void _PmergeMe_();
    public:
    	static std::deque<int> deq;
    	static std::vector<int> vect;
    private:
    	PmergeMe();
    	PmergeMe(const PmergeMe & other);
    	PmergeMe& operator=(const PmergeMe & other);
    	~PmergeMe();

    private:
    	static bool isPulusDigit(const std::string & arg);
    	static void fill_cont(const std::string& arg);
    	template <typename Cont>
    		static void RunSort(Cont& arr, const size_t size);
    	template <typename Cont>
    		static void BlockInsert(Cont& x, Cont& y);
    	template <typename Cont>
    		static int BlockSearch(const Cont& arr, const int val);
};
