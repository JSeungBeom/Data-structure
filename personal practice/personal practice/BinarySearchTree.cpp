#include <iostream>

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

	// key ���� ������ ��带 Ž��, O(n) time
	node* search(node* curNode, int key) {
		// �ش� ��尡 ���� ���
		if (curNode == NULL)
			return NULL;

		if (curNode->key == key) // ��带 ã�� ���
			return curNode;
		else if (curNode->key < key) // key ���� �ش� ����� Ű ������ ū ���
			return search(curNode->right, key); // �ش� ���� ������ ����Ʈ���� ��ġ
		else // key ���� �ش� ����� key ������ ���� ���
			return search(curNode->left, key); // �ش� ���� ���� ����Ʈ���� ��ġ
	}

	// key ���� ���� ��带 Ʈ���� ����, O(n) time
	void insert(int key) {
		if (search(root, key) != NULL) // �̹� �ش� key���� ���� ��尡 ����
			return;

		node* newNode = new node(key); // ���ο� ���
		if (root == NULL) { // ��Ʈ�� ����ִ� ���
			root = newNode;
			return;
		}

		node* curNode = root;
		node* parNode = NULL;

		// ������ ��ġ Ž��
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

	// key ���� ���� ��带 Ʈ������ ����, O(n) time
	void remove(int key) {
		node* delNode = search(root, key); // ��� Ž��
		if (delNode == NULL) // ��尡 ���� ���
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
			root = childNode;
			root->parent = NULL;
		}
		else if (delNode == parNode->left) {
			parNode->left = childNode;
			if (childNode != NULL) {
				childNode->parent = parNode;
			}
		}
		else {
			parNode->right = childNode;
			if (childNode != NULL) {
				childNode->parent = parNode;
			}
		}
	}
};