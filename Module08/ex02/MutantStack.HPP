#include <iostream>
#include <stack>

template<typename T, class Container = std::deque<T> >
	class MutantStack : public std::stack<T, Container>
	{
	public:
		MutantStack(){}
		MutantStack(const MutantStack<T, Container> &other){ std::stack<T, Container>::operator=(other); }
		~MutantStack(){}
	public:
		MutantStack& operator= (const MutantStack<T, Container> &other)
		{
			if (this != &other)
			{ std::stack<T, Container>::operator=(other); }
			return *this; 
		}
	public:
		typedef typename std::stack<T, Container>::container_type::iterator iterator;
		typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T, Container>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T, Container>::container_type::const_reverse_iterator const_reverse_iterator;
		
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
		
		const_iterator cbegin() { return this->c.cbegin(); }
		const_iterator cend() { return this->c.cend(); }
		
		reverse_iterator rbegin() { return this->c.rbegin(); }
		reverse_iterator rend() { return this->c.rend(); }
		
		const_reverse_iterator crbegin() { return this->c.crbegin(); }
		const_reverse_iterator crend() { return this->c.crend(); }
	};
	