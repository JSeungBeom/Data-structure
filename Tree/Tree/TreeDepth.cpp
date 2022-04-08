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
	
	void printDepth(int data) {
		int idx = find(data, nodeList);
		if (idx == -1) {
			return;
		}
		int depth = 0;
		node* curNode = nodeList[idx];
		while (curNode->parent != NULL) {
			depth++;
			curNode = curNode->parent;
		}
		cout << depth << endl;
	}
};

int main() {
	Tree tree(1);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		int parData, data;
		cin >> parData >> data;
		tree.insertNode(parData, data);
	}

	for (int i = 0; i < m; i++) {
		int data;
		cin >> data;
		tree.printDepth(data);
	}
}