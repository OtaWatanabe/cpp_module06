#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include "Data.hpp"

typedef unsigned long long uintptr_t;

class Serializer {
private:
	Serializer(void);
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif
