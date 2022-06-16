#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visit[501] = {false, };
vector<int> adj[501];
queue<int> q;
int cnt = 0;

void BFS(int start) {
	visit[start] = true;
	q.push(start);

	while (!q.empty()) {
		int x = q.front();
		cnt++;
		if (cnt % 2 == 1) {
			cout << x << " ";
		}
		q.pop();
		for (int i = 0; i < adj[x].size(); i++) {
			int next = adj[x][i];
			if (!visit[next]) {
				visit[next] = true;
				q.push(next);

			}
		}
	}

	while (!q.empty()) {
		q.pop();
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;
		while (m--) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		BFS(1);
		for (int i = 0; i < 501; i++) {
			visit[i] = false;
		}

		for (int i = 0; i < 501; i++) {
			while (!adj[i].empty()) {
				adj[i].pop_back();
			}
		}

		cnt = 0;
		cout << endl;
	}
}