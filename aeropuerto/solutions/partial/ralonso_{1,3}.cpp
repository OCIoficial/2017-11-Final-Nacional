#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <queue>

using namespace std;

const int INF = 1000000000;

int main() {
  int n, m, s, t, p;
  int a, b, c;
  int u, v, tt, w;
  int i;
  int tu, te;

  cin >> n >> m >> s >> t;

  vector< vector< pair< int, int > > > edges(n + 1);
  vector< int > time(n + 1, INF);

  for (i = 0; i < m; i++) {
    cin >> a >> b >> c;
    edges[a].push_back(make_pair(c, b));
    edges[b].push_back(make_pair(c, a));
  }

  cin >> p;

  for (i = 0; i < p; i++) {
    cin >> u >> v >> tt >> w;
  }

  priority_queue< pair< int, int >, vector< pair< int, int > >, greater< pair< int, int > > > pq;
  pq.push(make_pair(0, s));
  while (true) {
    auto pr = pq.top(); pq.pop();
    tu = get<0>(pr);
    u = get<1>(pr);
    if (time[u] != INF) continue;
    time[u] = tu;
    if (u == t) break;
    for(auto edge: edges[u]) {
      te = get<0>(edge);
      v = get<1>(edge);
      pq.push(make_pair(tu + te, v));
    }
  }

  cout << time[t] << endl;

  return 0;
}
