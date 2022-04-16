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

	void set(int idx, int data) {
		arr[idx] = data;
	}

	void add(int idx, int data) {
		for (int i = arrsize - 2; i >= idx; i--) {
			arr[i + 1] = arr[i];
		}
		arr[idx] = data;
	}

	void remove(int idx) {
		for (int i = idx + 1; i < arrsize; i++) {
			arr[i - 1] = arr[i];
		}
		arr[arrsize - 1] = 0;
	}

	void print() {
		for (int i = 0; i < arrsize; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	void find(int data) {
		int cnt = 0;
		for (int i = 0; i < arrsize; i++) {
			if (arr[i] == data) {
				cnt++;
			}
		}
		cout << cnt << endl;
	}
};

int main() {
	int t, n;
	cin >> t >> n;
	Array arr(n);
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		int data, idx;
		if (s == "add") {
			cin >> idx >> data;
			arr.add(idx, data);
		}
		else if (s == "remove") {
			cin >> idx;
			arr.remove(idx);
		}
		else if (s == "set") {
			cin >> idx >> data;
			arr.set(idx, data);
		}
		else if (s == "print") {
			arr.print();
		}
		else if (s == "find") {
			cin >> data;
			arr.find(data);
		}
	}
}