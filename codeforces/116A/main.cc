#include <iostream>
#include <cassert>

using namespace std;

int main()
{
#ifdef DEBUG
  cout << "DEBUG ON" << endl;
#endif
  int n, a, b, c = 0, max = 0;

  cin >> n;
  while (n--) {
    cin >> a >> b;
    c += b - a;
    if (c > max) max = c;
  }
  assert(c == 0);
  cout << max << endl;
  return 0;
}
