/*
 * -----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nlehmann@dcc.uchile.cl> wrote this file. As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you
 * think this stuff is worth it, you can buy me a beer in return Nicolás Lehmann
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<pair<int,int>> not_meblins;

long long norm2(pair<int, int> p) {
  return ((long long) p.first)*p.first + ((long long) p.second)*p.second;
}

long pointsInCircle(long long R) {
  long long points = 0;
  for (long long r = -R; r <= R; ++r)
    points += floor(sqrt(R*R - r*r));
  return 2*(points + R);
}

int emptyPoints(long long R) {
  int l = 0, r = not_meblins.size();
  while(l < r) {
    int m = (l + r)/2;
    if (norm2(not_meblins[m]) <= R * R)
      l = m + 1;
    else
      r = m;
  }
  return l;
}

int main() {
  int N;
  long long K;
  cin >> N >> K;

  not_meblins.resize(N);
  for (int i = 0; i < N; ++i) {
    int X, Y;
    cin >> X >> Y;
    not_meblins[i] = {X, Y};
  }
  sort(not_meblins.begin(), not_meblins.end(), [](pair<int, int> a, pair<int, int> b) {
      return norm2(a) < norm2(b);
    });

  int l = 0, r = 200000;
  while (l < r) {
    int m = (l + r)/2;
    if (pointsInCircle(m) - emptyPoints(m) < K)
      l = m + 1;
    else
      r = m;
  }

  cout << l << "\n";

  return 0;
}
