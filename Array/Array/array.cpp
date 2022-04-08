#include <iostream>

using namespace std;

class Array {
private:
	int* arr;
	int arrsize;

public:
	Array(int arrsize) {
		this->arrsize = arrsize;
		arr = new int[arrsize];
		for (int i = 0; i < arrsize; i++) {
			arr[i] = 0;
		}
	}

	int at(int idx) {
		return arr[idx];
	}

	void add(int idx, int value) {
		for (int i = arrsize - 2; i >= idx; i--) {
			arr[i + 1] = arr[i];
		}
		arr[idx] = value;
	}

	void remove(int idx) {
		for (int i = idx + 1; i < arrsize; i++) {
			arr[i - 1] = arr[i];
		}
		arr[arrsize - 1] = 0;
	}

	void set(int idx, int value) {
		arr[idx] = value;
		cout << value << endl;
	}

	void print() {
		for (int i = 0; i < arrsize; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	void find_max() {
		int max = arr[0];
		for (int i = 1; i < arrsize; i++) {
			if (arr[i] > max) {
				max = arr[i];
			}
		}
		cout << max << endl;
	}
};

int main() {
	int n, t;
	cin >> n >> t;
	Array arr(n);
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		int idx, value;
		if (s == "at") {
			cin >> idx;
			cout << arr.at(idx) << endl;
		}
		else if (s == "add") {
			cin >> idx >> value;
			arr.add(idx, value);
		}
		else if (s == "remove") {
			cin >> idx;
			arr.remove(idx);
		}
		else if (s == "set") {
			cin >> idx >> value;
			arr.set(idx, value);
		}
		else if (s == "print") {
			arr.print();
		}
		else if (s == "find_max") {
			arr.find_max();
		}
	}
}