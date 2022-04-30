#include <iostream>
#include <vector>

using namespace std;

struct compare {
	bool operator()(const int& e1, const int& e2) const {
		return e1 > e2;
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
			return -1;
		}

		compare C;
		int maxVal = seq[0];

		for (int i = 0; i < seq.size(); i++) {
			if (C(seq[i], maxVal)) {
				maxVal = seq[i];
			}
		}
		return maxVal;
	}

	void removeMax() {
		if (empty()) {
			return;
		}

		compare C;
		int maxIdx = 0;

		for (int i = 0; i < seq.size(); i++) {
			if (C(seq[i], seq[maxIdx])) {
				maxIdx = i;
			}
		}
		seq.erase(seq.begin() + maxIdx);
	}
};

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int N;
		cin >> N;
		vector <int> seq;
		unsortedSeqPQ pq;
		for (int i = 0; i < N; i++) {
			int n;
			cin >> n;
			seq.push_back(n);
		}
		for (int i = 0; i < N; i++) {
			pq.insert(seq.front());
			seq.erase(seq.begin());
		}
		for (int i = 0; i < N; i++) {
			seq.push_back(pq.max());
			pq.removeMax();
		}
		for (int i = 0; i < N; i++) {
			cout << seq[i] << " ";
		}
		cout << endl;
	}
}