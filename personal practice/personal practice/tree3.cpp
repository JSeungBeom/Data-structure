#include <iostream>
#include <vector>

using namespace std;

struct node {
	int data;
	node* parent;
	vector<node*>childList;
	node(int data, node* parent) {
		this->data = data;
		this->parent = parent;
	}
};

class Tree {
private:
	node* root;
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
		node* curNode = nodeList[idx];
		if (curNode == root) {
			return;
		}
		cout << curNode->parent->data << endl;
	}

	void printChild(int data) {
		int idx = find(data, nodeList);
		if (idx == -1) {
			cout << -1 << endl;
			return;
		}
		node* curNode = nodeList[idx];
		if (curNode->childList.size() == 0) {
			cout << -1 << endl;
			return;
		}
		vector<node*>& child = curNode->childList;
		for (int i = 0; i < child.size(); i++) {
			cout << child[i]->data << " ";
		}
		cout << endl;
	}

	void minChild(int data) {
		int idx = find(data, nodeList);
		if (idx == -1) {
			cout << -1 << endl;
			return;
		}
		node* curNode = nodeList[idx];
		if (curNode->childList.size() == 0) {
			cout << -1 << endl;
			return;
		}
		vector<node*>& child = curNode->childList;
		int min = child[0]->data;
		for (int i = 1; i < child.size(); i++) {
			if (min > child[i]->data) {
				min = child[i]->data;
			}
		}
		cout << min << endl;
	}
};


int main() {
	int n;
	cin >> n;
	Tree tree(1);

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int x, y;
		if (s == "insert") {
			cin >> x >> y;
			tree.insertNode(x, y);
		}
		if (s == "delete") {
			cin >> x;
			tree.deleteNode(x);
		}
		if (s == "parent") {
			cin >> x;
			tree.printParent(x);
		}
		if (s == "child") {
			cin >> x;
			tree.printChild(x);
		}
		if (s == "minChild") {
			cin >> x;
			tree.minChild(x);
		}
	}
}