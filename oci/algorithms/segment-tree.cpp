#include<bits/stdc++.h>

using namespace std;


template<class T>
struct SegmentTree{
	T (*merge)(T, T);
	int n;
	vector<T>ST;
	void build(int i, int l, int r, vector<T> &values){
		if (l == r){
			ST[i] = values[l];
			return;
		}
		build(i * 2, l, (l + r) / 2, values);
		build(i * 2 + 1, (l + r) / 2 + 1, r, values);
		ST[i] = merge(ST[i * 2], ST[i * 2 + 1]);
	}

	SegmentTree(vector<T> &values, T (*merge)(T a, T b)) : merge(merge){
		n = values.size();
		ST.resize(n << 2 | 3);
		build(1, 0, n - 1, values);
	}

	void update(int i, int l, int r, int pos, T val){
		if (r < pos or l > pos) return;
		if (l == r){
			ST[i] = val;
			return;
		}
		update(i << 1, l, (l + r) >> 1, pos, val);
		update(i << 1 | 1, (l + r) / 2 + 1, r, pos, val);
		ST[i] = merge(ST[i << 1], ST[i << 1 | 1]);
	}

	void update(int pos, T val){
		update(1, 0, n - 1, pos, val);
	}

	T query(int i, int l, int r, int a, int b){
		if (l >= a and r <= b) return ST[i];
		int mid = (l + r) >> 1;
		if (mid < a)
			return query(i << 1 | 1, mid + 1, r, a, b);
		if (mid >= b) 
			return query(i << 1, l, mid, a, b);
		return merge(query(i << 1, l, mid, a, b), query(i << 1 | 1, mid + 1, r, a, b));
	}

	T query(int a, int b){
		if (a > b) return merge(query(1, 0, n - 1, 0, b), query(1, 0, n - 1, a, n - 1));
		return query(1, 0, n - 1, a, b);
	}
};

pair<int, int> merge(pair<int, int> a, pair<int, int> b){
	if (a.first <= b.first)
		return a;
	return b;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i ++)
		cin >> a[i];

	vector<pair<int, int> > auxiliar(n);
	for (int i = 0; i < n; i ++){
		auxiliar[i] = pair<int, int>(a[i], i);
	}

	SegmentTree<pair<int, int> > ST(auxiliar, merge);

	int q;
	cin >> q;
	for (int i = 0; i < q; i ++){
		int a, b;
		cin >> a >> b;
		cout << ST.query(a, b).second << endl;
	}


	return 0;
}
