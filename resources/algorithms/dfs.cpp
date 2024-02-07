vvi adj(n);
vb v(n, false);

// recursivo
void dfs(int s) {
  v[s] = true;
  for (int u : adj[s])
    if (!v[u])
      dfs(u);
}

// para el dfs iterativo solo remplazar
// la queue del bfs por un stack
