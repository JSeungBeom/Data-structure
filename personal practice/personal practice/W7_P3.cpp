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

	node* getRoot() {
		return root;
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

	void postOrder(node* curNode) {
		depth++;
		for (int i = 0; i < curNode->childList.size(); i++) {
			postOrder(curNode->childList[i]);
		}
		depth--;
		cout << depth << endl;
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
		tree.postOrder(tree.getRoot());
	}
}