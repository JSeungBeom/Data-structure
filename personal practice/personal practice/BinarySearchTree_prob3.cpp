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
private:


public:
	node* root;
	int count = 0;
	BST() {
		root = NULL;
	}

	node* search(node* curNode, int key) {
		if (curNode == NULL)
			return NULL;

		if (curNode->key == key)
			return curNode;
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
	}

	void inOrder(node* curNode) {
		if (curNode == NULL) {
			return;
		}
		if (curNode->left != NULL) {
			inOrder(curNode->left);
		}

		count++;

		if (curNode->right != NULL) {
			inOrder(curNode->right);
		}
	}

	void print_count() {
		cout << count << endl;
		count = 0;
	}
};

int main() {
	int n, m;

	cin >> n >> m;

	BST b;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		b.insert(x);
	}

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		node* curNode = b.search(b.root, x);
		b.inOrder(curNode->right);
		b.print_count();
	}
}