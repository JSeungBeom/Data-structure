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
			cin >> arr[i];
		}
	}

	void shift(int d) {
		int* temp = new int[d];
		for (int i = 0; i < d; i++) {
			temp[i] = arr[arrsize - d + i];
		}
		for (int i = arrsize - d - 1; i >= 0; i--) {
			arr[i + d] = arr[i];
		}
		for (int i = 0; i < d; i++) {
			arr[i] = temp[i];
		}
	}

	void reverse(int start, int end) {
		for (int i = start; i <= end; i++) {
			int temp = arr[i];
			arr[i] = arr[end];
			arr[end] = temp;
			end--;
		}
	}

	void print() {
		for (int i = 0; i < arrsize; i++) {
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
		else if (s == "reverse") {
			int start, end;
			cin >> start >> end;
			arr.reverse(start, end);
		}
		else if (s == "print") {
			arr.print();
		}
	}
}