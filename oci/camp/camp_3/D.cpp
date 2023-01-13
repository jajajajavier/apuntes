#include <bits/stdc++.h>
using namespace std;

int dp[260][60];

int getWays(int x, int m, int i, vector<int> &c) {
  // cerr << x << " " << i << " " << c[i] << "\n";
  if (x == 0)
    return 1;
  if(x < 0)
    return 0;
  if (i == m)
    return 0;

  if(dp[x][i] != -1)
    return dp[x][i];

  int ans = 0;

  ans += getWays(x - c[i], m, i, c);
  ans += getWays(x, m, i+1, c);

  dp[x][i] = ans;

  return ans;
}

int main() {
  int n, m, x;
  vector<int> c;

  ios::sync_with_stdio(0); cin.tie(0);

  memset(dp, -1, sizeof(dp));

  cin >> n >> m;

  if (m == 0){
    cout << 0;
    return 0;
  }

  for(int i=0; i < m; i++) {
    cin >> x;
    c.push_back(x);
  }

  if(n == 0){
    cout << 0;
    return 0;
  }

  cout << getWays(n, m, 0, c);

  return 0;
}