  void findDistances() {
    D.resize(C.size(), vi(N, -1));
    for (int l=0; l < C.size(); l++) {
      queue<int> Q;
      for (int u : C[l]) {
        Q.push(u);
        D[l][u] = 0;
      }
      while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int v : graph[u])
          if (L[v] >= l && D[l][v] == -1){
          D[l][v] = D[l][u]+1;
          Q.push(v);
        }
      }
    }
  }

  void update(int v) {
    int u = v;
    while (u != -1) {
      A[u] = min(D[L[u]][v], A[u]);
      u = P[u];
    }
  }
  
  int query(int v) {
    int u = v, ans = INF;
    while (u != -1) {
      ans = min(ans, D[L[u]][v] + A[u]);
      u = P[u];
    }
    return ans;
  }
};
