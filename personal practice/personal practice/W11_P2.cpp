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
public:
	node* root;
	int cnt = 0;
	BST() {
		root = NULL;
	}

	void depth(node* curNode) {
		int d = 0;
		while (curNode != root) {
			d++;
			curNode = curNode->parent;
		}
		cout << d << endl;
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
		if (search(root, key) != NULL) {
			return;
		}

		node* newNode = new node(key);
		if (root == NULL) {
			root = newNode;
			depth(newNode);
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
		depth(newNode);
	}

	void remove(int key) {
		node* delNode = search(root, key);
		if (delNode == NULL) {
			return;
		}
		depth(delNode);

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
			while (childNode->left != NULL) {
				childNode = childNode->left;
			}
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
		else if (delNode == parNode->right) {
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

	void inOrder(node* curNode, int k) {
		if (curNode->left != NULL) {
			inOrder(curNode->left, k);
		}

		cnt++;
		if (cnt == k) {
			cout << curNode->key << endl;
		}

		if (curNode->right != NULL) {
			inOrder(curNode->right, k);
		}
	}

	int height(node* curNode) {
		if (curNode == NULL) {
			return -1;
		}
		int rheight = height(curNode->right);
		int lheight = height(curNode->left);

		if (rheight > lheight) {
			return rheight + 1;
		}
		else {
			return lheight + 1;
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
			b.inOrder(b.root, x);
			b.cnt = 0;
		}
		if (s == "height") {
			node* temp = b.search(b.root, x);
			cout << b.height(temp) << endl;
		}
	}
}