class BTNode:
    def __init__(self, item, left=None, right=None):
        self.data = item
        self.left = left
        self.right = right


class BTree:
    def __init__(self):
        self.root = None

    def inorder(self):
        self._inorder(self.root)

    def _inorder(self, root):
        if root:
            self._inorder(root.left)
            print root.data
            self._inorder(root.right)

class BSTree(BTree):
    def insert(self, item):
        self.root = self._insert(self.root, item)

    def _insert(self, root, item):
        if not root:
            return BTNode(item)

        if item < root.data:
            root.left = self._insert(root.left, item)
        elif item > root.data:
            root.right = self._insert(root.right, item)
        return root

    def delete(self, item):
        pass


bst = BSTree()
bst.insert(2)
bst.insert(1)
bst.insert(3)
bst.insert(5)
bst.inorder()
