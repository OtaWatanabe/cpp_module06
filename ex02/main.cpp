#include "functions.hpp"

int main() {
	std::srand(0);
	for (int i = 0; i < 10; ++i) {
		Base	*base = generate();
		if (base == NULL) {
			std::cerr << "memory allocation error" << std::endl;
			return 0;
		}
		identify(base);
		identify(*base);
		delete base;
	}
	A a;
	B b;
	C c;
	Base *abase = &a;
	Base *bbase = &b;
	Base *cbase = &c;
	identify(abase);
	identify(bbase);
	identify(cbase);
	identify(static_cast<Base&>(a));
	identify(static_cast<Base&>(b));
	identify(static_cast<Base&>(c));
}