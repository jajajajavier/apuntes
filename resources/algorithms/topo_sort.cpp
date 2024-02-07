int n;
vvi adj(n);
vb v(n, false);

void dfs (int s, vi & ans) {
  v[s] = true;
  for (int u : adj[s])
    if (!v[u])
      dfs(u);
  ans.pb(s);
}

vi topo_sort() {
  vi ans;
  for (int i=0; i < n; i++)
    if (!v[i])
       dfs(i, ans);
  reverse(all(ans));
  return ans;
}
