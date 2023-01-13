#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, W;
	cin >> N >> W;
	vector <int> v(N), w(N);
	for(int i=0; i<N; i++) cin >> w[i];
	for(int i=0; i<N; i++) cin >> v[i];
	vector <int> dp(W+1,0);
	// Caso base
	for(int j=0; j<=W; j++){
		if(w[0] <= j) dp[j] = v[0];
		else dp[j] = 0;
	}
	// Bottom-up
	for(int i=1; i<N; i++){
		for(int j=W; j-w[i]>=0; j--){
			// Solo guardamos la fila actual. Para calcular la siguiente fila, la sobreescribimos sobre la actual.
			// Importante que se haga de derecha a izquierda, asÃ­ los valores nuevos no son usados para calcular otros nuevos.
			dp[j] = max(dp[j], v[i]+dp[j-w[i]]);
		}
	}
	cout << dp[W] << '\n';
	return 0;
}
