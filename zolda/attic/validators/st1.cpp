/*
 * -----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nlehmann@dcc.uchile.cl> wrote this file. As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you
 * think this stuff is worth it, you can buy me a beer in return Nicolás Lehmann
 * -----------------------------------------------------------------------------
 */
#include "testlib.h"
#include <unordered_set>
using namespace std;

int main() {
  registerValidation();
  int N = inf.readInt(0, 0, "N");
  inf.readSpace();
  inf.readInt(1, 10, "K");
  inf.readEoln();

  set<pair<int,int>> points;
  for (int i = 0; i < N; ++i) {
    int X = inf.readInt(-1000000000, 1000000000, "Xi");
    inf.readSpace();
    int Y = inf.readInt(-1000000000, 1000000000, "Yi");
    inf.readEoln();

    ensuref(points.count({X, Y}) == 0, "No puede haber puntos repetidos");
    ensuref(make_pair(X, Y) != make_pair(0, 0), "Los puntos no pueden estar en el origen");
    points.emplace(X, Y);
  }
  inf.readEof();
  return 0;
}
