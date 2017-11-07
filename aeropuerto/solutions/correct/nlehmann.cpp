/*
 * -----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nlehmann@dcc.uchile.cl> wrote this file. As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you
 * think this stuff is worth it, you can buy me a beer in return Nicolás Lehmann
 * -----------------------------------------------------------------------------
 */

#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
#include <tuple>

using namespace std;

int N;
vector<vector<pair<int, int>>> paths;
vector<vector<tuple<int, int, int>>> trains;

template<class Fun>
void neighbors(int n, int t, Fun f) {
  for (auto path : paths[n])
    f(path.first, path.second);
  for (auto train : trains[n])
    if (get<1>(train) >= t)
      f(get<0>(train), get<1>(train) - t + get<2>(train));
}

int dijkstra(int S, int T) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> dist(N, INT_MAX);
  dist[S] = 0;
  pq.emplace(0, S);
  while (not pq.empty()) {
    int n, d;
    tie(d, n) = pq.top(); pq.pop();

    if (d > dist[n])
      continue;

    if (n == T)
      return d;

    neighbors(n, d, [&](int v, int w) {
        if (w + d < dist[v]) {
          dist[v] = w + d;
          pq.emplace(w + d, v);
        }
      });
  }
  return INT_MAX;
}

int main() {
  int M, S, T;
  scanf("%d%d%d%d", &N, &M, &S, &T);
  S--; T--;

  paths.resize(N);
  for (int i = 0; i < M; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    a--; b--;
    paths[a].emplace_back(b, c);
    paths[b].emplace_back(a, c);
  }

  int P;
  scanf("%d", &P);
  trains.resize(N);
  for (int i = 0; i < P; ++i) {
    int u, v, t, w;
    scanf("%d%d%d%d", &u, &v, &t, &w);
    u--; v--;
    trains[u].emplace_back(v, t, w);
  }

  printf("%d\n", dijkstra(S, T));
}
