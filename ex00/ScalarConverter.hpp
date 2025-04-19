#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <string>
# include <sstream>
# include <iostream>
# include <cctype>
# include <limits>

class ScalarConverter {
private:
	ScalarConverter();
	static void	convertInt(int i);
	static void	convertDouble(double d);
	static void	printMessage(const std::string& type, const std::string& msg);
	static void	printInt(int i);
	static void	printFloat(float f);
	static void	printDouble(double d);
	static void	printChar(char c);
public:
	static void	convert(const std::string& input);
};

#endif
