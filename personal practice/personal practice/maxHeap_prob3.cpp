#include <iostream>
#include <vector>

using namespace std;

class heap {
private:
	vector<int>arr;
	void swap(int idx1, int idx2) {
		arr[0] = arr[idx1];
		arr[idx1] = arr[idx2];
		arr[idx2] = arr[0];
	}

	void upHeap(int idx) {
		if (idx == 1) {
			return;
		}

		int parent = idx / 2;

		if (arr[parent] < arr[idx]) {
			swap(parent, idx);
			upHeap(parent);
		}
	}
	void downHeap(int idx) {
		int left = idx * 2;
		int right = idx * 2 + 1;
		int child;

		if (left > size()) {
			return;
		}
		else if (left == size()) {
			child = left;
		}
		else {
			if (arr[left] >= arr[right]) {
				child = left;
			}
			else {
				child = right;
			}
		}

		if (arr[child] > arr[idx]) {
			swap(child, idx);
			downHeap(child);
		}
	}

public:
	heap() {
		arr.push_back(0);
	}

	int size() {
		return arr.size() - 1;
	}

	bool empty() {
		return (size() == 0);
	}

	void insert(int e) {
		arr.push_back(e);
		upHeap(size());
	}

	int max() {
		if (empty()) {
			return -1;
		}

		return arr[1];
	}

	void removeMax() {
		cout << max() << endl;
		if (empty()) {
			return;
		}

		swap(1, size());
		arr.pop_back();
		downHeap(1);
	}

	void print() {
		if (empty()) {
			cout << -1 << endl;
			return;
		}

		for (int i = 1; i < arr.size(); i++) {
			cout << arr[i] << " ";
		}

		cout << endl;
	}
};

int main() {
	int t;
	cin >> t;

	heap h;
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		if (s == "insert") {
			int e;
			cin >> e;
			h.insert(e);
		}
		if (s == "size") {
			cout << h.size() << endl;
		}
		if (s == "isEmpty") {
			if (h.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		if (s == "pop") {
			h.removeMax();
		}
		if (s == "top") {
			cout << h.max() << endl;
		}
		if (s == "print") {
			h.print();
		}
	}
}