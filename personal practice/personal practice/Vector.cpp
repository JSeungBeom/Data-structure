#include <iostream>

using namespace std;

class arrayVector {
private:
	int capacity;
	int n;
	int* arr;
	// 벡터의 크기를 doubling
	void reserve(int size) {
		// capacity가 이미 size보다 크다면 종료
		if (size <= capacity) {
			return;
		}
		// arr의 요소들을 임시 저장할 배열
		int* arrTemp = new int[size];
		// 요소들을 복사
		for (int i = 0; i < n; i++) {
			arrTemp[i] = arr[i];
		}
		// arr이 NULL이 아니라면 메모리 할당 해제
		if (arr != NULL) {
			delete[] arr;
		}
		// arrTemp의 배열을 arr에 복사
		arr = arrTemp;
		//capacity를 size로 업데이트
		capacity = size;
	}

public:
	arrayVector(int capacity){
		this->capacity = capacity;
		arr = new int[capacity];
		n = 0;
	}

	int size() {
		return n;
	}

	bool empty() {
		return (n == 0);
	}

	int at(int idx) {
		if (idx < 0 || idx >= n) {
			return -1;
		}
		return arr[idx];
	}

	void set(int idx, int data) {
		if (idx < 0 || idx >= n) {
			return;
		}
		arr[idx] = data;
	}

	void erase(int idx) {
		if (idx < 0 || n <= idx) {
			return;
		}
		for (int i = idx + 1; i < capacity; i++) {
			arr[i - 1] = arr[i];
		}
		n--;
	}

	// idx 앞에 데이터를 삽입
	void insert(int idx, int data) {
		if (idx < 0 || idx > capacity) {
			return;
		}
		if (n == capacity) {
			reserve(2 * capacity);
		}
		for (int i = n - 1; i >= idx; i--) {
			arr[i + 1] = arr[i];
		}
		n++;
	}
};