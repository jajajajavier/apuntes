#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> visited;

void dfs(int nodo) {
    visited[nodo] = 1;
    for (int i = 0; i < g[nodo].size(); ++i) {
        int next = g[nodo][i];
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    visited.resize(n, 0);

    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u, v;
        g[u].push_back(v);
        g[v].push_back(u);  // no dirigido
    }

    int nodo_inicio = 0;

    dfs(nodo_inicio);

    return 0;
}