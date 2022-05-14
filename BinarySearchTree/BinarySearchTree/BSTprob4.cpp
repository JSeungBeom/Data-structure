#include <iostream>

using namespace std;

struct node {
	int key;
	node* parent;
	node* left;
	node* right;
	node(int key) {
		this->key = key;
		parent = left = right = NULL;
	}
};

class BST {
private:
	node* root;

public:
	int count = 0;
	BST() {
		root = NULL;
	}

	void print_depth(node* curNode) {
		int depth = 0;
		while (curNode != root) {
			curNode = curNode->parent;
			depth++;
		}
		cout << depth << endl;
	}

	node* getRoot() {
		return root;
	}

	node* search(node* curNode, int key) {
		if (curNode == NULL) {
			return NULL;
		}

		if (curNode->key == key) {
			return curNode;
		}
		else if (curNode->key < key) {
			return search(curNode->right, key);
		}
		else {
			return search(curNode->left, key);
		}
	}

	void insert(int key) {
		if (search(root, key) != NULL)
			return;

		node* newNode = new node(key);
		if (root == NULL) {
			root = newNode;
			print_depth(newNode);
			return;
		}

		node* curNode = root;
		node* parNode = NULL;

		while (curNode != NULL) {
			parNode = curNode;
			if (curNode->key < key) {
				curNode = curNode->right;
			}
			else {
				curNode = curNode->left;
			}
		}

		newNode->parent = parNode;
		if (parNode->key < key) {
			parNode->right = newNode;
		}
		else {
			parNode->left = newNode;
		}
		print_depth(newNode);
	}

	void remove(int key) {
		node* delNode = search(root, key);
		print_depth(delNode);
		if (delNode == NULL) {
			return;
		}

		node* parNode = delNode->parent;
		node* childNode;

		if (delNode->right == NULL && delNode->left == NULL) {
			childNode = NULL;
		}
		else if (delNode->right != NULL && delNode->left == NULL) {
			childNode = delNode->right;
		}
		else if (delNode->right == NULL && delNode->left != NULL) {
			childNode = delNode->left;
		}
		else {
			childNode = delNode->right;
			while (childNode->left != NULL)
				childNode = childNode->left;
			delNode->key = childNode->key;
			delNode = childNode;
			parNode = delNode->parent;
			childNode = delNode->right;
		}

		if (parNode == NULL) {
			root = childNode;
			if (childNode != NULL)
				root->parent = NULL;
		}
		else if (parNode->right == delNode) {
			parNode->right = childNode;
			if (childNode != NULL)
				childNode->parent = parNode;
		}
		else {
			parNode->left = childNode;
			if (childNode != NULL)
				childNode->parent = parNode;
		}
	}

	void max(node* curNode, int key) {
		if (curNode->right != NULL)
			max(curNode->right, key);

		count++;
		if (count == key) {
			cout << curNode->key << endl;
			return;
		}
		
		if (curNode->left != NULL)
			max(curNode->left, key);
	}

	int height(node* curNode) {
		if (curNode == NULL) {
			return 0;
		}

		int leftHeight = height(curNode->left);
		int rightHeight = height(curNode->right);
		if (leftHeight >= rightHeight) {
			return leftHeight + 1;
		}
		else {
			return rightHeight + 1;
		}
	}
};

int main() {
	int t;
	cin >> t;

	BST bst;

	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		int k;
		cin >> k;
		if (s == "insert") {
			bst.insert(k);
		}
		if (s == "delete") {
			bst.remove(k);
		}
		if (s == "max") {
			bst.max(bst.getRoot(), k);
			bst.count = 0;
		}
		if (s == "height") {
			node* temp = bst.search(bst.getRoot(), k);
			cout << bst.height(temp) - 1 << endl;
		}
	}
}