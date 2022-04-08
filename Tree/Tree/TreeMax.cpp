#include <iostream>
#include <vector>

using namespace std;

struct node {
	int data; // 데이터 필드
	node* parent; // 부모 노드를 가리킬 포인터
	vector<node*>childList; // 자식 노드들을 저장할 포인터 벡터
	// 생성자
	node(int data, node* parent) {
		this->data = data;
		this->parent = parent;
	}
};

class Tree {
private:
	node* root; // 트리의 root를 저장할 포인터
	vector<node*> nodeList; // 트리의 모든 노드들을 저장할 포인터 벡터
	// 특정 노드의 index를 list 내에서 찾는 함수
	int find(int data, vector<node*>& list) {
		for (int i = 0; i < list.size(); i++) {
			if (list[i]->data == data) {
				return i;
			} // list 내에 data와 일치하는 데이터가 있다면, 그 인덱스를 리턴
		}
		return -1; // 일치하는 데이터가 없다면, -1 리턴
	}

public:
	// 생성자
	Tree(int data) {
		root = new node(data, NULL); // root를 트리에 추가, root는 부모 노드가 없다
		nodeList.push_back(root); // nodeList에 root 추가
	}

	// 트리에 노드를 추가하는 함수
	void insertNode(int parData, int data) {
		// nodeList에 데이터가 이미 있다면 종료
		if (find(data, nodeList) != -1) {
			cout << -1 << endl;
			return;
		}
		int idx = find(parData, nodeList);
		// 부모 노드를 찾을 수 없다면 종료
		if (idx == -1) {
			cout << -1 << endl;
			return;
		}
		node* parNode = nodeList[idx]; // 부모 노드
		node* newNode = new node(data, parNode); // 자식 노드
		parNode->childList.push_back(newNode);// 부모 노드의 자식 노드 벡터에 newNode를 추가
		nodeList.push_back(newNode); // nodeList에 newNode를 추가
		return;

	}

	void deleteNode(int data) {
		int idx = find(data, nodeList);
		// 삭제하고자 하는 데이터가 트리에 없는 경우
		if (idx == -1) {
			cout << -1 << endl;
			return;
		}
		node* delNode = nodeList[idx]; // 삭제할 노드
		// 삭제할 노드가 루트인 경우 종료
		if (delNode == root) {
			return;
		}
		node* parNode = delNode->parent; // 부모 노드
		// 삭제하는 노드의 자식 노드들을 부모 노드의 자식 벡터에 연결하고, 자식 노드들의 부모를 부모 노드로 설정
		for (int i = 0; i < delNode->childList.size(); i++) {
			parNode->childList.push_back(delNode->childList[i]);
			delNode->childList[i]->parent = parNode;
		}
		vector<node*>&child = parNode->childList; // 부모 노드의 자식들을 담는 벡터
		child.erase(child.begin() + find(data, child)); // 자식 벡터에서 노드를 삭제
		delete nodeList[idx]; // 메모리 할당 해제
		nodeList.erase(nodeList.begin() + idx); // 노드 벡터에서 노드를 삭제
		return;
	}

	void printParent(int data) {
		int idx = find(data, nodeList);
		// 해당 노드가 없는 경우
		if (idx == -1) {
			cout << -1 << endl;
			return;
		}
		// 해당 노드가 root인 경우
		if (idx == 0) {
			cout << -1 << endl;
			return;
		}
		cout << nodeList[idx]->parent->data << endl;
	}

	void printChild(int data) {
		int idx = find(data, nodeList);
		// 해당 노드가 없는 경우
		if (idx == -1) {
			cout << -1 << endl;
			return;
		}
		// 해당 노드의 자식 노드가 없는 경우
		if (nodeList[idx]->childList.size() == 0) {
			cout << -1 << endl;
			return;
		}
		vector<node*>& list = nodeList[idx]->childList;
		for (int i = 0; i < list.size(); i++) {
			cout << list[i]->data << " ";
		}
		cout << endl;
	}

	void maxChild(int data) {
		int idx = find(data, nodeList);
		// 해당 노드가 없는 경우
		if (idx == -1) {
			cout << -1 << endl;
			return;
		}
		// 해당 노드의 자식 노드가 없는 경우
		if (nodeList[idx]->childList.size() == 0) {
			cout << -1 << endl;
			return;
		}
		vector<node*>& list = nodeList[idx]->childList;
		int max = list[0]->data; // 최대값은 자식들 중 첫번째 값으로 초기화
		for (int i = 1; i < list.size(); i++) {
			if (list[i]->data > max) {
				max = list[i]->data;
			} // 자식 노드들 중, max보다 큰 데이터를 가진다면 max를 그 값으로 대입
		}
		cout << max << endl;
	}
};

int main() {
	int t;
	cin >> t;
	Tree tree(1); // 초기에 루트는 1
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		int pardata, data;
		if (s == "insert") {
			cin >> pardata >> data;
			tree.insertNode(pardata, data);
		}
		else if (s == "delete") {
			cin >> data;
			tree.deleteNode(data);
		}
		else if (s == "parent") {
			cin >> data;
			tree.printParent(data);
		}
		else if (s == "child") {
			cin >> data;
			tree.printChild(data);
		}
		else if (s == "maxChild") {
			cin >> data;
			tree.maxChild(data);
		}
	}
}