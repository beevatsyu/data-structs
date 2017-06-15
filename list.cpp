#include <iostream>
#include "linked_list.hpp"

int main(int argc, const char *argv[])
{
	LinkedList<int> L1;
	L1.Append(2);
	L1.Append(5);
	L1.Append(3);
    L1.Delete(6);
	std::cout << L1;
	return 0;
}
