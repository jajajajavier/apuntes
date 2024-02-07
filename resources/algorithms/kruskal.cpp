// la priority queue es la lista de adyacencia
// (peso, (a, b))
int kruskal(int n, priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>>> &pq){
  DSU dsu(n);
  // vpi tree; // aristas del arbol
  int total_w = 0;
  
  while (!pq.empty()) {
    pair<int, pii> p = pq.top();
    pq.pop();
    int a = p.ss.ff;
    int b = p.ss.ss;
    int w = p.ff
    if (dsu.find(a) != dsu.find(b)) {
      dsu.unite(a, b);
      // tree.pb({a, b});
      total_w += w;
    }
  }

  return tree;
  // return total_w;
}
