#include <iostream>
#include <vector>

using namespace std;

// ������ �����ε�, e1�� e2���� �۴ٸ�(�켱������ ���ٸ�) true
struct compare {
	bool operator()(const int& e1, const int& e2)const {
		return e1 < e2;
	}
};

class sortedSeqPQ {
private:
	// ���ĵ��� ���� ������
	vector <int> seq;

public:
	// �������� ũ�� ����
	int size() {
		return seq.size();
	}

	// �������� ������� �Ǵ�
	bool empty() {
		return (seq.size() == 0);
	}

	// �������� ��� ����, ���ĵ� ���·� ���� �ȴ�
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