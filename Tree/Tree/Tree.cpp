#include <iostream>
#include <vector>

using namespace std;

struct node {
	int data; // 데이터 필드
	node* parent; // 부모 노드를 가리키는 포인터 변수
	vector<node*> childList; // 자식 노드들을 가리키는 포인터 벡터
	// 기본 생성자
	node(int data, node* parent) {
		this->data = data;
		this->parent - parent;
	}
};

class Tree {
private:
	node* root; // 트리의 root를 저장하는 포인터 변수
	vector<node*> nodeList; // 트리의 모든 노드의 포인터를 저장하는 벡터

	 // 노드 포인터 벡터에서 특정 노드를 찾는 함수
	int find(int data, vector <node*>& list) {
		for (int i = 0; i < list.size(); i++) {
			if (list[i]->data == data) {
				return i;
			} // 노드를 찾았을 경우, 인덱스를 반환
		}
		return -1;
	};
public:
	// 기본 생성자, 트리에 루트 추가
	Tree(int data) {	
		root = new node(data, NULL);
		nodeList.push_back(root);
	}; 
	
	// 트리에 노드를 삽입
	void insertNode(int parData, int data) {
		// 새로 삽입할 노드가 이미 존재하는 경우
		if (find(data, nodeList) != -1) {
			return;
		}
		int idx = find(parData, nodeList);
		// 부모 노드가 존재하지 않는 경우
		if (idx == -1) {
			return;
		}

		node* parNode = nodeList[idx]; // parNode에 부모 노드의 주소를 저장
		node* newNode = new node(data, parNode); // 새로 삽입할 노드를 생성 후, 부모를 parNode로 지정
		parNode->childList.push_back(newNode); // parNode의 자식으로 새로운 노드 삽입
		nodeList.push_back(newNode); // 전체 노드 벡터에 새로운 노드 저장
		return;
	}

	// 트리에서 노드를 삭제하고, 부모 노드에 그 노드의 자식들을 연결
	void deleteNode(int data) {
		int idx = find(data, nodeList);
		// 삭제하려는 노드가 존재하지 않는 경우
		if (idx == -1) {
			return;
		}

		node* delNode = nodeList[idx]; // delNode에 삭제하려는 노드의 주소를 저장
		if (delNode == root) { // 삭제하려는 노드가 root일 경우, 삭제하지 않음
			return;
		} 

		node* parNode = delNode->parent; // parNode에 삭제하려는 노드의 부모 노드의 주소를 저장
		for (int i = 0; i < delNode->childList.size(); i++) {
			parNode->childList.push_back(delNode->childList[i]); // 삭제하려는 노드의 자식들을 parNode의 자식으로 삽입
			delNode->childList[i]->parent = parNode; // 삭제하려는 노드의 자식들의 부모를 parNode로 설정
		}

		vector<node*>& child = parNode->childList;
		child.erase(child.begin() + find(data, child)); // parNode의 자식 벡터에서 delNode 제거
		nodeList.erase(nodeList.begin() + idx); // 전체 노드 벡터에서 delNode를 제거
		delete nodeList[idx]; // delNode 할당 해제
		return;
	}	

	// 부모 노드를 출력
	void printParent(int data) {
		int idx = find(data, nodeList);
		if (idx == -1) {
			return;
		}

		node* curNode = nodeList[idx];
		cout << curNode->parent->data << endl;
	}

	// 자식 노드들을 출력
	void printChild(int data) {
		int idx = find(data, nodeList);
		if (idx == -1) {
			return;
		}
		vector<node*>& child = nodeList[idx]->childList;
		for (int i = 0; i < child.size(); i++) {
			cout << child[i]->data << " ";
		}
		cout << endl;
	}
};

int main() {
	Tree t(2);
	t.insertNode(2, 5);
	t.insertNode(2, 3);
	t.insertNode(2, 4);
	t.printChild(2);
}