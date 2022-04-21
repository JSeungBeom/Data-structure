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
			cin >> arr[i];
		}
	}

	void shift(int d) {
		int* temp = new int[capacity];
		
		for (int i = 0; i < d; i++) {
			temp[capacity - d + i] = arr[i];
		}
		for (int i = d; i < capacity; i++) {
			arr[i - d] = arr[i];
		}
		for (int i = capacity - d; i < capacity; i++) {
			arr[i] = temp[i];
		}
	}

	void reverse(int start, int end) {
		for (int i = start; i < end; i++) {
			int temp = arr[i];
			arr[i] = arr[end];
			arr[end] = temp;
			end--;
		}
	}

	void print() {
		for (int i = 0; i < capacity; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	int t, n;
	cin >> t >> n;
	Array arr(n);
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		if (s == "shift") {
			int d;
			cin >> d;
			arr.shift(d);
		}
		if (s == "reverse") {
			int st, en;
			cin >> st >> en;
			arr.reverse(st, en);
		}
		if (s == "print") {
			arr.print();
		}
	}
}