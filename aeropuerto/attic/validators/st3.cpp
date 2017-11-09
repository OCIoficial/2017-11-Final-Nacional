/*
 * -----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <jperez@dcc.uchile.cl> wrote this file. As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you
 * think this stuff is worth it, you can buy me a beer in return Nicolás Lehmann
 * -----------------------------------------------------------------------------
 */

#include "testlib.h"
#include <utility>
#include <set>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> edge;

bool check_conn(vector<vector<int>> &A) 
{
  int N = A.size();

  vector<bool> V(N,false);
  V[1] = true;

  queue<int> Q;
  Q.push(1);

  while(!Q.empty())
  {
    int u = Q.front(); Q.pop();
    for(int v : A[u])
      if(!V[v])
      {
        V[v] = true;
        Q.push(v);
      }
  }

  for(int u = 1; u < N; ++u) if(!V[u]) return false;
  return true;
}

int main() {
  registerValidation();
  int N = inf.readInt(2, 3000, "N");
  inf.readSpace();
  int M = inf.readInt(1, 30000, "M");
  inf.readSpace();

  // check connectivity
  ensuref(M >= N-1, "El grafo debe ser conexo (no alcanzan las aristas)");

  int A = inf.readInt(1, N, "A");
  inf.readSpace();
  int B = inf.readInt(1, N, "B");
  inf.readEoln();

  set<edge> edges;
  vector<vector<int>> G(N + 1);

  for (int i = 0; i < M; ++i) {
    int u = inf.readInt(1, N, "u");
    inf.readSpace();
    int v = inf.readInt(1, N, "v");
    inf.readSpace();
    int c = inf.readInt(1, 1000, "c");
    inf.readEoln();

    ensuref(u != v, "No puede haber conexiones entre un terminal y si mismo");
    ensuref(edges.count({u, v}) == 0, "No puede haber aristas repetidas");
    ensuref(edges.count({v, u}) == 0, "No puede haber aristas repetidas");
    edges.emplace(u,v);
    G[u].push_back(v);
    G[v].push_back(u);
  }

  ensuref(check_conn(G), "El grafo debe ser conexo");

  int P = inf.readInt(0, 0, "P");
  inf.readEoln();
  inf.readEof();
  return 0;
}
