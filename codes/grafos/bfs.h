#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> visited;

void bfs(int nodo) {
    queue<int> q;
    q.push(nodo);
    visited[nodo] = 1;
    while (!q.empty()) {
        int nodo = q.front();
        q.pop();
        for (int i = 0; i < g[nodo].size(); ++i) {
            int next = g[nodo][i];
            if (!visited[next]) {
                q.push(next);
                visited[next] = 1;
            }
        }
    }
}

vector<int> dist;

void bfs_dist(int nodo) {
    queue<int> q;
    q.push(nodo);
    visited[nodo] = 1;
    while (!q.empty()) {
        int nodo = q.front();
        q.pop();
        for (int i = 0; i < g[nodo].size(); ++i) {
            int next = g[nodo][i];
            if (!visited[next]) {
                q.push(next);
                visited[next] = 1;
                dist[next] = dist[nodo] + 1;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    visited.resize(n, 0);
    dist.resize(n, 0);

    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u, v;
        g[u].push_back(v);
        g[v].push_back(u);  // no dirigido
    }

    int nodo_inicio = 0;

    bfs(nodo_inicio);

    // version con distancias
    // bfs_dist(nodo_inicio);

    return 0;
}