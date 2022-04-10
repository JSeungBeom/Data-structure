#include <iostream>
#include <vector>

using namespace std;

struct node {
	int data;
	node* parent; // 부모 노드
	vector<node*>childList; // 자식 노드들의 리스트
	node(int data, node* parent) {
		this->data = data;
		this->parent = parent;
	}
};

class Tree {
private:
	node* root; // 트리의 root
	vector<node*>nodeList; // 전체 트리의 노드들의 리스트
	// 해당 리스트에서 인덱스 값을 리턴
	int find(int data, vector<node*>& list) {
		for (int i = 0; i < list.size(); i++) {
			if (list[i]->data == data) {
				return i;
			}
		}
		return -1;
	}

public:
	Tree(int data) {
		root = new node(data, NULL);
		nodeList.push_back(root);
	}

	void insertNode(int parData, int data) {
		if (find(data, nodeList) != -1) {
			cout << -1 << endl;
			return;
		}
		int idx = find(parData, nodeList);
		if (idx == -1) {
			cout << -1 << endl;
			return;
		}
		node* parNode = nodeList[idx];
		node* newNode = new node(data, parNode);
		parNode->childList.push_back(newNode);
		nodeList.push_back(newNode);
	}

	void deleteNode(int data) {
		int idx = find(data, nodeList);
		if (idx == -1) {
			cout << -1 << endl;
			return;
		}
		node* curNode = nodeList[idx];
		if (curNode == root) {
			cout << -1 << endl;
			return;
		}
		node* parNode = curNode->parent;
		for (int i = 0; i < curNode->childList.size(); i++) {
			parNode->childList.push_back(curNode->childList[i]);
			curNode->childList[i]->parent = parNode;
		}
		vector<node*>& child = parNode->childList;
		child.erase(child.begin() + find(data, child));
		nodeList.erase(nodeList.begin() + idx);
		delete curNode;
	}

	void printParent(int data) {
		int idx = find(data, nodeList);
		if (idx == -1) {
			cout << -1 << endl;
			return;
		}
		if (idx == 0) {
			return;
		}
		node* curNode = nodeList[idx];
		cout << curNode->parent->data << endl;
	}

	void printChild(int data) {
		int idx = find(data, nodeList);
		if (idx == -1) {
			cout << -1 << endl;
			return;
		}
		node* curNode = nodeList[idx];
		vector<node*>child = curNode->childList;
		if (child.size() == 0) {
			cout << -1 << endl;
			return;
		}
		for (int i = 0; i < child.size(); i++) {
			cout << child[i]->data << " ";
		}
		cout << endl;
	}

	void maxChild(int data) {
		int idx = find(data, nodeList);
		if (idx == -1) {
			cout << -1 << endl;
			return;
		}
		node* curNode = nodeList[idx];
		vector<node*>child = curNode->childList;
		if (child.size() == 0) {
			cout << -1 << endl;
			return;
		}
		int max = child[0]->data;
		for (int i = 1; i < child.size(); i++) {
			if (child[i]->data > max) {
				max = child[i]->data;
			}
		}
		cout << max << endl;
	}
};

int main() {
	int t;
	cin >> t;
	Tree tree(1);
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