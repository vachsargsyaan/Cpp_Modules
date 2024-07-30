#include "Base.hpp"

Base::Base(){}
Base::~Base(){}

A::A(){}
A::~A(){}

B::B(){}
B::~B(){}

C::C(){}
C::~C(){}

Base* generate()
{
	int randomClass = 'A' + std::rand() % ('C' - 'A' + 1);
	if (static_cast<char>(randomClass) == 'A')
	{
		A *ptr = new A;
		return dynamic_cast<Base*>(ptr);
	}
	if (static_cast<char>(randomClass) == 'B')
	{
		B *ptr = new B;
		return dynamic_cast<Base*>(ptr);
	}
	if (static_cast<char>(randomClass) == 'C')
	{
		C *ptr = new C;
		return dynamic_cast<Base*>(ptr);
	}
	return NULL;
}

void identify(Base* p)
{
    
	A *objA = dynamic_cast<A*>(p);
	B *objB = dynamic_cast<B*>(p);
	C *objC = dynamic_cast<C*>(p);
	if (objA)
		std::cout << "The actual type of the object pointed to by p: A" << std::endl;
	else if (objB)
		std::cout << "The actual type of the object pointed to by p: B" << std::endl;
	else if (objC)
		std::cout << "The actual type of the object pointed to by p: C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A &objA = dynamic_cast<A&>(p);
		(void)objA;
		std::cout << "The actual type of the object that p refers to: A" << std::endl;
	}
	catch(...)
	{
		try
		{
			B &objB = dynamic_cast<B&>(p);
			(void)objB;
			std::cout << "The actual type of the object that p refers to: B" << std::endl;
		}
		catch(...)
		{
			try
			{
				C &objC = dynamic_cast<C&>(p);
				(void)objC;
				std::cout << "The actual type of the object that p refers to: C" << std::endl;
			}
			catch(...)
			{}
		}
	}
}