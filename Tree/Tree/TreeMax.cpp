#include <iostream>
#include <vector>

using namespace std;

struct node {
	int data; // ������ �ʵ�
	node* parent; // �θ� ��带 ����ų ������
	vector<node*>childList; // �ڽ� ������ ������ ������ ����
	// ������
	node(int data, node* parent) {
		this->data = data;
		this->parent = parent;
	}
};

class Tree {
private:
	node* root; // Ʈ���� root�� ������ ������
	vector<node*> nodeList; // Ʈ���� ��� ������ ������ ������ ����
	// Ư�� ����� index�� list ������ ã�� �Լ�
	int find(int data, vector<node*>& list) {
		for (int i = 0; i < list.size(); i++) {
			if (list[i]->data == data) {
				return i;
			} // list ���� data�� ��ġ�ϴ� �����Ͱ� �ִٸ�, �� �ε����� ����
		}
		return -1; // ��ġ�ϴ� �����Ͱ� ���ٸ�, -1 ����
	}

public:
	// ������
	Tree(int data) {
		root = new node(data, NULL); // root�� Ʈ���� �߰�, root�� �θ� ��尡 ����
		nodeList.push_back(root); // nodeList�� root �߰�
	}

	// Ʈ���� ��带 �߰��ϴ� �Լ�
	void insertNode(int parData, int data) {
		// nodeList�� �����Ͱ� �̹� �ִٸ� ����
		if (find(data, nodeList) != -1) {
			cout << -1 << endl;
			return;
		}
		int idx = find(parData, nodeList);
		// �θ� ��带 ã�� �� ���ٸ� ����
		if (idx == -1) {
			cout << -1 << endl;
			return;
		}
		node* parNode = nodeList[idx]; // �θ� ���
		node* newNode = new node(data, parNode); // �ڽ� ���
		parNode->childList.push_back(newNode);// �θ� ����� �ڽ� ��� ���Ϳ� newNode�� �߰�
		nodeList.push_back(newNode); // nodeList�� newNode�� �߰�
		return;

	}

	void deleteNode(int data) {
		int idx = find(data, nodeList);
		// �����ϰ��� �ϴ� �����Ͱ� Ʈ���� ���� ���
		if (idx == -1) {
			cout << -1 << endl;
			return;
		}
		node* delNode = nodeList[idx]; // ������ ���
		// ������ ��尡 ��Ʈ�� ��� ����
		if (delNode == root) {
			return;
		}
		node* parNode = delNode->parent; // �θ� ���
		// �����ϴ� ����� �ڽ� ������ �θ� ����� �ڽ� ���Ϳ� �����ϰ�, �ڽ� ������ �θ� �θ� ���� ����
		for (int i = 0; i < delNode->childList.size(); i++) {
			parNode->childList.push_back(delNode->childList[i]);
			delNode->childList[i]->parent = parNode;
		}
		vector<node*>&child = parNode->childList; // �θ� ����� �ڽĵ��� ��� ����
		child.erase(child.begin() + find(data, child)); // �ڽ� ���Ϳ��� ��带 ����
		delete nodeList[idx]; // �޸� �Ҵ� ����
		nodeList.erase(nodeList.begin() + idx); // ��� ���Ϳ��� ��带 ����
		return;
	}

	void printParent(int data) {
		int idx = find(data, nodeList);
		// �ش� ��尡 ���� ���
		if (idx == -1) {
			cout << -1 << endl;
			return;
		}
		// �ش� ��尡 root�� ���
		if (idx == 0) {
			cout << -1 << endl;
			return;
		}
		cout << nodeList[idx]->parent->data << endl;
	}

	void printChild(int data) {
		int idx = find(data, nodeList);
		// �ش� ��尡 ���� ���
		if (idx == -1) {
			cout << -1 << endl;
			return;
		}
		// �ش� ����� �ڽ� ��尡 ���� ���
		if (nodeList[idx]->childList.size() == 0) {
			cout << -1 << endl;
			return;
		}
		vector<node*>& list = nodeList[idx]->childList;
		for (int i = 0; i < list.size(); i++) {
			cout << list[i]->data << " ";
		}
		cout << endl;
	}

	void maxChild(int data) {
		int idx = find(data, nodeList);
		// �ش� ��尡 ���� ���
		if (idx == -1) {
			cout << -1 << endl;
			return;
		}
		// �ش� ����� �ڽ� ��尡 ���� ���
		if (nodeList[idx]->childList.size() == 0) {
			cout << -1 << endl;
			return;
		}
		vector<node*>& list = nodeList[idx]->childList;
		int max = list[0]->data; // �ִ밪�� �ڽĵ� �� ù��° ������ �ʱ�ȭ
		for (int i = 1; i < list.size(); i++) {
			if (list[i]->data > max) {
				max = list[i]->data;
			} // �ڽ� ���� ��, max���� ū �����͸� �����ٸ� max�� �� ������ ����
		}
		cout << max << endl;
	}
};

int main() {
	int t;
	cin >> t;
	Tree tree(1); // �ʱ⿡ ��Ʈ�� 1
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		int pardata, data;
		if (s == "insert") {
			cin >> pardata >> data;
			tree.insertNode(pardata, data);
		}
		else if (s == "delete") {
			cin >> data;
			tree.deleteNode(data);
		}
		else if (s == "parent") {
			cin >> data;
			tree.printParent(data);
		}
		else if (s == "child") {
			cin >> data;
			tree.printChild(data);
		}
		else if (s == "maxChild") {
			cin >> data;
			tree.maxChild(data);
		}
	}
}