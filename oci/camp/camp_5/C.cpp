#include <bits/stdc++.h>
using namespace std;

vector<int> distances (int s, int n ,vector<vector<int>> & adj) {
    vector<bool> visited(n, false); 
    vector<int> dist(n, -1);
    queue<int> Q;

    dist[s] = 0;
    visited[s] = true;
    Q.push(s);
 
    while(!Q.empty()) {
        int v = Q.front();
        Q.pop();

        for (auto i: adj[v]) 
            if (!visited[i]) {
                visited[i] = true;
                dist[i] = dist[v] + 1;
                Q.push(i);
            }
    }

    return dist;
}

pair<int, int> route_rebuild(int v, vector<vector<int>> &adj, vector<int> & dist, int next) {
    int rebuilds_min = 0;
    int rebuilds_max = 0;
    
    if (dist[v] <= dist[next]) {
        rebuilds_min++;
        rebuilds_max++;
        return {rebuilds_min, rebuilds_max};
    }
    
    int cont = 0; 
    for(int i: adj[v]) {
        if (dist[i] == dist[next])
            cont++;
        if(cont == 2) {
            rebuilds_max++;
            break;
        }
    }

    return {rebuilds_min, rebuilds_max};
}

int main() {
    int n, m, a, b, k, x;

    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<vector<int>> adj_reverse(n);

    for(int i=0; i < m; i++) {
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj_reverse[b].push_back(a);
    }

    cin >> k;
    vector<int> route(k);
    for(int i=0; i < k; i++) {
        cin >> x;
        route[i] = x - 1; 
    }

    int s = route.front(); int f = route.back();
    vector<int> dist = distances(f, n, adj_reverse);

    pair<int, int> rebuild = {0, 0};
    pair<int, int> aux;
    for (int i=0; i < k-1; i++) {
            aux = route_rebuild(route[i], adj, dist, route[i+1]);
            rebuild.first += aux.first;
            rebuild.second += aux.second;
    }

    cout << rebuild.first << " " << rebuild.second;

    return 0;
}