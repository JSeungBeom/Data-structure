#include <iostream>
#include <vector>

using namespace std;

struct compare {
	bool operator()(const int& e1, const int& e2) {
		return e1 < e2;
	}
};

class sortedSqPQ {
private:
	vector<int>seq;

public:
	int size() {
		return seq.size();
	}

	bool empty() {
		return (seq.size() == 0);
	}

	void insert(int e) {
		compare C;
		int idx = 0;
		for (idx = 0; idx < seq.size(); idx++) {
			if (C(seq[idx], e))
				break;
		}
		seq.insert(seq.begin() + idx, e);
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
		int n;
		cin >> n;
		sortedSqPQ pq;
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