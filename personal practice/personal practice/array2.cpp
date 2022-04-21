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
		int* temp = new int[d];
		for (int i = 0; i < d; i++) {
			temp[i] = arr[capacity - d + i];
		}
		for (int i = capacity - d - 1; i >= 0; i--) {
			arr[i + d] = arr[i];
		}
		for (int i = 0; i < d; i++) {
			arr[i] = temp[i];
		}
	}

	void reverse(int x, int y) {
		for (int i = x; i < y; i++) {
			int temp = arr[i];
			arr[i] = arr[y];
			arr[y] = temp;
			y--;
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
			int x, y;
			cin >> x >> y;
			arr.reverse(x, y);
		}
		if (s == "print") {
			arr.print();
		}
	}
}