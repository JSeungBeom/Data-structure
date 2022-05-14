#include <iostream>

using namespace std;

struct node {
	int key; // 노드의 key를 저장
	node* parent; // 부모 노드
	node* right; // 오른쪽 자식 노드
	node* left; // 왼쪽 자식 노드
	node(int key) { // 생성자
		this->key = key;
		parent = left = right = NULL;
	}
};

// 이진 탐색 트리 (AVL Tree 구현은 X)
class BST {
private:
	node* root; // 트리의 root

public:
	// 기본 생성자
	BST() {
		root = NULL;
	}

	node* search(node* curNode, int key) {
		// 찾고자 하는 노드가 트리에 존재 X
		if (curNode == NULL) { 
			return NULL;
		}
		// 해당 키 값을 찾은 경우 노드의 주소 리턴
		if (curNode->key == key) {
			return curNode;
		} 
		// 키 값이 현재 노드의 키 값보다 큰 경우
		// 해당 키 값은 현재 노드의 오른쪽 서브트리에 위치
		else if (curNode->key < key) {
			return search(curNode->right, key);
		}
		// 키 값이 현재 노드의 키 값보다 작은 경우
		// 해당 키 값은 현재 노드의 왼쪽 서브트리에 위치
		else {
			return search(curNode->left, key);
		}
	}

	void insert(int key) {
		// 삽입하고자 하는 키 값이 이미 존재하는 경우
		if (search(root, key) != NULL)
			return;

		node* newNode = new node(key);
		// root가 없는 경우, 새 노드가 root
		if (root == NULL) {
			root = newNode;
			return;
		}

		node* curNode = root;
		node* parNode = NULL;

		// 새 노드가 삽입될 위치 탐색
		while (curNode != NULL) {
			parNode = curNode;
			// search의 과정과 유사한 형태로 탐색
			if (curNode->key < key) {
				curNode = curNode->right;
			}
			else {
				curNode = curNode->left;
			}
		}
		// 결과적으로 curNode = NULL, parNode = 들어갈 노드의 parent를 저장

		newNode->parent = parNode; // 새 노드의 부모 노드는 parNode
		// newNode의 키 값에 따라, 부모 노드의 오른쪽 / 왼쪽에 추가될지 결정
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

		// 삭제하려는 노드의 자식 노드가 몇 개인지, 어느 쪽에 있는지 판단하여
		// childNode를 결정
		if (delNode->left == NULL && delNode->right == NULL) {
			childNode = NULL; // 삭제하려는 노드의 child가 없는 경우
		}
		else if (delNode->left == NULL && delNode->right != NULL) {
			childNode = delNode->right; // 삭제하려는 노드의 right child만 있는 경우
		}
		else if (delNode->left != NULL && delNode->right == NULL) {
			childNode = delNode->left; // 삭제하려는 노드의 left child만 있는 경우
		}
		else { // 삭제하려는 노드의 양 쪽 자식이 모두 존재하는 경우
			// 해당 노드를 삭제할 수 없으므로, 가장 가까운 값 successor 탐색
			childNode = delNode->right;
			while (childNode->left != NULL) {
				childNode = childNode->left;
			}
			// successor의 key 값을 delNode에 복사
			// successor는 delNode에서 순서 조건을 위반하지 않는 key 값
			delNode->key = childNode->key;
			// successor를 저장하고 있던 노드를 삭제 노드로 갱신
			// successor는 무조건 left child는 없는 노드
			delNode = childNode; 
			parNode = delNode->parent; // 부모노드는 delNode의 parent
			childNode = delNode->right; // childNode는 delNode의 right child
		}

		// 삭제하려는 노드의 부모 노드와 자식 노드를 연결
		if (parNode == NULL) { // root를 삭제하는 경우
			root = childNode;
			if(childNode != NULL)
			root->parent = NULL;
		}
		else if (delNode == parNode->left) { // 삭제할 노드가 부모 노드의 왼쪽 자식
			parNode->left = childNode;
			if (childNode != NULL) {
				childNode->parent = parNode;
			}
		}
		else { // 삭제할 노드가 부모 노드의 오른쪽 자식
			parNode->right = childNode;
			if (childNode != NULL) {
				childNode->parent = parNode;
			}
		}
		delete delNode; // 노드 삭제
	}
};