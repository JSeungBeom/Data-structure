#include <iostream>
#include <vector>

using namespace std;

struct node {
	int data;
	int files = 0;
	node* parent;
	vector <node*>childList;
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

	node* getroot() {
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
		parNode->childList.push_back(newNode);
		nodeList.push_back(newNode);
		return;
	}

	// 후위 순회, 먼저 자식의 노드를 방문하고 자신의 노드를 방문
	void postorder(node* curNode) {
		for (int i = 0; i < curNode->childList.size(); i++) {
			postorder(curNode->childList[i]);
		}
		if (curNode->childList.size() == 0) {
			curNode->files = 1;
		}
		else {
			for(int i = 0; i < curNode->childList.size(); i++)
			curNode->files += curNode->childList[i]->files;
		}
	}

	void printFiles(int data) {
		int idx = find(data, nodeList);
		cout << nodeList[idx]->files << endl;
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
	tree.postorder(tree.getroot());
	for (int i = 0; i < m; i++) {
		int data;
		cin >> data;
		tree.printFiles(data);
	}
}