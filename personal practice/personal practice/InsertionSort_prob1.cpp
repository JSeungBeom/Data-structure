#include <iostream>
#include <vector>	

using namespace std;

// 비교자
struct compare {
	// e1 < e2 -> true, e1 >= e2 -> false
	bool operator()(const int e1, const int e2) {
		return e1 < e2;
	}
};

//정렬된 시퀀스를 이용한 우선순위 큐 구현, 삽입 정렬 기능 수행
class sortedSeqPQ {
private:
	vector<int>seq;

public:
	int size() {
		return seq.size();
	}

	bool empty() {
		return (seq.size() == 0);
	}

	// 큐에 원소 삽입, O(n) time
	void insert(int e) {
		compare C; // 비교자 변수
		int idx = 0;
		for (idx = 0; idx < seq.size(); idx++) {
			if (C(seq[idx], e)) // 삽입할 원소보다 우선 순위가 높은 원소 탐색
				break;
		}
		seq.insert(seq.begin() + idx, e); // 해당 위치에 원소 삽입
	}

	// 우선순위가 가장 높은 원소 반환, O(1) time
	int min() {
		if (empty()) {
			return -1;
		}
		// 큐의 가장 마지막 원소 -> 우선순위가 가장 높은 원소
		return seq.back();
	}

	// 우선순위가 가장 높은 원소 삭제, O(1) time
	void removeMin() {
		if (empty()) {
			return;
		}

		// 큐의 가장 마지막 원소 삭제
		seq.pop_back(); 
	}
	
};

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		sortedSeqPQ pq;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			pq.insert(x);
		}
		
		while (!pq.empty()) {
			cout << pq.min() << " ";
			pq.removeMin();
		}
		cout << endl;
	}
}