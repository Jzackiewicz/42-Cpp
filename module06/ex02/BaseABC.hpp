#pragma once

#include <string>
#include <iostream>

class	Base
{
	public:
		virtual ~Base(void);
};

class A: public Base
{
	public:
		A(void);
		~A(void);
};

class B: public Base
{
	public:
		B(void);
		~B(void);
};

class C: public Base
{
	public:
		C(void);
		~C(void);
};

class D: public Base
{
	public:
		D(void);
		~D(void);
};

Base	*generate(void);
void	identify(Base* p);
void	identify(Base& p);