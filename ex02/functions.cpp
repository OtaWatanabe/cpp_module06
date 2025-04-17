#include "functions.hpp"

Base * generate(void) {
	int r = std::rand() % 3;
	if (r == 0) return new A;
	if (r == 1) return new B;
	return new C;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) std::cout << "Class A" << std::endl;
	if (dynamic_cast<B*>(p)) std::cout << "Class B" << std::endl;
	if (dynamic_cast<C*>(p)) std::cout << "Class C" << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Class A" << std::endl;
	}
	catch (const std::bad_cast &e) {
		(void)e;
	}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Class B" << std::endl;
	}
	catch (const std::bad_cast &e) {
		(void)e;
	}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Class C" << std::endl;
	}
	catch (const std::bad_cast &e) {
		(void)e;
	}
}