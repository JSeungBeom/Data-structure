#include <iostream>
#include <vector>

using namespace std;

struct node {
	int data;
	int files = 0;
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
		nodeList.push_back(newNode);
		parNode->childList.push_back(newNode);
	}

	void postorder(node* curNode) {
		for (int i = 0; i < curNode->childList.size(); i++) {
			postorder(curNode->childList[i]);
		}
		// external node일 경우, 파일로 취급
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
		if (idx == -1) {
			return;
		}
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
	tree.postorder(tree.root);
	for (int i = 0; i < m; i++) {
		int data;
		cin >> data;
		tree.printFiles(data);
	}
}