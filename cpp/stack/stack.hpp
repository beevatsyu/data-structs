#ifndef	STACK_HPP
#define STACK_HPP

#include <stack>

template <class T>
class Stack {
	std::stack<T> stk;
	std::stack<T> aux;

public:
	T top();

	void push(T);

	void pop();

	bool is_empty();

	T min();
};

template <class T>
T Stack<T>::top() {
	return stk.top();
}

template <class T>
void Stack<T>::push(T item) {
	if (aux.empty() || item < aux.top()) {
		aux.push(item);
	}
	stk.push(item);
}

template <class T>
void Stack<T>::pop() {
	if (stk.top() == aux.top()) {
		aux.pop();
	}
	stk.pop();
}

template <class T>
bool Stack<T>::is_empty() {
	return stk.empty();
}

template <class T>
T Stack<T>::min() {
	return aux.top();
}

#endif
