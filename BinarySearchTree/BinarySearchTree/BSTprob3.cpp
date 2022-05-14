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
	BST() {
		root = NULL;
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

	void remove(int key) {
		node* delNode = search(root, key);
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
};

int main() {
	int n, m;
	cin >> n >> m;

	BST bst;
	int max = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (max < x) {
			max = x;
		}
		bst.insert(x);
	}

	for (int i = 0; i < m; i++) {
		int x;
		int count = 0;
		cin >> x;
		node* temp = bst.search(bst.getRoot(), x);
		for (int j = max; j > x; j--) {
			if (bst.search(temp, j) != NULL) {
				count++;
			}
		}
		cout << count << endl;
	}
}