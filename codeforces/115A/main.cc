#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int n, i, j;
  int p[2000];

  cin >> n;

  for (i = 0; i < n; i++) {
    cin >> p[i]; 
    if (p[i] != -1) p[i]--;
  }

  int depth, top = 0;
  for (i = 0; i < n; i++) {
    depth = 0;
    for (j = p[i]; j != -1; j = p[j]) {
      depth++;
    }
    top = max(top, depth);
  }

  cout << top + 1 << endl;

  return 0;
}
