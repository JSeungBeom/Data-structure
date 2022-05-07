#include <iostream>
#include <vector>

using namespace std;

class heap {
private:
	vector<int>arr;

	// 배열 기반 Tree에서 사용하지 않는 0번 인덱스를 이용하여,
	// 두 인덱스에 저장된 요소를 교환
	void swap(int idx1, int idx2) {
		arr[0] = arr[idx1];
		arr[idx1] = arr[idx2];
		arr[idx2] = arr[0];
	}

	// 힙에 요소를 추가할 때, 순서 조건을 만족하기 위해 upHeap
	// 최악의 경우, 트리의 높이만큼 O(log n)time에 수행
	void upHeap(int idx) {
		if (idx == 1) // root일 경우
			return;

		int parent = idx / 2; // 부모의 인덱스 계산
		// 부모의 값이 더 크다면 (순서 조건이 맞지 않는 경우)
		if (arr[parent] > arr[idx]) {
			swap(parent, idx);
			upHeap(parent);
		}
	}

	// 힙의 최솟값을 삭제할 때, 마지막 노드의 값이 루트 노드에 덮어지므로
	// 순서 조건을 만족하기 위해, downHeap, 최악의 경우 O(log n)time에 수행
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
			if (arr[left] <= arr[right])
				child = left;
			else
				child = right;
		}

		if (arr[child] < arr[idx]) {
			swap(child, idx);
			downHeap(child);
		}
	}

public:
	// 생성자, 배열의 0번 인덱스는 사용 X (순서 조건 유지)
	heap() {
		arr.push_back(0);
	}

	int size() {
		return arr.size() - 1;
	}

	bool empty() {
		return (arr.size() == 1);
	}

	// 마지막 노드 다음 노드에 요소를 삽입하고,
	// 순서 조건을 만족하기 위해 upHeap 
	void insert(int e) {
		arr.push_back(e);
		upHeap(size());
	}

	// 가장 작은 원소를 리턴 
	int min() {
		if (empty()) {
			return -1;
		}
		return arr[1]; // root에 저장된 원소 리턴
	}

	// 가장 작은 요소를 삭제
	void removeMin() {
		if (empty()) {
			cout << -1 << endl;
			return;
		}

		cout << min() << endl;
		swap(1, size()); // 루트 노드의 값과, 마지막 노드의 값을 swap
		arr.pop_back(); // 마지막 노드를 삭제
		downHeap(1); // 루트 노드의 순서 조건을 만족하기 위해 downHeap
	}

	void print() {
		if (empty()) {
			cout << -1 << endl;
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
	heap h;
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		if (s == "isEmpty") {
			if (h.empty()) {
				cout << 1 << endl;
			}
			else
				cout << 0 << endl;
		}
		if (s == "size") {
			cout << h.size() << endl;
		}
		if (s == "insert") {
			int e;
			cin >> e;
			h.insert(e);
		}
		if (s == "pop") {
			h.removeMin();
		}
		if (s == "top") {
			cout << h.min() << endl;
		}
		if (s == "print") {
			h.print();
		}
	}
}