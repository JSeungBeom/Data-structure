#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<vector<int>> adj_list(501, vector<int>(501, 0));
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			adj_list[i].push_back(x);
		}
	}

	for (int i = 0; i < m; i++) {
		int k, f;
		cin >> k >> f;
		int a = k - 1;
		if (f == 0) {
			int check[501] = { 0, };
			for (int i = 0; i < adj_list[a].size(); i++) {
				if (adj_list[a][i] != 0) {
					check[i] = 1;
				}
				if (adj_list[a][i] == 2) {
					for (int j = 0; j < adj_list[j].size(); j++) {
						if (check[j] != 1 && i != j) {
							check[j] = 2;
						}
					}
				}
			}

			for (int i = 0; i < 501; i++) {
				if (check[i] == 2) {
					cout << i << " ";
				}
			}
			cout << endl;
		}
		if (f == 1) {
			int check[501] = { 0, };
			for (int i = 0; i < adj_list[a].size(); i++) {
				if (adj_list[a][i] != 0) {
					check[i] = 1;
				}
				if (adj_list[a][i] == 1) {
					for (int j = 0; j < adj_list[j].size(); j++) {
						if (check[j] != 1 && i != j) {
							check[j] = 2;
						}
					}
				}
			}

			for (int i = 0; i < 501; i++) {
				if (check[i] == 2) {
					cout << i << " ";
				}
			}
			cout << endl;
		}
	}
}