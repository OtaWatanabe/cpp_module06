#include "Serializer.hpp"
#include <iostream>

int	main() {
	Data	data;
	Data	*dataptr;
	
	data.id = 1;
	data.name = "a";
	dataptr = Serializer::deserialize(Serializer::serialize(&data));
	std::cout << "id: "<< dataptr->id << "\nname: " << dataptr->name << std::endl;
}
