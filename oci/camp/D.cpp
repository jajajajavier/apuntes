#include <bits/stdc++.h>
using namespace std;
#include "hielo.h"
const int INF = 1e9;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int next_x = 0;
int next_y = 0;

bool posible(int N, bool rocas[100][100], int xi, int yi, int xf, int yf) {
  bool visited[105][105];
  memset(visited, 0, sizeof(visited));

  queue<pair<int, int>> Q;

  visited[xi][yi] = true;
  Q.push({xi, yi});
  pair<int, int> v;

  while (!Q.empty()) {

    if (visited[xf][yf])
      return true;

    v = Q.front();
    Q.pop();

    for (int i=0; i < 4; i++) {
      next_x = v.first + dx[i];
      next_y = v.second + dy[i];

      if( next_x >= 0 && next_y >= 0  && next_x < N && next_y < N)
        while (next_x < N && next_y < N && next_x >= 0 && next_y >= 0) {
          if (rocas[next_x][next_y])
            break;
          next_x += dx[i];
          next_y += dy[i];
        }

        next_x -= dx[i];
        next_y -= dy[i];

        if (!visited[next_x][next_y]) {
          visited[next_x][next_y] = true;
          Q.push({next_x, next_y});
        }
    }

  }
  
  return false;
}

int minimo(int N, bool rocas[100][100], int xi, int yi, int xf, int yf) {
  bool visited[105][105];
  long int dist[105][105];
  memset(visited, 0, sizeof(visited));
  for(int i=0; i < 105; i++)
    for(int j=0; j < 105; j++)
      dist[i][j] = 1e10;

  queue<pair<int, int>> Q;
  // priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> Q;

  visited[xi][yi] = true;
  dist[xi][yi] = 0;
  Q.push({xi, yi});
  pair<int, int> v;
  int cont = 0;

  while (!Q.empty()) {

    v = Q.front();
    Q.pop();

    for (int i=0; i < 4; i++) {
      next_x = v.first + dx[i];
      next_y = v.second + dy[i];

      if( next_x >= 0 && next_y >= 0  && next_x < N && next_y < N) {
        cont = 0;
        while (next_x < N && next_y < N && next_x >= 0 && next_y >= 0) {
          if (rocas[next_x][next_y])
            break;
          next_x += dx[i];
          next_y += dy[i];
          cont++;
        }
      }

        next_x -= dx[i];
        next_y -= dy[i];

        if(dist[next_x][next_y] > cont + dist[v.first][v.second]) {
          dist[next_x][next_y] = cont + dist[v.first][v.second];
        }

        if (!visited[next_x][next_y]) {
          visited[next_x][next_y] = true;
          Q.push({next_x, next_y});
        }
    }

  }

  if (dist[xf][yf] == 1e10)
    return -1;

  return dist[xf][yf];
}
