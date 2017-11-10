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

int norm2(pair<int, int> p) {
  return p.first*p.first + p.second*p.second;
}

int pointsInCircle(int R) {
  int points = 0;
  for (int i = -R; i <= R; ++i)
    for (int j = -R; j <= R; ++j)
      if (norm2({i, j}) <= R*R)
        points += 1;
  return points - 1;
}

int emptyPoints(int R) {
  int sum = 0;
  for (auto p : not_meblins)
    if (norm2(p) <= R*R)
      sum += 1;
  return sum;
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

  int r = 1;
  while(pointsInCircle(r) - emptyPoints(r) < K)
    r++;
  cout << r << "\n";

  return 0;
}
