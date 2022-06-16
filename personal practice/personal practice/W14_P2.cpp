#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[201];
bool visit[201];
int minVal = 1000;

void DFS(int cur) {
	visit[cur] = true;
	if (cur < minVal) {
		minVal = cur;
	}
	for (int i = 0; i < adj[cur].size(); i++) {
		int next = adj[cur][i];
		if (visit[next])
			continue;
		DFS(next);
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		while (m--) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		while (k--) {
			int c;
			cin >> c;
			DFS(c);

			cout << minVal << endl;
			minVal = 10000;
		}

		for (int i = 0; i < 201; i++) {
			visit[i] = false;
		}

		for (int i = 0; i < 201; i++) {
			while (!adj[i].empty()) {
				adj[i].pop_back();
			}
		}

	}
}