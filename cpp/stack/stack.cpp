#include <iostream>
#include "stack.hpp"

typedef Stack<int> stack;

std::ostream& operator<< (std::ostream& out, stack stk) {
	if (stk.is_empty()) {
		return out << "empty stack";
	}
	out << stk.top() << "\t<-- top of the stack";
	stk.pop();
	while (!stk.is_empty()) {
		out << '\n' << stk.top();
		stk.pop();
	}
	return out;
}

int main(void)
{
	stack stk;
	stk.push(1);
	stk.push(2);
	stk.push(3);
	std::cout << stk << std::endl;
	return 0;
}
