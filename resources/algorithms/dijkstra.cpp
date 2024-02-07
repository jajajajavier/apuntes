vvpii adj(n);
vi d(n, INF);
vi p(n, -1);
  
void dijkstra (int a, int b) {
  // priority_queue<pii, vpi, greater<pii>> pq;
  priority_queue<pii> pq;
  vb v(n, false);

  d[a] = 0;
  pq.push({0, a});

  while (!pq.empty()) {
    int s = pq.top().second;
    pq.pop();

    if (v[s]) continue;
    v[s] = true;

    for (auto u : adj[s])
      if (d[s] + u.ss < d[u.ff]) {
        d[u.ff] = d[s] + u.ss;
        p[u.ff] = v;
        // pq.push({d[u.ff], u.ff});
        pq.push({-d[u.ff], u.ff});
    }
  }
}

vi restore_path(int b, int a) {
  vi path;

  for (int v=b; v != a; v = p[v])
    path.pb(v);
  path.pb(a);

  reverse(all(path));
  return path;
}
