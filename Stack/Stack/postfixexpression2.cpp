#include <iostream>

using namespace std;

struct node {
	char data; // 데이터 필드, 부호를 저장할 것이므로 char 타입
	node* next; // 링크 필드
};

class stack {
private:
	node* topNode; // singlylinkedlist에서의 head 역할
	int listsize; // 스택 사이즈

public:
	stack() {
		topNode = NULL;
		listsize = 0;
	} // 멤버변수 초기화

	int size() {
		return listsize;
	} // 스택의 사이즈 반환

	bool empty() {
		if (size() == 0) {
			return true;
		}
		else
			return false;
	} // 스택이 비었는지 판단

	bool isUpper(char data1, char data2) {
		if (data1 == '*' || data1 == '/') {
			return true;
		} // 이전 연산자가 *, / 였다면 무조건 다음 연산자보다 크니 true
		else if (data1 == '+' || data1 == '-') {
			if (data2 == '+' || data2 == '-')
				return true;
			else
				return false;
		} // 이전 연산자가 +, - 였다면 다음 연산자가 +, -이면 true, *, /라면 false 반환
		else
			return false;
	} // 연산자가 이전 연산자보다 큰지, 작은지 판단

	void push(char data) {
		int num = data - '0'; 
		if (num >= 1 && num <= 9) {
			cout << num;
			return;
		} // 데이터가 피연산자이면 출력하고 함수 종료
		while (!empty() && isUpper(topNode->data, data)) {
			pop();
		} // 들어오는 데이터의 연산자 우선 순위를 판단하여 pop() 함수 반복 수행
		node* newNode = new node; // 새 노드
		newNode->data = data; // 데이터 삽입
		newNode->next = topNode; // 새 노드의 next가 topNode
		topNode = newNode; // 새 노드가 topNode
		listsize++;  // *리스트사이즈를 증가
	}

	void pop() {
		if (empty()) {
			return;
		} // 스택이 비었다면 종료
		node* curNode = topNode; // 삭제될 노드는 topNode
		cout << curNode->data; // 삭제될 노드의 데이터를 출력
		topNode = topNode->next; // topNode는 topNode의 next
		delete curNode; // 이전 topNode를 삭제
		listsize--; // *리스트사이즈를 감소
	}
};

int main() {
	int t;
	
	cin >> t; // 수식의 수

	stack st;

	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			st.push(s[j]);
			if (j == s.length() - 1) {
				while (!st.empty()) {
					st.pop();
				}
			} // 수식이 끝났으므로, 스택에 남은 연산자를 모두 pop
		}
		cout << endl;
	}
}