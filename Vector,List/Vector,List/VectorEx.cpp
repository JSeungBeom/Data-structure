#include <iostream>

using namespace std;

class arrayVector {
private:
	int capacity;
	int n;
	int* arr;
	// 배열의 최대 크기를 size로 변경하는 함수
	void reverse(int size) {
		if (capacity >= size) {
			return; 
		} // capacity가 size보다 이미 크다면 종료

		int* arrTemp = new int[size]; // 요소를 임시 저장할 배열
		for (int i = 0; i < n; i++) {
			arrTemp[i] = arr[i];
		} // arr의 요소들을 임시 배열에 복사

		if (arr != NULL) {
			delete[]arr;
		} // arr이 NULL이 아니라면 메모리 해제

		arr = arrTemp; // 임시 배열을 arr에 얕은 복사
		capacity = size; // 최대 크기를 size로 업데이트
	}

public:
	// 생성자
	arrayVector() {
		capacity = 1;
		n = 0;
		arr = NULL;
	}

	// 벡터의 크기 리턴
	int size() {
		return n;
	}

	// 벡터가 비었는지 판단
	bool empty() {
		return (n == 0);
	}

	// 벡터의 idx 요소를 리턴
	int at(int idx) {
		if (idx < 0 || idx >= n) {
			return -1;
		}
		return arr[idx];
	}

	// 벡터의 idx 요소를 data로 변경
	void set(int idx, int data) {
		if (idx < 0 || idx >= n) {
			return;
		}
		arr[idx] = data;
	}

	// 벡터의 idx 요소를 삭제
	void erase(int idx) {
		if (idx < 0 || idx >= n) {
			return;
		}
		for (int i = idx + 1; i < n; i++) {
			arr[i - 1] = arr[i];
		}
		n--;
	}

	// 벡터의 idx에 data를 삽입
	void insert(int idx, int data) {
		if (idx < 0 || idx > n){
			return;
		}
		if (n == capacity){
			reverse(capacity * 2);
		}
		for (int i = n - 1; i >= idx; i--) {
			arr[i + 1] = arr[i];
		}
		arr[idx] = data;
		n++;
	}
};

/*
	배열을 이용한 벡터의 구현에서, O(N)의 공간 복잡도를 가지고, insert와 delete 기능은
	worst-case에 O(n)의 time complexity를 갖는다. 그 외 set, at, empty, size의 기능들은
	O(1)의 time complextiy를 갖는다. 예외적으로 벡터의 크기를 조절하는 reverse 함수 또한 O(n)의
	time complexity를 갖는다.
*/
