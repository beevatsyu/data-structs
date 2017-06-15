#ifndef LinkedList_H
#define LinkedList_H

template<class T>
class LinkedList {
    struct Node {
        T data;
        Node *next;

        Node(T item) {
            data = item;
            next = 0;
        }
    } *head;

public:
    LinkedList();

    ~LinkedList();

    void Append(T);

    void Delete(T);

    template<class U> friend
    std::ostream &operator<<(std::ostream &, const LinkedList<U> &);
};

template<class T>
LinkedList<T>::LinkedList() {
    head = 0;
}

template<class T>
LinkedList<T>::~LinkedList() {
    Node *ptr = head;
    while (ptr) {
        Node *temp = ptr->next;
        delete ptr;
        ptr = temp;
    }
}

template<class T>
void LinkedList<T>::Append(T item) {
    Node **ptr = &head;
    while (*ptr) {
        ptr = &(*ptr)->next;
    }
    *ptr = new Node(item);
}

template<class T>
void LinkedList<T>::Delete(T key) {
    Node **ptr = &head;
    while (*ptr && (*ptr)->data != key) {
        ptr = &(*ptr)->next;
    }
    if (*ptr) {
        Node *temp = *ptr;
        *ptr = (*ptr)->next;
        delete temp;
    }
}

template<class T>
std::ostream& operator<<(std::ostream& out, const LinkedList<T>& list) {
    out << list.head->data;
    for (typename LinkedList<T>::Node *ptr = list.head->next; ptr; ptr = ptr->next) {
        out << " -> " << ptr->data;
    }
    return out << '\n';
}

#endif /*LinkedList_H*/
