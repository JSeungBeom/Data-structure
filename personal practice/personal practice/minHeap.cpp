#include <iostream>
#include <vector>	

using namespace std;

// Array-based Heap
// Complete Binary Tree�� Array�� ���������� 1 : 1 ���� ����
// PriorityQueue�� ���� -> ���ĵ� ������, ���ĵ��� ���� ������, Heap
class heap {
private:
	vector<int> arr; // ���� ���Ҹ� �����ϴ� ����

	// ���� ���Ҹ� ��ü, O(1) time
	void swap(int idx1, int idx2) {
		arr[0] = arr[idx1];
		arr[idx1] = arr[idx2];
		arr[idx2] = arr[0];
	}

	// idx�� ���ҿ��� upHeap�� ����, O(log n) time (Ʈ���� ���̰� O(log n)�̹Ƿ�)
	void upHeap(int idx) {
		if (idx == 1) // root�� ������ ���, ����
			return;

		int parent = idx / 2; // ����� �θ� ����� �ε��� -> i / 2
		if (arr[parent] > arr[idx]) { // �θ� ����� �켱 ������ ���� ��庸�� ���ٸ�
			swap(parent, idx); // �� ����� ���Ҹ� ��ü
			upHeap(parent); // �θ� ��带 ���󰡸� ���� ���� ����
		}

	}

	// idx�� ���ҿ��� downHeap�� ����, O(log n) time (Ʈ���� ���̰� O(log n)�̹Ƿ�)
	void downHeap(int idx) {
		int left = 2 * idx;
		int right = 2 * idx + 1;
		int child;
		// �� �ڽ� ��� ���� X
		if (left > size()) {
			return;
		}
		else if (left == size()) { // ���� �ڽĸ� ������ ���
			child = left;
		}
		else { // �� �ڽ� ��� ������ ���, �� ���� �ڽ��� child
			if (arr[left] <= arr[right]) { 
				child = left;
			}
			else {
				child = right;
			}
		}

		if (arr[child] < arr[idx]) { // �ڽ� ��尡 �ش� ��庸�� �켱 ������ ���� ���
			swap(child, idx); // �� ��带 ��ü
			downHeap(child); // �ڽ� ��带 ���󰡸� ���� ���� ����
		}
	}

public:
	// ������, 0�� �ε����� ��� ���´�
	heap() {
		arr.push_back(0); 
	}
	int size() {
		return arr.size() - 1;
	}
	
	bool empty() {
		return (arr.size() == 1);
	}

	// ���� ���� e ����, O(log n) time (Ʈ���� ���̰� O(log n)�̹Ƿ�)
	void insert(int e) { 
		arr.push_back(e); // ���� �������� ���� ����
		upHeap(size()); // �ش� ���ҿ��� upHeap���� �������� ����
	}

	// �켱 ������ ���� ���� ���� ����, O(1) time
	int min() {
		if (empty()) {
			return -1;
		}

		return arr[1]; // root�� ���Ұ� �켱 ������ ���� ����
	}
	
	// �켱 ������ ���� ���� ���� ����, O(log n) time (Ʈ���� ���̰� O(log n)�̹Ƿ�)
	void removeMin() { 
		if (empty()) {
			return;
		}

		swap(1, size()); // root�� ���ҿ� ������ ����� ���� ��ü
		arr.pop_back(); // ������ ��� ����
		downHeap(1); // root���� downHeap �����Ͽ� �������� ����
	}
};

/*
	Selection Sort -> O(n^2) time
	Insertion Sort -> O(n^2) time
	Heap Sort -> O(nlogn) time
*/