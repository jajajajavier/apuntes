#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, w, h;
  long long int area;
  vector<long long int> envelop(3);

  cin >> n >> w >> h;
  envelop[0] = w * h;
  envelop[1] = w;
  envelop[2] = h;

  vector<vector<long long int>> chain(n); 
  for(int i=0; i < n; i++) {
    cin >> w >> h;
    chain[i].push_back(w * h);
    chain[i].push_back(w);
    chain[i].push_back(h);
    chain[i].push_back(i+1);
  }

  // [0] area
  // [1] width
  // [2] height
  // [3] envelop id

  sort(chain.begin(), chain.end());

  vector<int> id_list;

  for(int i=0; i < n; i++) {
    if (chain[i][0] > envelop[0] && chain[i][1] > envelop[1] && chain[i][2] > envelop[2]) {
      id_list.push_back(chain[i][3]);
      envelop[0] = chain[i][0];
      envelop[1] = chain[i][1];
      envelop[2] = chain[i][2];
    }
  }

  if(!id_list.empty()) {
    cout << 0;
    return 0;
  }

  for (int i: id_list)
    cout << i << " ";


  return 0;
}