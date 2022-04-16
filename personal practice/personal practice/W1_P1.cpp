#include <iostream>

using namespace std;

class Array {
private:
	int* arr;
	int arrsize;

public:
	// 생성자
	Array(int arrsize) {
		this->arrsize = arrsize;
		arr = new int[arrsize];
		for (int i = 0; i < arrsize; i++) {
			arr[i] = 0;
		}
	}

	// 배열의 할당, idx번째 값을 data로 변경
	void set(int idx, int data) {
		if (idx < 0 || idx >= arrsize) {
			return;
		}
		arr[idx] = data;
	}

	// 배열의 삽입, arr[idx] ~ arr[n -2]를 오른쪽으로 이동시킨 뒤, 삽입
	void add(int idx, int data) {
		// exception handling
		if (idx < 0 || idx > arrsize) {
			return;
		}
		// 배열의 맨 뒤부터 요소들을 오른쪽으로 이동
		for (int i = arrsize - 2; i >= idx; i--) {
			arr[i + 1] = arr[i];
		}
		// 데이터 삽입
		arr[idx] = data;
	}

	// 배열의 삭제, arr[idx +1] ~ arr[arrsize - 1]을 왼쪽으로 이동
	void remove(int idx) {
		// exception handling
		if (idx < 0 || idx >= arrsize) {
			return;
		}
		// idx + 1부터 arrsize - 1을 왼쪽으로 이동시켜, 삭제된 공간을 채움
		for (int i = idx + 1; i < arrsize; i++) {
			arr[i - 1] = arr[i];
		}
		// 맨 뒤의 빈 공간을 0으로 채움
		arr[arrsize - 1] = 0;
	}
	
	// 배열 출력
	void print() {
		for (int i = 0; i < arrsize; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	// 배열에서 일치하는 요소를 찾아 인덱스 출력
	void find(int data) {
		for (int i = 0; i < arrsize; i++) {
			if (arr[i] == data) {
				cout << i << endl;
				return;
			}
		}
		cout << -1 << endl;
	}
};

int main() {
	int t, n;
	cin >> t >> n;
	Array arr(n);
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		int data, idx;
		if (s == "set") {
			cin >> idx >> data;
			arr.set(idx, data);
		}
		else if (s == "add") {
			cin >> idx >> data;
			arr.add(idx, data);
		}
		else if (s == "remove") {
			cin >> idx;
			arr.remove(idx);
		}
		else if (s == "print") {
			arr.print();
		}
		else if (s == "find") {
			cin >> data;
			arr.find(data);
		}
	}
}