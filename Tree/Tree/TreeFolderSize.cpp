#include <iostream>
#include <vector>

using namespace std;

struct node {
	int data;
	int size;
	node* parent;
	vector <node*> childList;
	node(int data, node* parent) {
		this->data = data;
		this->parent = parent;
	}
};

class Tree {
private:

	vector<node*>nodeList;
	int find(int data, vector<node*>& list) {
		for (int i = 0; i < list.size(); i++) {
			if (data == list[i]->data) {
				return i;
			}
		}
		return -1;
	}

public:
	node* root;
	Tree(int data) {
		root = new node(data, NULL);
		nodeList.push_back(root);
	}

	void insertNode(int parData, int data) {
		if (find(data, nodeList) != -1) {
			return;
		}
		int idx = find(parData, nodeList);
		if (idx == -1) {
			return;
		}
		node* parNode = nodeList[idx];
		node* newNode = new node(data, parNode);
		parNode->childList.push_back(newNode);
		nodeList.push_back(newNode);
	}

	void insertSize(int data, int size) {
		int idx = find(data, nodeList);
		if (idx == -1) {
			return;
		}
		node* curNode = nodeList[idx];
		curNode->size = size;
	}

	// 폴더의 총 용량을 계산하기 위해, 후위 순회를 사용
	void postorder(node* curNode) {
		for (int i = 0; i < curNode->childList.size(); i++) {
			postorder(curNode->childList[i]);
		}
		for (int i = 0; i < curNode->childList.size(); i++) {
			curNode->size += curNode->childList[i]->size;
		}
	}

	void printSize(int data) {
		int idx = find(data, nodeList);
		node* curNode = nodeList[idx];
		cout << curNode->size << endl;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	Tree tree(1);
	for (int i = 0; i < n - 1; i++) {
		int pardata, data;
		cin >> pardata >> data;
		tree.insertNode(pardata, data);
	}

	for (int i = 0; i < n; i++) {
		int data, size;
		cin >> data >> size;
		tree.insertSize(data, size);
	}
	tree.postorder(tree.root);
	for (int i = 0; i < m; i++) {
		int data;
		cin >> data;
		tree.printSize(data);
	}
}