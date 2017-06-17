#include <iostream>
#include <stack>
#include "binary_tree.hpp" 

int main()
{
	Tree<int> bst;
	bst.Insert(5);
	bst.Insert(1);
	bst.Insert(7);
	bst.Insert(3);
	bst.Display();
	std::cout << "======" << std::endl;
	bst.Delete(1);
	bst.Delete(5);
	bst.Display();
	return 0;
}
