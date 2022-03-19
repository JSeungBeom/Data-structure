#include <iostream>

using namespace std;

class stack {
private:
	int* arr; // 스택을 저장할 배열
	int capacity; // 배열의 최대 크기
	int topIndex; // 스택의 top 데이터의 index

public:
	stack(int capacity) {
		this->capacity = capacity; // 전달받은 parameter로 capcity 초기화
		topIndex = -1; // topIndex는 0부터 시작하므로, -1로 초기화
		arr = new int[capacity]; // arr을 동적 배열로 생성
	}

	int size() {
		return topIndex + 1; // 스택의 크기는 topIndex + 1
	} // 스택의 사이즈

	bool empty() {
		if (size() == 0) {
			return true;
		}
		else
			return false;
	} // 스택이 비었는지 판단할 함수

	int top() {
		if (empty()) {
			return -1;
		} // 스택이 비었을 경우, -1 반환
		return arr[topIndex]; // topIndex의 요소를 반환
	} // 가장 위에 있는 요소를 반환하는 함수

	void push(int data) {
		if (capacity == size()) {
			cout << "FULL" << endl;
			return;
		} // 배열의 수용 가능 크기를 넘어서면, FULL 출력
		arr[++topIndex] = data; // topIndex를 1 증가시키고, 그 index에 data 삽입
	} // 스택의 맨 위에 요소를 추가하는 함수

	int pop() {
		if (empty()) {
			return -1;
		} // 스택이 비었을 경우, -1 반환
		topIndex--;
		return arr[topIndex + 1]; // return하면 함수가 종료되므로, 일단 topIndex를 1 감소시키고 기존 top을 반환
	}
};

int main() {
	int t, n;

	cin >> t >> n; // 수용 가능한 크기, 명령어의 수

	stack st(t); // 객체 생성

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "top") {
			cout << st.top() << endl;
		}
		else if (s == "size") {
			cout << st.size() << endl;
		}
		else if (s == "push") {
			int data;
			cin >> data;
			st.push(data);
		}
		else if (s == "empty") {
			if (st.empty()) {
				cout << 1 << endl;
			}
			else
				cout << 0 << endl;
		}
		else if (s == "pop") {
			cout << st.pop() << endl;
		}
		else
			break;
	}
}