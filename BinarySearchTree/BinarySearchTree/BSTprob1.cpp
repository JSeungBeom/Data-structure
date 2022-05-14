#include <iostream>

using namespace std;

struct node {
	int key; // ����� key�� ����
	node* parent; // �θ� ���
	node* right; // ������ �ڽ� ���
	node* left; // ���� �ڽ� ���
	node(int key) { // ������
		this->key = key;
		parent = left = right = NULL;
	}
};

// ���� Ž�� Ʈ�� (AVL Tree ������ X)
class BST {
private:
	node* root; // Ʈ���� root

public:
	// �⺻ ������
	BST() {
		root = NULL;
	}

	node* getRoot() {
		return root;
	}

	node* search(node* curNode, int key) {
		// ã���� �ϴ� ��尡 Ʈ���� ���� X
		if (curNode == NULL) {
			return NULL;
		}
		// �ش� Ű ���� ã�� ��� ����� �ּ� ����
		if (curNode->key == key) {
			return curNode;
		}
		// Ű ���� ���� ����� Ű ������ ū ���
		// �ش� Ű ���� ���� ����� ������ ����Ʈ���� ��ġ
		else if (curNode->key < key) {
			return search(curNode->right, key);
		}
		// Ű ���� ���� ����� Ű ������ ���� ���
		// �ش� Ű ���� ���� ����� ���� ����Ʈ���� ��ġ
		else {
			return search(curNode->left, key);
		}
	}

	void insert(int key) {
		// �����ϰ��� �ϴ� Ű ���� �̹� �����ϴ� ���
		if (search(root, key) != NULL)
			return;

		node* newNode = new node(key);
		// root�� ���� ���, �� ��尡 root
		if (root == NULL) {
			root = newNode;
			return;
		}

		node* curNode = root;
		node* parNode = NULL;

		// �� ��尡 ���Ե� ��ġ Ž��
		while (curNode != NULL) {
			parNode = curNode;
			// search�� ������ ������ ���·� Ž��
			if (curNode->key < key) {
				curNode = curNode->right;
			}
			else {
				curNode = curNode->left;
			}
		}
		// ��������� curNode = NULL, parNode = �� ����� parent�� ����

		newNode->parent = parNode; // �� ����� �θ� ���� parNode
		// newNode�� Ű ���� ����, �θ� ����� ������ / ���ʿ� �߰����� ����
		if (parNode->key < key) {
			parNode->right = newNode;
		}
		else {
			parNode->left = newNode;
		}
	}

	void remove(int key) {
		node* delNode = search(root, key);
		if (delNode == NULL)
			return;

		node* parNode = delNode->parent;
		node* childNode;

		// �����Ϸ��� ����� �ڽ� ��尡 �� ������, ��� �ʿ� �ִ��� �Ǵ��Ͽ�
		// childNode�� ����
		if (delNode->left == NULL && delNode->right == NULL) {
			childNode = NULL; // �����Ϸ��� ����� child�� ���� ���
		}
		else if (delNode->left == NULL && delNode->right != NULL) {
			childNode = delNode->right; // �����Ϸ��� ����� right child�� �ִ� ���
		}
		else if (delNode->left != NULL && delNode->right == NULL) {
			childNode = delNode->left; // �����Ϸ��� ����� left child�� �ִ� ���
		}
		else { // �����Ϸ��� ����� �� �� �ڽ��� ��� �����ϴ� ���
			// �ش� ��带 ������ �� �����Ƿ�, ���� ����� �� successor Ž��
			childNode = delNode->right;
			while (childNode->left != NULL) {
				childNode = childNode->left;
			}
			// successor�� key ���� delNode�� ����
			// successor�� delNode���� ���� ������ �������� �ʴ� key ��
			delNode->key = childNode->key;
			// successor�� �����ϰ� �ִ� ��带 ���� ���� ����
			// successor�� ������ left child�� ���� ���
			delNode = childNode;
			parNode = delNode->parent; // �θ���� delNode�� parent
			childNode = delNode->right; // childNode�� delNode�� right child
		}

		// �����Ϸ��� ����� �θ� ���� �ڽ� ��带 ����
		if (parNode == NULL) { // root�� �����ϴ� ���
			root = childNode;
			if (childNode != NULL)
				root->parent = NULL;
		}
		else if (delNode == parNode->left) { // ������ ��尡 �θ� ����� ���� �ڽ�
			parNode->left = childNode;
			if (childNode != NULL) {
				childNode->parent = parNode;
			}
		}
		else { // ������ ��尡 �θ� ����� ������ �ڽ�
			parNode->right = childNode;
			if (childNode != NULL) {
				childNode->parent = parNode;
			}
		}
		delete delNode; // ��� ����
	}
};

int main() {
	int n, m;
	cin >> n >> m;

	BST bst;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		bst.insert(x);
	}

	for (int i = 0; i < m; i++) {
		int x;
		int count = 0;
		cin >> x;
		node* temp = bst.search(bst.getRoot(), x);
		for(int j = 0; j < x; j++)
			if (bst.search(temp, j) != NULL) {
				count++;
		}

		cout << count << endl;
	}


}