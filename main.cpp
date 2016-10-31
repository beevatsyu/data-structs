#include <iostream>
#include "LinkedList.H"

int main(int argc, const char *argv[])
{
	LinkedList<int> L1;
	L1.Append(2);
	L1.Append(5);
	L1.Append(3);
	L1.Display();
	return 0;
}
