#include <iostream>
#include <vector>

using namespace std;

int abs(int a) {
  return a > 0 ? a : -a;
}

int max(int a, int b) {
  return a > b ? a : b;
}

int main()
{
#ifdef DEBUG
  cout << "DEBUG ON" << endl;
#endif

  int n, i, sum, dx, dy;
  vector<int> r(8, 0);

  while (cin >> n) {
    if (!n) break;
    sum = 0;
    do {
      for (i = 0; i < 8; i++) {
        cin >> r[i];
      }
      dx = abs(r[0] - r[6]);
      dy = abs(r[1] - r[7]);
      sum += (dx > dy ? dx : dy);
    } while (--n);
    cout << sum << endl;
  }

  return 0;
}
