#include <iostream>

using namespace std;

class Array {
private:
	int capacity;
	int* arr;

public:
	Array(int capacity) {
		this->capacity = capacity;
		arr = new int[capacity];
		for (int i = 0; i < capacity; i++) {
			arr[i] = 0;
		}
	}
	
	int at(int idx) {
		return arr[idx];
	}

	void add(int idx, int data) {
		if (idx < 0 || idx > capacity) {
			return;
		}
		for (int i = capacity - 2; i >= idx; i--) {
			arr[i + 1] = arr[i];
		}
		arr[idx] = data;
	}

	void remove(int idx) {
		if (idx < 0 || idx >= capacity){
			return;
		}
		for (int i = idx + 1; i < capacity; i++) {
			arr[i - 1] = arr[i];
		}
		arr[capacity - 1] = 0;
	}

	void find1(int data) {
		int cnt = 0;
		for (int i = 0; i < capacity; i++) {
			if (arr[i] == data) {
				cnt++;
			}
		}
		cout << cnt << endl;
	}

	void find2(int data) {
		for (int i = 0; i < capacity; i++) {
			if (arr[i] == data) {
				cout << i << endl;
				return;
			}
		}
		cout << -1 << endl;
	}
	void set(int idx, int data) {
		if (idx < 0 || idx >= capacity) {
			return;
		}
		arr[idx] = data;
	}

	void print() {
		for (int i = 0; i < capacity; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	Array ar(5);

	ar.print();
	ar.add(0, 11);
	ar.add(1, 22);
	ar.add(2, 33);
	ar.add(2, 55);
	ar.print();
	ar.remove(2);
	ar.print();

	return 0;
}