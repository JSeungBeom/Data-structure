#include <iostream>
#include <vector>	

using namespace std;

// ����
struct compare {
	// e1 < e2 -> true, e1 >= e2 -> false
	bool operator()(const int e1, const int e2) {
		return e1 < e2;
	}
};

//���ĵ� �������� �̿��� �켱���� ť ����, ���� ���� ��� ����
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

	// ť�� ���� ����, O(n) time
	void insert(int e) {
		compare C; // ���� ����
		int idx = 0;
		for (idx = 0; idx < seq.size(); idx++) {
			if (C(seq[idx], e)) // ������ ���Һ��� �켱 ������ ���� ���� Ž��
				break;
		}
		seq.insert(seq.begin() + idx, e); // �ش� ��ġ�� ���� ����
	}

	// �켱������ ���� ���� ���� ��ȯ, O(1) time
	int min() {
		if (empty()) {
			return -1;
		}
		// ť�� ���� ������ ���� -> �켱������ ���� ���� ����
		return seq.back();
	}

	// �켱������ ���� ���� ���� ����, O(1) time
	void removeMin() {
		if (empty()) {
			return;
		}

		// ť�� ���� ������ ���� ����
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