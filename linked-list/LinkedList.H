#ifndef LinkedList_H
#define LinkedList_H

template <class T>
struct Node {
	T data;
	Node *next;
	Node(T);
};

template <class T>
Node<T>::Node(T item) {
	data = item;
	next = 0;
}

template <class T>
class LinkedList {
	Node<T> *head;
public:
	LinkedList();
	~LinkedList();
	void Insert(T, T);
	void Append(T);
	void Delete(T);
	void Display();
};

template <class T>
LinkedList<T>::LinkedList() {
	head = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
	Node<T> *ptr = head;
	while (ptr) {
		Node<T> *temp = ptr->next;
		delete ptr;
		ptr = temp;
	}
}

template <class T>
void LinkedList<T>::Append(T item) {
	Node<T> **ptr = &head;
	while (*ptr) {
		ptr = &(*ptr)->next;
	}
	*ptr = new Node<T>(item);
}

template <class T>
void LinkedList<T>::Display() {
	for (Node<T> *ptr = head; ptr; ptr = ptr->next) {
		std::cout << ptr->data << ", ";
	}
	std::cout << "\b\b  \b\b\n";
}

#endif /*LinkedList_H*/
