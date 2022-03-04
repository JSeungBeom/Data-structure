#include <iostream>

using namespace std;

class Array {
private:
	int* arr;
	int arraysize;

public:
	Array(int n) {
		this->arraysize = n;
		this->arr = new int[arraysize]; // 입력받은 n의 크기를 갖는 동적배열을 생성한다
		for (int i = 0; i < arraysize; i++) {
			arr[i] = 0;
		} // 동적배열의 요소들을 0으로 초기화한다
	}


	void find(int val) {
		int cnt = 0;
		for (int i = 0; i < arraysize; i++) {
			if (arr[i] == val) {
				cnt++;
			}
		}
		cout << cnt << endl;
	}

	void add(int index, int val) {
		for (int i = arraysize - 2; i >= index; i--) {
			arr[i + 1] = arr[i];
		} // index에 요소를 추가하고자 하니, index ~ n - 2번째까지의 요소들은 뒤로 한 칸씩 shift하게 된다. 이 때 맨 마지막 index의 요소는 버려지게 된다.
		arr[index] = val;
	} // 배열에 요소를 추가하는 함수

	void set(int index, int val) {
		arr[index] = val; // 단순히 index에 있는 요소를 변경하므로, 해당 index에 값을 삽입만 해주면 된다
	} // 배열에 요소를 바꾸는 함수

	void remove(int index) {
		for (int i = index + 1; i < arraysize; i++) {
			arr[i - 1] = arr[i];
		} // index에 요소를 삭제하고자 하니, index + 1 ~ n - 1의 요소들을 한 칸씩 앞으로 shift하게 된다. 이 때 맨 마지막 index의 요소는 0이 된다.
		arr[arraysize - 1] = 0;
	} // 배열에 요소를 삭제하는 함수

	void print() {
		for (int i = 0; i < arraysize; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	} // 배열을 출력하는 함수

};

int main() {
	int t, n;
	cin >> t >> n;
	Array ar(n); // 객체 생성, 생성자 호출


	for (int j = 0; j < t; j++) {
		string input;
		cin >> input;
		int i, z;
		if (input == "add") {
			cin >> i >> z;
			ar.add(i, z);
		}
		else if (input == "remove") {
			cin >> i;
			ar.remove(i);
		}
		else if (input == "set") {
			cin >> i >> z;
			ar.set(i, z);
		}
		else if (input == "print") {
			ar.print();
		}
		else if (input == "find") {
			cin >> i;
			ar.find(i);
		}
		else
			break;
	}

	return 0;
}
