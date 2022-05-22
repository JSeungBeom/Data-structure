#include <iostream>
#include <vector>	

using namespace std;

// Array-based Heap
// Complete Binary Tree는 Array와 구조적으로 1 : 1 대응 관계
// PriorityQueue의 구현 -> 정렬된 시퀀스, 정렬되지 않은 시퀀스, Heap
class heap {
private:
	vector<int> arr; // 힙의 원소를 저장하는 벡터

	// 힙의 원소를 교체, O(1) time
	void swap(int idx1, int idx2) {
		arr[0] = arr[idx1];
		arr[idx1] = arr[idx2];
		arr[idx2] = arr[0];
	}

	// idx의 원소에서 upHeap을 수행, O(log n) time (트리의 높이가 O(log n)이므로)
	void upHeap(int idx) {
		if (idx == 1) // root에 도달할 경우, 종료
			return;

		int parent = idx / 2; // 노드의 부모 노드의 인덱스 -> i / 2
		if (arr[parent] > arr[idx]) { // 부모 노드의 우선 순위가 현재 노드보다 낮다면
			swap(parent, idx); // 두 노드의 원소를 교체
			upHeap(parent); // 부모 노드를 따라가며 순서 조건 만족
		}

	}

	// idx의 원소에서 downHeap을 수행, O(log n) time (트리의 높이가 O(log n)이므로)
	void downHeap(int idx) {
		int left = 2 * idx;
		int right = 2 * idx + 1;
		int child;
		// 두 자식 모두 존재 X
		if (left > size()) {
			return;
		}
		else if (left == size()) { // 왼쪽 자식만 존재할 경우
			child = left;
		}
		else { // 두 자식 모두 존재할 경우, 더 작은 자식이 child
			if (arr[left] <= arr[right]) { 
				child = left;
			}
			else {
				child = right;
			}
		}

		if (arr[child] < arr[idx]) { // 자식 노드가 해당 노드보다 우선 순위가 높을 경우
			swap(child, idx); // 두 노드를 교체
			downHeap(child); // 자식 노드를 따라가며 순서 조건 만족
		}
	}

public:
	// 생성자, 0번 인덱스는 비워 놓는다
	heap() {
		arr.push_back(0); 
	}
	int size() {
		return arr.size() - 1;
	}
	
	bool empty() {
		return (arr.size() == 1);
	}

	// 힙에 원소 e 삽입, O(log n) time (트리의 높이가 O(log n)이므로)
	void insert(int e) { 
		arr.push_back(e); // 힙의 마지막에 원소 삽입
		upHeap(size()); // 해당 원소에서 upHeap으로 순서조건 만족
	}

	// 우선 순위가 가장 높은 원소 리턴, O(1) time
	int min() {
		if (empty()) {
			return -1;
		}

		return arr[1]; // root의 원소가 우선 순위가 가장 높다
	}
	
	// 우선 순위가 가장 높은 원소 삭제, O(log n) time (트리의 높이가 O(log n)이므로)
	void removeMin() { 
		if (empty()) {
			return;
		}

		swap(1, size()); // root의 원소와 마지막 노드의 원소 교체
		arr.pop_back(); // 마지막 노드 삭제
		downHeap(1); // root에서 downHeap 수행하여 순서조건 만족
	}
};

/*
	Selection Sort -> O(n^2) time
	Insertion Sort -> O(n^2) time
	Heap Sort -> O(nlogn) time
*/