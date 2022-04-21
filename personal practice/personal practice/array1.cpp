#include <iostream>

using namespace std;

class Array {
private:
	int* arr;
	int capacity;

public:
	Array(int capacity) {
		this->capacity = capacity;
		arr = new int[capacity];
		for (int i = 0; i < capacity; i++) {
			arr[i] = 0;
		}
	}

	void add(int idx, int data) {
		for (int i = capacity - 2; i >= idx; i--) {
			arr[i + 1] = arr[i];
		}
		arr[idx] = data;
	}

	void remove(int idx) {
		for (int i = idx + 1; i < capacity; i++) {
			arr[i - 1] = arr[i];
		}
		arr[capacity - 1] = 0;
	}

	void set(int idx, int data) {
		arr[idx] = data;
	}

	void print() {
		for (int i = 0; i < capacity; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	void find(int data) {
		for (int i = 0; i < capacity; i++) {
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
		int idx, data;
		if (s == "add") {
			cin >> idx >> data;
			arr.add(idx, data);
		}
		if (s == "remove") {
			cin >> idx;
			arr.remove(idx);
		}
		if (s == "set") {
			cin >> idx >> data;
			arr.set(idx, data);
		}
		if (s == "print") {
			arr.print();
		}
		if (s == "find") {
			cin >> data;
			arr.find(data);
		}
	}
}