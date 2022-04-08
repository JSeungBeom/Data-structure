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
	}

	void add(int idx, int value) {
		for (int i = arrsize - 2; i >= idx; i--) {
			arr[i + 1] = arr[i];
		}
		arr[idx] = value;
	}

	void shift(int len) {
		len %= arrsize;
		int* temp = new int[arrsize];
		for (int i = len; i < arrsize; i++) {
			temp[i] = arr[i - len];
		}
		for (int i = arrsize - len; i < arrsize; i++) {
			temp[i - arrsize + len] = arr[i];
		}
		for (int i = 0; i < arrsize; i++) {
			cout << temp[i] << " ";
		}
		cout << endl;
	}

	void reverse() {
		int n = arrsize - 1;
		for (int i = 0; i < n; i++) {
			int temp = arr[i];
			arr[i] = arr[n];
			arr[n] = temp;
			n--;
		}
		for (int i = 0; i < arrsize; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, d;
		cin >> n >> d;
		Array arr(n);
		for (int j = 0; j < n; j++) {
			int value;
			cin >> value;
			arr.add(j, value);
		}
		arr.shift(d);
		arr.reverse();
	}
}