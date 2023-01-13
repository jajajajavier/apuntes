#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct DSU {
    vector<int> p, rank;
    DSU(int N) {
        for (int i = 0; i < N; i++) {
            p.push_back(i);
            rank.push_back(0);
        }
    }
    int find(int x) {
        if (p[x] != x) {
            return p[x] = find(p[x]);
        } else
            return x;
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (rank[x] < rank[y])
            swap(x, y);
        p[y] = x;
        if (rank[x] == rank[y])
            rank[x]++;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    // crear grafo
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--;
        v--;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    // kruskal
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;
    for (int i = 0; i < n; i++) {
        for (pair<int, int> p : graph[i]) {
            pq.push({p.second, {i, p.first}});  //(peso, (u, v))
        }
    }
    DSU dsu(n);
    vector<pair<int, int>> tree;  // las aristas del arbol
    while (!pq.empty()) {
        pair<int, pair<int, int>> p = pq.top();
        pq.pop();
        int u = p.second.first;
        int v = p.second.second;
        if (dsu.find(u) != dsu.find(v)) {
            dsu.unite(u, v);
            tree.push_back({u, v});
        }
    }

    return 0;
}