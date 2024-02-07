struct Centroid {
  vi subTree, P, L, A;
  vvi graph, C, D;
  
  Centroid(vvi & adj) {
    graph = adj;
    N = graph.size();

    subTree.resize(N, 0);
    P.resize(N); L.resize(N);
    dfs();

    findCentroid(0, N, 0, -1);
    findDistances();
    A.resize(N, INF);
  }

  void dfs() {
    stack<int> S; S.push(0);
    queue<int> Q; Q.push(0);
    vi Parent(N, -1);
    subTree[0] = 1;
    while (!Q.empty()) {
      int u = Q.front(); Q.pop();
      for (int v : graph[u]) 
        if (subTree[v] == 0) {
          subTree[v] = 1; Parent[v] = u;
          S.push(v); Q.push(v);
        }
    }
    while(!S.empty()) {
      int u= S.top(); S.pop();
      for (int v : graph[u])
        if (v != Parent[u])
          subTree[u] += subTree[v];
    }
  }

  void findCentroid(int u, int n, int l, int p) {
    int heavy = -1;
    for (int v : graph[u])
      if (subTree[v] > n/2) {
      heavy = v;
      break;
    }
    if (heavy == -1) {
      if (C.size()  <= 1) C.pb(vi());
      C[l].pb(u); P[u] = p; L[u] = l;
      subTree[u] = 0;
      for (int v: graph[u])
        if (subTree[v]) findCentroid(v, subTree[v], l+1, u);
    }
    else {
      subTree[u] = n-subTree[heavy];
      findCentroid(heavy, n, l, p);
    }
  }

