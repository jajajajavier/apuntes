struct EDGE{ int a, b, w; };

int n, m;
vector<EDGE> edges;
vi p(n);

void bellmanFord(int s) {
  vi d(n, INF);
  d[s] = 0;
  int x;

  for (int i=0; i < n; i++) {
    x = -1;
    for (EDGE & e: edges)
      if (d[e.a] < INF) 
        if (d[e.b] > d[e.a] + e.w) {
          d[e.b] = max(d[e.a] + e.w, -INF);
          p[e.b] = e.a;
          x = e.b;
        }
  }

  if (x == -1)
    // Negative cycle
  else {
    int y = x;
    for (int i = 0; i < n; ++i)
      y = p[y];

    vi path; // cycle
    for (int cur = y;; cur = p[cur]) {
      path.pb(cur);
      if (cur == y && path.size() > 1)
        break;
    }
    reverse(all(path));
  }
}
