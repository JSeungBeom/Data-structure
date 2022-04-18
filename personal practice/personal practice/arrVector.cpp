#include <iostream>

using namespace std;

class arrayVector {
private:
	int* arr;
	int capacity;
	int n;
	// doubling size
	void reserve(int size) {
		if (size <= capacity) {
			return;
		}
		int* temp = new int[size];
		for (int i = 0; i < n; i++) {
			temp[i] = arr[i];
		}
		if (arr != NULL) {
			delete arr;
		}
		arr = temp;
		capacity = size;
	}

public:
	arrayVector() {
		capacity = 1;
		arr = NULL;
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
		if (idx < 0 || idx >= n) {
			return;
		}
		for (int i = idx + 1; i < n; i++) {
			arr[i - 1] = arr[i];
		}
		n--;
	}

	void insert(int idx, int data) {
		if (idx < 0 || idx > n) {
			return;
		}
		if (n == capacity) {
			reserve(2 * capacity);
		}
		for (int i = n - 1; i >= idx; i--) {
			arr[i + 1] = arr[i];;
		}
		arr[idx] = data;
		n++;
	}
};

int main() {

}