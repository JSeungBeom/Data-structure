#include <iostream>
#include <vector>

using namespace std;

// ����
struct compare {
	bool operator()(const int e1, const int e2) {
		return e1 > e2;
	}
};

// ���ĵ��� ���� �������� �켱���� ť ����, �������� ���
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

	// ť�� ���� ����, O(1) time
	void insert(int e) {
		seq.push_back(e); // �׳� �ڿ� ����
	}

	// ť�� �켱 ������ ���� ���� ���� ����, O(n) time
	int max() {
		if (empty()) {
			return -1;
		}

		compare C;
		int maxVal = seq[0];

		for (int i = 0; i < seq.size(); i++) {
			if (C(seq[i], maxVal)) { // ť�� ��Ұ� maxVal���� �켱������ ���ٸ�
				maxVal = seq[i]; // maxVal�� �ش� ���
			}
		}
		return maxVal;
	}

	// ť�� �켱 ������ ���� ���� ���� ����, O(n) time
	void removeMax() {
		if (empty()) {
			return;
		}

		compare C;
		int maxIdx = 0;

		for (int i = 0; i < seq.size(); i++) {
			if (C(seq[i], seq[maxIdx])) { // �ش� �ε������� maxIdx������ ��Һ��� �켱������ ���ٸ�
				maxIdx = i; // maxIdx�� �ش� �ε���
			}
		}

		seq.erase(seq.begin() + maxIdx); // maxIdx�� ��� ����
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