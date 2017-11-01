/*
 * -----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nlehmann@dcc.uchile.cl> wrote this file. As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you
 * think this stuff is worth it, you can buy me a beer in return Nicolás Lehmann
 * -----------------------------------------------------------------------------
 */
#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;

  int digits = 1;
  int pow = 1;
  int row = 0;
  int col = 0;
  int pages = 1;
  for (int i = 1; i <= N; ++i) {
    if (pow * 10 == i) {
      pow = i;
      digits += 1;
    }
    if (col + digits > 28) {
      for (int j = 0; j < 28 - col; ++j)
        cerr << "_";
      col = 0;
      row += 1;
      cerr << "\n";
    }
    if (row == 35) {
      row = 0;
      pages += 1;
      cerr << "--------------------\n";
    }
    cerr << i << "|";
    col += digits;
  }
  if (row == 0 && col == 0)
    pages -= 1;

  cerr << "\n\n\n";
  cout << pages << "\n";

  return 0;
}
