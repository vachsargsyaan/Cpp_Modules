#pragma once

#include <cstdlib>
#include <ctime>
#include <iostream>

class Base
{
public:
	Base();
	virtual ~Base();
};

class A : public Base
{
public:
	A();
	~A();
};

class B : public Base
{
public:
	B();
	~B();
};

class C : public Base
{
public:
	C();
	~C();
};

Base* generate();
void identify(Base* p);
void identify(Base& p);
