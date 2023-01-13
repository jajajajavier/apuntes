#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
const int INF = 1e9;

int n, m;
vector<vector<ii>> g;
vector<int> distance;

void dijkstra(int nodo_inicio) {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, nodo_inicio});
    distance[nodo_inicio] = 0;

    while (!pq.empty()) {
        int nodo = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > distance[nodo])
            continue;

        for (int i = 0; i < g[nodo].size(); ++i) {
            int next = g[nodo][i].first;
            int w_extra = g[nodo][i].second;
            if (distance[nodo] + w_extra < distance[next]) {
                distance[next] = distance[nodo] + w_extra;
                pq.push({distance[next], next});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    distance.resize(n, INF);

    rep(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        u, v, w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});  // no dirigido
    }

    int nodo_inicio = 0;

    dijkstra(nodo_inicio);

    return 0;
}