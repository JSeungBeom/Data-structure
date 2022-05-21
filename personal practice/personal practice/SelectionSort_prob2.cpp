#include <iostream>
#include <vector>

using namespace std;

struct compare {
	bool operator()(const int e1, const int e2) {
		if (e1 % 2 != 0 && e2 % 2 == 0) {
			return true;
		}
		else if (e1 % 2 == 0 && e2 % 2 != 0) {
			return false;
		}
		else {
			return e1 > e2;
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

	int max() {
		if (empty()) {
			return -1;;
		}

		compare C;
		int max = seq[0];
		for (int idx = 0; idx < seq.size(); idx++) {
			if (C(seq[idx], max)) {
				max = seq[idx];
			}
		}

		return max;
	}

	void removeMax() {
		if (empty()) {
			return;
		}

		compare C;
		int maxIdx = 0;
		for (int i = 0; i < seq.size(); i++) {
			if (C(seq[i], seq[maxIdx]))
				maxIdx = i;
		}
		seq.erase(seq.begin() + maxIdx);
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