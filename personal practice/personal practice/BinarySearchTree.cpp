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

	// key 값을 가지는 노드를 탐색, O(n) time
	node* search(node* curNode, int key) {
		// 해당 노드가 없는 경우
		if (curNode == NULL)
			return NULL;

		if (curNode->key == key) // 노드를 찾은 경우
			return curNode;
		else if (curNode->key < key) // key 값이 해당 노드의 키 값보다 큰 경우
			return search(curNode->right, key); // 해당 노드는 오른쪽 서브트리에 위치
		else // key 값이 해당 노드의 key 값보다 작은 경우
			return search(curNode->left, key); // 해당 노드는 왼쪽 서브트리에 위치
	}

	// key 값을 갖는 노드를 트리에 삽입, O(n) time
	void insert(int key) {
		if (search(root, key) != NULL) // 이미 해당 key값을 갖는 노드가 존재
			return;

		node* newNode = new node(key); // 새로운 노드
		if (root == NULL) { // 루트가 비어있는 경우
			root = newNode;
			return;
		}

		node* curNode = root;
		node* parNode = NULL;

		// 삽입할 위치 탐색
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

	// key 값을 갖는 노드를 트리에서 삭제, O(n) time
	void remove(int key) {
		node* delNode = search(root, key); // 노드 탐색
		if (delNode == NULL) // 노드가 없는 경우
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