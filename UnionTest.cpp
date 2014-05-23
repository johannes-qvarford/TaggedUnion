#include <iostream>
#include "TaggedUnion.h"

int main() {
	using namespace tut;

	std::cout << "creating tagged union<int, char, short> tu" << std::endl;
	TaggedUnion<int, char, short> tu;
	std::cout << "initial tag is " << tu.getTag() << std::endl;
	std::cout << "t.set<2>(short(10))" << std::endl; 
	tu.set<2>(short(10));
	std::cout << "t.set<0>(20)" << std::endl;
	tu.set<0>(20);
	std::cout << "i = tu.get<0>()" << std::endl;
	int i = tu.get<0>();
	std::cout << "i is " << i << std::endl;
	std::cout << "i = tu.getFirstOfType<int>()" << std::endl;
	i = tu.getFirstOfType<int>();
	std::cout << "i is " << i << std::endl;
	std::cout << "about to call i.get<1>()" << std::endl;
	char c = tu.get<1>();
	std::cout << "c is " << c << std::endl;
	return 0;
}
