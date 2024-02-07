int n;
vvi adj(n);
vb v;
int timer;
vi tin, low;

void dfs(int s, int p = -1) {
  v[s] = true;
  tin[s] = low[s] = timer++;
  int children = 0;
  for (int to : adj[s]) {
    if (to == p) continue;
    if (v[to]) 
      low[s] = min(low[s], tin[to]); 
    else {
      dfs(to, s);
      low[s] = min(low[s], low[to]);
      if (low[to] >= tin[s] && p != -1) {
        // is a cutpoint
      }
      children++;
    }
  }
  if (p == -1 && children > 1) {
    // is a cutpoint
  }
}

void find_cutpoints() {
  timer = 0;
  v.resize(n, false);
  tin.resize(n, -1); low.resize(n, -1);
  for (int i=0; i < n; i++)
    if (!v[i])
      dfs(i);
}
