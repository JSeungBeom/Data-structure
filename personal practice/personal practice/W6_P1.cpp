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
	vector <node*> nodeList;
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
		return;
	}

	void deleteNode(int data) {
		int idx = find(data, nodeList);
		if (idx == -1) {
			cout << -1 << endl;
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
		return;
	}

	void printParent(int data) {
		int idx = find(data, nodeList);
		if (idx == -1) {
			cout << -1 << endl;
			return;
		}
		if (idx == 0) {
			cout << -1 << endl;
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
		if (nodeList[idx]->childList.size() == 0) {
			cout << -1 << endl;
			return;
		}
		vector<node*>& child = nodeList[idx]->childList;
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
		vector<node*>& child = nodeList[idx]->childList;
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
		int parData, data;
		if (s == "insert") {
			cin >> parData >> data;
			tree.insertNode(parData, data);
		}
		if (s == "delete") {
			cin >> data;
			tree.deleteNode(data);
		}
		if (s == "parent") {
			cin >> data;
			tree.printParent(data);
		}
		if (s == "child") {
			cin >> data;
			tree.printChild(data);
		}
		if (s == "maxChild") {
			cin >> data;
			tree.maxChild(data);
		}
	}
}