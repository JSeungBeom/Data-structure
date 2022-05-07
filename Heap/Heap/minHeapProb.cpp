#include <iostream>	
#include <vector>

using namespace std;

class minHeap {
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
		if (arr[parent] > arr[idx]) {
			swap(parent, idx);
			upHeap(parent);
		}
	}

	void downHeap(int idx) {
		int left = 2 * idx;
		int right = 2 * idx + 1;
		int child;

		if (left > size()) {
			return;
		}
		else if (left == size()) {
			child = left;
		}
		else {
			if (arr[left] <= arr[right]) {
				child = left;
			}
			else {
				child = right;
			}
		}

		if (arr[child] < arr[idx]) {
			swap(child, idx);
			downHeap(child);
		}
	}
public:
	minHeap() {
		arr.push_back(0);
	}

	int size() {
		return arr.size() - 1;
	}

	bool empty() {
		return (arr.size() == 1);
	}

	void insert(int e) {
		arr.push_back(e);
		upHeap(size());
	}

	int min() {
		if (empty()) {
			return -1;
		}

		return arr[1];
	}

	void removeMin() {
		if (empty()) {
			return;
		}

		swap(1, size());
		arr.pop_back();
		downHeap(1);
	}

	void print() {
		if (empty()) {
			return;
		}

		for (int i = 1; i <= size(); i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++) {
		int n, p;
		cin >> n >> p;
		minHeap h;
		int count = 0;

		for (int i = 0; i < n; i++) {
			int k;
			cin >> k;
			h.insert(k);
		}

		while (true) {
			if (h.min() >= p) {
				cout << count << endl;
				h.print();
				break;
			}
			if (h.size() <= 2) {
				cout << "False" << endl;
				break;
			}
			int a = h.min();
			h.removeMin();
			int b = h.min();
			h.removeMin();
			int c = h.min();
			h.removeMin();

			int max = a, min = a;
			if (max < b) {
				max = b;
			}
			if (max < c) {
				max = c;
			}
			if (min > b) {
				min = b;
			}
			if (min > b) {
				min = b;
			}

			int result = (max + min) / 2;
			h.insert(result);
			count++;
		}
	}
}