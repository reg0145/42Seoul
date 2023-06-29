#include <iostream>
#include "Data.hpp"

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

int main(void)
{
	Data dungeon = {"200 OK", "{\"dungeon_lvl\": \"2\", \"room\": \"1\", \"enemy\": \"1\", \"enemy_lvl\": \"2\", \"enemy_hp\": \"100\", \"enemy_dmg\": \"10\", \"enemy_armor\": \"5\", \"player_lvl\": \"6\",\"player_hp\": \"100\", \"player_dmg\": \"10\", \"player_armor\": \"5\"}"};

	Data *ptr = &dungeon;
	uintptr_t addr = serialize(ptr);
	Data *ptr2 = deserialize(addr);

	if (ptr == ptr2)
		std::cout << "Same address!\n" << std::endl;

	std::cout << "Address : " << addr << std::endl;
	std::cout << "Status  : " << ptr2->status << "\n" << ptr2->body << std::endl;
	return 0;
}

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}