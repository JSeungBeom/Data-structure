#include <iostream>

using namespace std;

struct node {
	int key;
	node* right;
	node* left;
	node* parent;
	node(int key) {
		this->key = key;
		right = left = parent = NULL;
	}
};

class BST {
public:
	node* root;
	int count = 0;
	BST() {
		root = NULL;
	}

	node* search(node* curNode, int key) {
		if (curNode == NULL)
			return NULL;

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
		if (delNode == NULL) {
			return;
		}

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
			if (childNode != NULL) {
				childNode->parent = NULL;
			}
		}
		else if (parNode->right == delNode) {
			parNode->right = childNode;
			if (childNode != NULL) {
				childNode->parent = parNode;
			}
		}
		else {
			parNode->left = childNode;
			if (childNode != NULL) {
				childNode->parent = parNode;
			}
		}
	}

	void max(node* curNode, int key) {
		if (curNode->right != NULL) {
			max(curNode->right, key);
		}
		
		count++;
		if (count == key) {
			cout << curNode->key << endl;
			return;
		}

		if (curNode->left != NULL) {
			max(curNode->left, key);
		}
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
		if (s == "max") {
			b.max(b.root, x);
			b.count = 0;
		}
		if (s == "height") {
			node* temp = b.search(b.root, x);
			cout << b.height(temp) << endl;
		}
	}
}