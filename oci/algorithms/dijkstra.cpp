#include <bits/stdc++.h>
using namespace std;

int n, v;
vector< vector< pair< int, int > > > matriz;
vector< int > distances; // vector que almacena las distancias desde el nodo inicial hasta cualquier otro nodo

int dijkstra(int nodo_s, int nodo_f){
	distances[nodo_s] = 0;
	priority_queue<pair< int, int >, vector<pair< int, int >>, greater<pair< int, int >>> next;
	next.push(pair< int, int >(0, nodo_s));
	
	while(!next.empty()){
		int u = next.top().second; int d = next.top().first;
		next.pop();
		if(u != nodo_f && d <= distances[u]){
			for(int i = 0; i < matriz[u].size(); i++){
				int v = matriz[u][i].first;
				int w = matriz[u][i].second;
				if(distances[v] > distances[u] + w){
					distances[v] = distances[u] + w;
					next.push(pair< int, int >(distances[v], v));
				}
			}
		}
	}
  return distances[nodo_f];
}

int main(){
  cin >> n >> v;
  matriz.resize(n, vector< pair< int, int > >());
  distances.resize(n, 1000000000);  

  for(int i = 0; i < v; i++){
    int a, b, w; // w representa el peso
    cin >> a >> b >> w;
    // se anade una arista
    matriz[a].push_back(pair<int, int>(b, w));
    matriz[b].push_back(pair<int, int>(a, w));
  }
  
  int nodo_s, nodo_f;
  cin >> nodo_s >> nodo_f;
  cout << dijkstra(nodo_s, nodo_f) << "\n";
  return 0;
}
