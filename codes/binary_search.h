#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int binary_search(int i, int j) {
    while (i < j) {
        int m = (i+j) / 2;
        if (predicate(v[m]))
            j = m;
        else
            i = m + 1;
    }
    return i;
}

bool predicate(int x) {
    return x >= 0;
}

int main() {

    v = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << binary_search(0, v.size()) << endl;

    return 0;
}