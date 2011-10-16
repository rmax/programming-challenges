#include <iostream>

using namespace std;

const int size = 20;
char board[size][size];

int main()
{
#ifdef DEBUG
  cout << "DEBUG ON" << endl;
#endif
  int n, m, i, j, k, l;
  cin >> n;
  m = 2*n + 1;
  for (i = 0; i < m; i++) {
    for (j = 0; j < m; j++) {
      if (i > n ) k = i - n;
      else k = n - i;
      if (j <= n) l = j - k;
      else l = (i>n) ? 3*n - j - i : i + n - j;
      if (j < k) cout << " ";
      if (j >= k && l >= 0) cout << l;
      if (j < n || l > 0) cout << " ";
    }
    cout << endl;
  }
  return 0;
}
