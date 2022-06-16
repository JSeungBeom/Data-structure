#include <iostream>
#include <vector>
#include <algorithm>	
using namespace std;

int main(void) {
	vector<int> adj_list[2001];
	int t, n;

	cin >> t >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
	}

	while (t--) {
		string s;
		cin >> s;
		if (s == "insertEdge") {
			int u, v;
			int check = 0;
			cin >> u >> v;

			for (int i = 0; i < adj_list[u].size(); i++) {
				if (adj_list[u][i] == v) {
					cout << "Exist" << endl;
					check = 1;
				}
			}

			if (check == 0) {
				adj_list[u].push_back(v);
				adj_list[v].push_back(u);
			}
		}
		else if (s == "eraseEdge") {
			int u, v;
			int check = 0;
			cin >> u >> v;

			for (int i = 0; i < adj_list[u].size(); i++) {
				if (adj_list[u][i] == v) {
					check = 1;
				}
			}


			if (check == 1) {
				int idx1;
				int idx2;
				for (int i = 0; i < adj_list[u].size(); i++) {
					if (adj_list[u][i] == v) {
						idx1 = i;
					}
				}

				for (int i = 0; i < adj_list[v].size(); i++) {
					if (adj_list[v][i] == u) {
						idx2 = i;
					}
				}
				adj_list[u].erase(adj_list[u].begin() + idx1);
				adj_list[v].erase(adj_list[v].begin() + idx2);
			}
			else {
				cout << "None" << endl;
			}
		}
		else if (s == "MaxAdjacentNode") {
			int a;
			cin >> a;
			int check = 0;
			int max = 0;

			if (adj_list[a].size() == 0) {
				cout << "None" << endl;
				check = 1;
			}

			if (check == 0) {
				for (int i = 0; i < adj_list[a].size(); i++) {
					if (adj_list[a][i] > max) {
						max = adj_list[a][i];
					}
				}

				cout << max << endl;
			}
			
		}
	}
}