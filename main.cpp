#include <iostream>
#include "Vector.h"
#include <string>

int main() {
	Vector<std::string> vec;
	vec.push_back("a");
	vec.push_back("b");
	vec.push_back("c");
	vec.push_back("d");
	vec.push_back("e");
	vec.push_back("f");
//	std::cout << vec.size();
	vec.print();
}
