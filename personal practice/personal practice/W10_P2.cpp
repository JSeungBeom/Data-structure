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
			if (arr[left] <= arr[right]) {
				child = right;
			}
			else {
				child = left;
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
		if (empty()) {
			return;
		}
		
		swap(1, size());
		arr.pop_back();
		downHeap(1);
	}

	void print() {
		for (int i = 1; i < arr.size(); i++) {
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
		heap h;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int k;
			cin >> k;
			h.insert(k);
		}

		while (true) {
			if (h.max() <= p) {
				cout << cnt << endl;
				h.print();
				break;
			}
			if (h.size() <= 2 && h.max() > p) {
				cout << "False" << endl;
				break;
			}
			int* temp = new int[3];
			for (int i = 0; i < 3; i++) {
				temp[i] = h.max();
				h.removeMax();
			}
			
			int max = temp[0];
			int min = temp[0];
			cnt++;

			for (int i = 0; i < 3; i++) {
				if (temp[i] > max) {
					max = temp[i];
				}
			}

			for (int i = 0; i < 3; i++) {
				if (temp[i] < max) {
					min = temp[i];
				}
			}

			int result = (max + min) / 2;
			h.insert(result);
			if (result <= p) {
				cout << cnt << endl;
				h.print();
				break;
			}
		}
	}
}