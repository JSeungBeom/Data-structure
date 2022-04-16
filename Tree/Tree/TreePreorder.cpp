#include <iostream>
#include <vector>

using namespace std;

struct node {
	int data;
	node* parent;
	vector <node*> childList;
	node(int data, node* parent) {
		this->data = data;
		this->parent = parent;
	}
};

class Tree {
private:
	int depth = 0;
	vector <node*> nodeList;
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
		return;
	}

	// 전위순회, 먼저 자신의 노드를 방문하고 자식 노드를 방문
	void preorder(node* curNode) {
		cout << depth << " ";
		depth++;
		for (int i = 0; i < curNode->childList.size(); i++) {
			preorder(curNode->childList[i]);
		}
		depth--;
	}

};

int main() {
	int t;

	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		Tree tree(1);
		for (int i = 0; i < n - 1; i++) {
			int parData, data;
			cin >> parData >> data;
			tree.insertNode(parData, data);
		}
		tree.preorder(tree.root);
	}
}