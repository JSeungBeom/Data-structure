#include <iostream>

using namespace std;

struct node {
	node* next;
	node* prev;
	int data;
};

class nodeList {
private:
	node* header;
	node* trailer;
	int n;

public:
	// 생성자, 초기 상태는 header와 trailer 노드가 서로 연결된 형태
	nodeList() {
		header = new node;
		trailer = new node;
		header->next = trailer;
		trailer->prev = header;
		header->prev = trailer->next = NULL;
		n = 0;
	}

	// list의 크기 리턴
	int size() {
		return n;
	}

	// list가 비었는지 확인
	bool empty() {
		return (n == 0);
	}

	// list의 header의 next 주소값 리턴
	node* begin() {
		return header->next;
	}

	// list의 trailer의 주소값 리턴
	node* end() {
		return trailer;
	}

	// list의 pos 앞에 data를 삽입
	void insert(node* pos, int data) {
		node* newNode = new node;
		newNode->data = data;
		newNode->next = pos;
		newNode->prev = pos->prev; // newNode가 양 쪽 노드에 붙은 형태
		pos->prev->next = newNode;
		pos->prev = newNode; // 양 쪽 노드를 newNode에 연결
		n++;
	}

	// list의 pos를 삭제
	node* erase(node* pos) {
		if (empty()) {
			cout << "Empty" << endl;
			return pos; 
		}
		if (pos == end()) {
			return pos;
		}
		pos->prev->next = pos->next;
		pos->next->prev = pos->prev; // pos의 양 쪽 노드를 서로 연결
		delete pos; // pos 삭제
		n--;
		return begin(); // p의 주소값을 다시 begin()으로 초기화
	}

	// p를 다음 노드로 이동
	node* nextP(node* p) {
		if (p != end())
			return p->next;
		else
			return p;
	}

	// p를 이전 노드로 이동
	node* prevP(node* p) {
		if (p != begin())
			return p->prev;
		else
			return p;
	}

	// 리스트의 요소들을 출력
	void print() {
		if (empty()) {
			cout << "Empty" << endl;
			return;
		}
		node* curNode = begin();
		while (curNode != end()) {
			cout << curNode->data << " ";
			curNode = curNode->next;
		}
		cout << endl;
	}

	// data보다 큰 요소들의 인덱스를 리스트에서 출력
	void upper(int data) {
		node* curNode = begin();
		bool flag = false;
		int idx = 0;
		while (curNode != end()) {
			if (curNode->data > data) {
				cout << idx << " ";
				flag = true;
			}
			curNode = curNode->next;
			idx++;
		}
		if (flag == false) {
			cout << -1;
		}
		cout << endl;
	}
};
int main() {
	int n;

	cin >> n;
	nodeList list;
	node* p = list.begin(); // p의 초기값은 begin()

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "begin") {
			p = list.begin();
		}
		else if (s == "end") {
			p = list.end();
		}
		else if (s == "insert") {
			int data;
			cin >> data;
			list.insert(p, data);
		}
		else if (s == "erase") {
			p = list.erase(p);
		}
		else if (s == "nextP") {
			p = list.nextP(p);
		}
		else if (s == "prevP") {
			p = list.prevP(p);
		}
		else if (s == "print") {
			list.print();
		}
		else if (s == "upper") {
			int data;
			cin >> data;
			list.upper(data);
		}
		else
			break;
	}
}