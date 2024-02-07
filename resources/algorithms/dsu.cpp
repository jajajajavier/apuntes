template <class T>
struct DSU {
  vector<T> parent, rank;

  DSU() {}

  DSU(int N) {
    for (int i=0; i < N; i++) {
      parent.pb(i);
      rank.pb(0);
    }
  }
  
  void extend (int N) {
    int sz = parent.size();
    for (int i=0; i < N; i++) {
      parent.pb(sz + i);
      rank.pb(0);
    }
  }

  T find (T x) {
    if (parent[x] != x) 
      return parent[x] = find(parent[x]);
    else return x;
  }

  void unite(T x, T y) {
    x = find(x); y = find(y);
    if (x == y) return;
    if (rank[x] < rank[y]) swap(x, y);
    parent[y] = x;
    if (rank[x] == rank[y]) rank[x]++;
  }
};
