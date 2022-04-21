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
	node* root;
	vector<node*> nodeList;
	int find(int data, vector<node*>& list) {
		for (int i = 0; i < list.size(); i++) {
			if (data == list[i]->data) {
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

	void deleteNode(int data) {
		int idx = find(data, nodeList);
		if (idx == -1) {
			return;
		}
		node* delNode = nodeList[idx];
		if (delNode == root) {
			return;
		}
		node* parNode = delNode->parent;
		for (int i = 0; i < delNode->childList.size(); i++) {
			parNode->childList.push_back(delNode->childList[i]);
			delNode->childList[i]->parent = parNode;
		}
		vector<node*>& child = parNode->childList;
		child.erase(child.begin() + find(data, child));
		delete nodeList[idx];
		nodeList.erase(nodeList.begin() + idx);
	}

	void printAncestors(int data) {
		int idx = find(data, nodeList);
		if (idx == -1) {
			return;
		}
		node* curNode = nodeList[idx];
		while (curNode != root) {
			cout << curNode->parent->data << " ";
			curNode = curNode->parent;
		}
		cout << endl;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	Tree tree(1);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		tree.insertNode(x, y);
	}
	for (int i = 0; i < m; i++) {
		int v;
		cin >> v;
		tree.printAncestors(v);
	}
}