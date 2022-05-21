#include <iostream>
#include <vector>

using namespace std;

// 비교자
struct compare {
	bool operator()(const int e1, const int e2) {
		return e1 > e2;
	}
};

// 정렬되지 않은 시퀀스로 우선순위 큐 구현, 선택정렬 기능
class unsortedSeqPQ {
private:
	vector<int>seq;

public:
	int size() {
		return seq.size();
	}

	bool empty() {
		return (seq.size() == 0);
	}

	// 큐에 원소 삽입, O(1) time
	void insert(int e) {
		seq.push_back(e); // 그냥 뒤에 삽입
	}

	// 큐의 우선 순위가 가장 높은 원소 리턴, O(n) time
	int max() {
		if (empty()) {
			return -1;
		}

		compare C;
		int maxVal = seq[0];

		for (int i = 0; i < seq.size(); i++) {
			if (C(seq[i], maxVal)) { // 큐의 요소가 maxVal보다 우선순위가 높다면
				maxVal = seq[i]; // maxVal이 해당 요소
			}
		}
		return maxVal;
	}

	// 큐의 우선 순위가 가장 높은 원소 삭제, O(n) time
	void removeMax() {
		if (empty()) {
			return;
		}

		compare C;
		int maxIdx = 0;

		for (int i = 0; i < seq.size(); i++) {
			if (C(seq[i], seq[maxIdx])) { // 해당 인덱스에서 maxIdx에서의 요소보다 우선순위가 높다면
				maxIdx = i; // maxIdx는 해당 인덱스
			}
		}

		seq.erase(seq.begin() + maxIdx); // maxIdx의 요소 삭제
	}
};

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		unsortedSeqPQ pq;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			pq.insert(x);
		}

		while (!pq.empty()) {
			cout << pq.max() << " ";
			pq.removeMax();
		}

		cout << endl;
	}
}