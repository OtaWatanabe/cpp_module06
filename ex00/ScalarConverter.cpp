#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

void	ScalarConverter::printMessage(const std::string& type, const std::string& msg) {
	std::cout << type << ": " << msg << std::endl;
}

void	ScalarConverter::printChar(char c) {
	std::cout << "char: '" << c << '\'' << std::endl;
}

void	ScalarConverter::printInt(int i) {
	std::cout << "int: " << i << std::endl;
}

void	ScalarConverter::printFloat(float f) {
	if (static_cast<float>(std::numeric_limits<int>::max() < f) ||
		(f < static_cast<float>(std::numeric_limits<int>::min())) ||
		static_cast<float>(static_cast<int>(f)) != f) {
		std::cout << "float: " << f << 'f' << std::endl;
		return ;
	}
	std::cout << "float: " << f << ".0f" << std::endl;
}

void	ScalarConverter::printDouble(double d) {
	if (static_cast<double>(std::numeric_limits<int>::max() < d) ||
		(d < static_cast<double>(std::numeric_limits<int>::min())) ||
		static_cast<double>(static_cast<int>(d)) != d) {
		std::cout << "double: " << d << std::endl;
		return ;
	}
	std::cout << "double: " << d << ".0" << std::endl;
}

void	ScalarConverter::convertInt(int i) {
	char	c;

	c = static_cast<char>(i);
	if (std::isprint(c)) printChar(c);
	else printMessage("char", "Non displayable");
	printInt(i);
	printFloat(static_cast<float>(i));
	printDouble(static_cast<double>(i));
}

void	ScalarConverter::convertFloat(float f) {
	char	c;
	int		i;

	if (static_cast<float>(std::numeric_limits<int>::max() < f) ||
		(f < static_cast<float>(std::numeric_limits<int>::min())) ||
		isnan(f)) {
		printMessage("char", "impossible");
		printMessage("int", "impossible");
	}
	else {
		i = static_cast<int>(f);
		c = static_cast<char>(i);
		if (std::isprint(c)) printChar(c);
		else printMessage("char", "Non displayable");
		printInt(i);
	}
	printFloat(f);
	printDouble(static_cast<double>(f));
}

void	ScalarConverter::convertDouble(double d) {
	int		i;
	char	c;

	if (static_cast<double>(std::numeric_limits<int>::max() < d) ||
		(d < static_cast<double>(std::numeric_limits<int>::min())) ||
		isnan(d)) {
		printMessage("char", "impossible");
		printMessage("int", "impossible");
	}
	else {
		i = static_cast<int>(d);
		c = static_cast<char>(i);
		if (std::isprint(c)) printChar(c);
		else printMessage("char", "Non displayable");
		printInt(i);
	}
	printFloat(static_cast<float>(d));
	printDouble(d);
}

void	ScalarConverter::convertChar(char c) {
	if (std::isprint(c)) printChar(c);
	else printMessage("char", "Non displayable");
	printInt(static_cast<int>(c));
	printFloat(static_cast<float>(c));
	printDouble(static_cast<double>(c));
}

void	ScalarConverter::convert(const std::string& input) {
	std::stringstream	ss(input);

	int	i;
	ss >> i;
	if (!ss.fail() && ss.eof()) {
		convertInt(i);
		return ;
	}
	ss.clear();
	ss.seekg(0);

	double	d;
	ss >> d;
	if (!ss.fail() && ss.eof()) {
		convertDouble(d);
		return ;
	}
	ss.str("");
	ss.clear();

	if (input[input.size()-1] == 'f') {
		ss << input.substr(0, input.size() - 1);
		float	f;
		ss >> f;
		if (!ss.fail() && ss.eof()) {
			convertFloat(f);
			return ;
		}
	}
	if (input.size() == 3 && input[0] == '\'' && input[2] == '\'') {
		convertChar(input[1]);
		return ;
	}
	printMessage("char", "impossible");
	printMessage("int", "impossible");
	printMessage("float", "impossible");
	printMessage("double", "impossible");
}
