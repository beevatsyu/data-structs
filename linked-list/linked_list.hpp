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
	void Append(T);
	void Insert(T, T);
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
void LinkedList<T>::Insert(T key, T item) {
	for (Node<T> *ptr = head; ptr; ptr = ptr->next) {
		if (ptr->data == key) {
			break;
		}
	}
	if (ptr) {
		Node<T> *node = new Node<T>(item);
		node->next = ptr->next;
		ptr->next = node;
		return;
	}
	std::cout << "WARNING: Insert key not found.\n";
}

template <class T>
void LinkedList<T>::Delete(T key) {
	
template <class T>
void LinkedList<T>::Display() {
	for (Node<T> *ptr = head; ptr; ptr = ptr->next) {
		std::cout << ptr->data << ", ";
	}
	std::cout << "\b\b  \b\b\n";
}

#endif /*LinkedList_H*/
