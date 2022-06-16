#include <iostream>
#include <vector>  

using namespace std;

int cnt = 0;
int n, m;
vector<int> adj[501];
bool visit[501];

void DFS(int cur) {
    cnt++;
    if (cnt % 2 != 0)
        cout << cur << " ";
    visit[cur] = true;
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
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        DFS(1);
        cnt = 0;
        for (int i = 0; i < 501; i++) {
            visit[i] = false;
        }
        
        for (int i = 0; i < 501; i++) {
            while(!adj[i].empty())
            adj[i].pop_back();
        }
        cout << endl;
    }
}