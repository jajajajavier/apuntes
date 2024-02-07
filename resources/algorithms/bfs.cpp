// n = numero de nodos
// s = origen
vvi adj;  // lista de adyacencia

queue<int> q;
vb v(n, false); // visitados
vi d(n, -1); // distancias
vi p(n, -1); // path

q.push(s);
v[s] = true;
p[s] = -1;
while (!q.empty()) {
    int a = q.front();
    q.pop();
    for (int b : adj[a]) {
        if (!used[b]) {
            used[b] = true;
            q.push(b);
            d[b] = d[a] + 1;
            p[b] = a;
        }
    }
}
