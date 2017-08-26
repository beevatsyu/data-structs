#ifndef TREE_HPP
#define TREE_HPP

template <class T>
class BSTree {
	struct Node {
		T data;
		Node *left;
		Node *right;
		Node(T item) {
			data = item;
			left = right = NULL;
		}
	} *_root;
	Node* _insert(Node*, T);
	Node* _delete(Node*, T);
	void _display(Node*);
public:
	BSTree() { _root = NULL; }
	void Insert(T);
	void Delete(T);
	void Display(void);
};

template <class T>
typename BSTree<T>::Node* BSTree<T>::_insert(Node *root, T item) {
	if (!root) {
		return new Node(item);
	}
	if (item < root->data) {
		root->left = _insert(root->left, item);
	} else if (item > root->data) {
		root->right = _insert(root->right, item);
	}
	return root;
}

template <class T>
void BSTree<T>::Insert(T item) {
	_root = _insert(_root, item);
}

template <class T>
typename BSTree<T>::Node* BSTree<T>::_delete(Node *root, T item) {
	if (!root) {
		return root;
	}

	if (root->data == item) {
		if (!root->left && !root->right) { // has no child
			delete root;
			return NULL;
		}
		if (!root->left) { // has right child only
			Node *ptr = root;
			root = root->right;
			delete ptr;
		} else if (!root->right) { // has left child only
			Node *ptr = root;
			root = root->left;
			delete ptr;
		} else { // has both the children
			Node *pptr = root;
			Node *ptr = root->left;
			while (ptr->right) {
				pptr = ptr;
				ptr = ptr->right;
			}
			if (pptr == root) {
				pptr->left = ptr->left;
			} else {
				pptr->right = ptr->left;
			}
			root->data = ptr->data;
			delete ptr;
		}
	}

	if (item < root->data) {
		root->left = _delete(root->left, item);
	} else if (item > root->data) {
		root->right = _delete(root->right, item);
	}
	return root;
}

template <class T>
void BSTree<T>::Delete(T item) {
	_root = _delete(_root, item);
}

template <class T>
void BSTree<T>::_display(Node *root) {
	if (root) {
		_display(root->left);
		std::cout << root->data << '\n';
		_display(root->right);
	}
}

template <class T>
void BSTree<T>::Display() {
	_display(_root);
}

#endif /* TREE_HPP */
