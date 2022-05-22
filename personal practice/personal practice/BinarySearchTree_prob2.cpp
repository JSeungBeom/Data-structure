#include <iostream>

using namespace std;

struct node {
	int key;
	node* left;
	node* right;
	node* parent;
	node(int key) {
		this->key = key;
		left = right = parent = NULL;
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

	void print_depth(node* curNode) {
		int depth = 0;
		while (curNode != root) {
			curNode = curNode->parent;
			depth++;
		}

		cout << depth << endl;
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
		if (delNode == NULL)
			return;

		node* parNode = delNode->parent;
		node* childNode;

		if (delNode->left == NULL && delNode->right == NULL) {
			childNode = NULL;
		}
		else if (delNode->left != NULL && delNode->right == NULL) {
			childNode = delNode->left;
		}
		else if (delNode->left == NULL && delNode->right != NULL) {
			childNode = delNode->right;
		}
		else {
			childNode = delNode->right;
			while (childNode->left != NULL) {
				childNode = childNode->left;
			}
			delNode->key = childNode->key;
			delNode = childNode;
			parNode = delNode->parent;
			childNode = delNode->right;
		}

		if (parNode == NULL) {
			childNode = root;
			if (childNode != NULL)
				root->parent = NULL;
		}
		else if (parNode->left == delNode) {
			parNode->left = childNode;
			if (childNode != NULL)
				childNode->parent = parNode;
		}
		else {
			parNode->right = childNode;
			if (childNode != NULL)
				childNode->parent = parNode;
		}
	}

	node* getRoot() {
		return root;
	}

	void inOrder(node* curNode, int k) {
		if (curNode->left != NULL)
			inOrder(curNode->left, k);

		count++;
		if (count == k) {
			cout << curNode->key << endl;
			return;
		}
	
		if (curNode->right != NULL)
			inOrder(curNode->right, k);
	}

	int height(node* curNode) {
		if (curNode == NULL) {
			return -1;
		}

		int lefth = height(curNode->left);
		int righth = height(curNode->right);

		if (lefth > righth) {
			return lefth + 1;
		}
		else {
			return righth + 1;
		}
	}
};

int main() {
	int t;
	cin >> t;
	BST b;
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		int x;
		cin >> x;
		if (s == "insert") {
			b.insert(x);
		}
		if (s == "delete") {
			b.remove(x);
		}
		if (s == "min") {
			b.inOrder(b.getRoot(), x);
			b.count = 0;
		}
		if (s == "height") {
			node* temp = b.search(b.getRoot(), x);
			cout << b.height(temp) << endl;
		}
	}
}