#include <iostream>

using namespace std;

class arrayVector {
private:
	int capacity;
	int n;
	int* arr;
	// ������ ũ�⸦ doubling
	void reserve(int size) {
		// capacity�� �̹� size���� ũ�ٸ� ����
		if (size <= capacity) {
			return;
		}
		// arr�� ��ҵ��� �ӽ� ������ �迭
		int* arrTemp = new int[size];
		// ��ҵ��� ����
		for (int i = 0; i < n; i++) {
			arrTemp[i] = arr[i];
		}
		// arr�� NULL�� �ƴ϶�� �޸� �Ҵ� ����
		if (arr != NULL) {
			delete[] arr;
		}
		// arrTemp�� �迭�� arr�� ����
		arr = arrTemp;
		//capacity�� size�� ������Ʈ
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

	// idx �տ� �����͸� ����
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