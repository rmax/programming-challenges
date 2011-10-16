#include <iostream>

using namespace std;

int main()
{
  const int M = 150;
  const char W = 'W';
  int n, m, i, j;
  char g[M][M];
  int l[M];
  int r[M];
  bool found;
  int moves = 0;

  cin >> n >> m;

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> g[i][j];
    }
  }

  for (i = 0; i < n; i++) {
    l[i] = 0;
    while (l[i] < m && g[i][j] != W) l[i]++;
    r[i] = m-1;
    while (r[i] >= 0 && g[i][j] != W) r[i]--;
#ifdef DEBUG
    cout << l[i] << "->" << r[i] << endl;
#endif
  }

  return 0;
  for (j = m-1; j >= 0; j--) {
    i = n;
    while (--i && i >= 0 && g[i][j] == W);
    n = i - 1;
    if (i >= 0) {
      break;
    }
  }

  moves = 0;
  cout << "n:" << n << endl;
  if (n > 0) {
    for (i = 0; i < n; i++) {
      if (i % 2 == 0) {
        cout << "right: " << l[i] << "->" << r[i] << endl;
      } else {
        cout << "left: " << l[i] << "<-" << r[i] << endl;
      }
    }
  }

  cout << moves;

  return 0;
}
