#include <iostream>
#include <vector>

using namespace std;

struct node {
	int data;
	int filesize;
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
		nodeList.push_back(newNode);
		parNode->childList.push_back(newNode);
	}

	node* getRoot() {
		return root;
	}

	void postOrder(node* curNode) {
		for (int i = 0; i < curNode->childList.size(); i++) {
			postOrder(curNode->childList[i]);
		}
		if (curNode->childList.size() != 0) {
			for (int i = 0; i < curNode->childList.size(); i++) {
				curNode->filesize += curNode->childList[i]->filesize;
			}
		}
	}

	void insertFile(int data, int filesize) {
		int idx = find(data, nodeList);
		nodeList[idx]->filesize = filesize;
	}

	void printFile(int data) {
		int idx = find(data, nodeList);
		cout << nodeList[idx]->filesize << endl;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	Tree tree(1);
	for (int i = 0; i < n - 1; i++) {
		int parData, data;
		cin >> parData >> data;
		tree.insertNode(parData, data);
	}
	for (int i = 0; i < n; i++) {
		int data, size;
		cin >> data >> size;
		tree.insertFile(data, size);
	}
	tree.postOrder(tree.getRoot());
	for (int i = 0; i < m; i++) {
		int data;
		cin >> data;
		tree.printFile(data);
	}
}