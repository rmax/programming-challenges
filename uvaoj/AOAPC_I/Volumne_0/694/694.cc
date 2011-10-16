#include <iostream>

using namespace std;

long solve(long long a, long long const& l) {
  long t = 0;
  while (a > 1 && a <= l) {
    a = (a & 1) ? (3*a + 1) : a >> 1;
    ++t;
  }
  if (a == 1) {
    ++t;
  }
  return t;
}

int main()
{
#ifdef DEBUG
  cout << "DEBUG ON" << endl;
#endif

  long long a, l;
  unsigned int i = 0;
  while (cin >> a >> l) {
    if (a < 0 || l < 0) break;
    cout << "Case " << ++i << ": "
         << "A = " << a << ", "
         << "limit = " << l << ", "
         << "number of terms = " << solve(a, l)
         << endl;
  }
  return 0;
}
