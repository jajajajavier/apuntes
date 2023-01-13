#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string padre, hijo;
  map<string, vector<string>> dependencias;

  cin >> n;

  while(n--) {
    cin >> hijo;
    hijo.pop_back();
    while(getchar() != '\n') {
      cin >> padre;
      if(!dependencias.count(padre))
        dependencias.insert({padre, {}});
      dependencias[padre].push_back(hijo);
    }
  }

    



    // for (auto i: dependencias) {
    //   cout << i.first << " ---> ";
    //   for(auto j: i.second) cout << j << " ";
    //   cout <<endl;
    // }

  return 0;
}