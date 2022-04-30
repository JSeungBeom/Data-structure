#include <iostream>
#include <vector>

using namespace std;

// 연산자 오버로딩, e1이 e2보다 작다면(우선순위가 높다면) true
struct compare {
	bool operator()(const int& e1, const int& e2)const {
		return e1 < e2;
	}
};

class sortedSeqPQ {
private:
	// 정렬되지 않은 시퀀스
	vector <int> seq;

public:
	// 시퀀스의 크기 리턴
	int size() {
		return seq.size();
	}

	// 시퀀스가 비었는지 판단
	bool empty() {
		return (seq.size() == 0);
	}

	// 시퀀스에 요소 삽입, 정렬된 상태로 삽입 된다
	void insert(int e) {
		compare C;

		int i;
		for (i = 0; i < seq.size(); i++) {
			if (C(seq[i], e)) {
				break;
			}
		}
		seq.insert(seq.begin() + i, e);
	}

	int min() {
		if (empty()) {
			return -1;
		}
		
		return seq.back();
	}

	void removeMin() {
		if (empty()) {
			return;
		}

		seq.pop_back();
	}
};

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int N;
		cin >> N;
		sortedSeqPQ pq;
		for (int i = 0; i < N; i++) {
			int n;
			cin >> n;
			pq.insert(n);
		}
		while (!pq.empty()) {
			cout << pq.min() << " ";
			pq.removeMin();
		}
		cout << endl;
	}
}