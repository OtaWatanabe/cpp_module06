#include "ScalarConverter.hpp"

int	main(int argc, char *argv[]) {
	for (int i = 1; i < argc; ++i) {
		std::cout << argv[i] << std::endl;
		ScalarConverter::convert(std::string(argv[i]));
	}
}