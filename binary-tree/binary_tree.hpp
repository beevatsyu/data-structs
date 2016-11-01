#ifndef TREE_HPP
#define TREE_HPP

template <class T>
class Tree {
	struct Node {
		T data;
		Node *left;
		Node *right;
	} *root;
public:
	Tree();
	~Tree();
	void Insert(T);
	void Delete(T);
	void Display(void);
};

template <class T>
void Tree<T>::Insert(T item) {
}

template <class T>
void Tree<T>::Delete(T item) {
}

template <class T>
void Tree<T>::Display() {
	std::stack<Node*> stk;
	if (root) {
		stk.push(root);
		while (!stk.empty()) {
			Node *tmp = stk.top();
			stk.pop();
			std::cout << tmp->data << ' ';
			stk.push(tmp->right);
			stk.push(tmp->left);
		}
	}
}

#endif /* TREE_HPP */
