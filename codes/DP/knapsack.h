#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, W;
    cin >> N >> W;
    vector<int> v(N), w(N);
    for (int i = 0; i < N; i++)
        cin >> w[i];
    for (int i = 0; i < N; i++)
        cin >> v[i];

    vector<vector<int>> dp(N, vector<int>(W + 1, 0));
    // ll dp[N][W];
    // Caso base
    for (int j = 0; j <= W; j++) {
        if (w[0] <= j)
            dp[0][j] = v[0];
        else
            dp[0][j] = 0;
    }
    // Bottom-up
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = dp[i - 1][j];  // no incluimos el i
            if (w[i] <= j) {          // si el objeto i es incluible
                dp[i][j] = max(dp[i - 1][j], v[i] + dp[i - 1][j - w[i]]);
            }
        }
    }
    cout << dp[N - 1][W] << '\n';
    return 0;
}