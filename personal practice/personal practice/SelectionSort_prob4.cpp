#include <iostream>
#include <vector>	

using namespace std;

struct compare {
	bool operator()(const int e1, const int e2) {
		if (e1 % 2 == 0 && e2 % 2 != 0) {
			return true;
		}
		else if (e1 % 2 != 0 && e2 % 2 == 0) {
			return false;
		}
		else {
			return e1 < e2;
		}
	}
};

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

	void insert(int e) {
		seq.push_back(e);
	}

	int min() {
		if (empty()) {
			return -1;
		}

		compare C;
		int minVal = seq[0];

		for (int i = 0; i < seq.size(); i++) {
			if (C(seq[i], minVal)) {
				minVal = seq[i];
			}
		}
		return minVal;
	}

	void removeMin() {
		if (empty()) {
			return;
		}

		compare C;
		int minIdx = 0;

		for (int i = 0; i < seq.size(); i++) {
			if (C(seq[i], seq[minIdx])) {
				minIdx = i;
			}
		}

		seq.erase(seq.begin() + minIdx);
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
			cout << pq.min() << " ";
			pq.removeMin();
		}
		cout << endl;
	}
}