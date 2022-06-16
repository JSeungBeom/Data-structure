#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	vector<vector<int>> adj_matrix(2001, vector<int>(2001, 0));
	
	int t, n;
	cin >> t >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
	}

	while (t--) {
		string s;
		cin >> s;
		if (s == "insertEdge") {
			int s, d;
			cin >> s >> d;
			int check = 1;
			if (adj_matrix[s][d] != NULL || adj_matrix[d][s] != NULL) {
				check = 0;
				cout << "Exist" << endl;
			}

			if (check == 1) {
				adj_matrix[s][d] = 1;
				adj_matrix[d][s] = 1;
			}
		}
		if (s == "eraseEdge") {
			int s, d;
			cin >> s >> d;
			int check = 1;
			if (adj_matrix[s][d] == NULL || adj_matrix[d][s] == NULL) {
				check = 0;
				cout << "None" << endl;
			}

			if (check == 1) {
				adj_matrix[s][d] = 0;
				adj_matrix[d][s] = 0;
			}
		}
		if (s == "SumAdjacentNode") {
			int s;
			cin >> s;

			int sum = 0;

			for (int i = 0; i < 2001; i++) {
				if (adj_matrix[s][i] == 1) {
					sum += i;
				}
			}

			if (sum == 0) {
				cout << "None" << endl;
			}
			else {
				cout << sum << endl;
			}
		}
	}
}