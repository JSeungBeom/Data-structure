#include <iostream>

using namespace std;

struct node {
	node* next;
	int data;
};

class queue {
private:
	node* frontNode;
	node* rearNode;
	int n;
	int point;


public:
	queue() {
		frontNode = rearNode = NULL;
		n = 0;
		point = 0;
	}
	
	int getpoint() {
		return point;
	}

	void addpoint() {
		point++;
	}

	int size() {
		return n;
	}

	bool empty() {
		return (n == 0);
	}

	int front() {
		if (empty()) {
			return -1;
		}
		return frontNode->data;
	}

	void enqueue(int data) {
		node* newNode = new node;
		newNode->data = data;
		newNode->next = NULL;
		if (empty()) {
			frontNode = rearNode = newNode;
		}
		else {
			rearNode->next = newNode;
			rearNode = newNode;
		}
		n++;
	}

	void dequeue() {
		if (empty()) {
			return;
		}
		node* curNode = frontNode;
		if (size() == 1) {
			frontNode = rearNode = NULL;
		}
		else {
			frontNode = frontNode->next;
		}
		delete curNode;
		n--;
	}

	void add(int dif) {
		if (empty()) {
			return;
		}
		frontNode->data += dif;
	}
};

int main() {
	int t; 

	cin >> t;


	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		queue p1;
		queue p2;
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			p1.enqueue(x);
		}
		for (int j = 0; j < n; j++) {
			int y;
			cin >> y;
			p2.enqueue(y);
		}

		for (int j = 1; j <= n; j++) {
			cout << "Round" << j << " ";
			int dif = abs(p1.front() - p2.front());
			if (p1.front() > p2.front()) {
				p1.addpoint();
				p1.dequeue();
				p2.dequeue();
				p1.add(dif);
				cout << p1.getpoint() << ":"
					<< p2.getpoint() << endl;
			}
			else if (p1.front() < p2.front()) {
				p2.addpoint();
				p1.dequeue();
				p2.dequeue();
				p2.add(dif);
				cout << p1.getpoint() << ":"
					<< p2.getpoint() << endl;
			}
			else {
				p1.dequeue();
				p2.dequeue();
				cout << p1.getpoint() << ":"
					<< p2.getpoint() << endl;
			}
		}
		if (p1.getpoint() > p2.getpoint()) {
			cout << "Winner P1" << endl;
		}
		else if (p1.getpoint() < p2.getpoint()) {
			cout << "Winner P2" << endl;
		}
		else {
			cout << "Draw" << endl;
		}
	}
}