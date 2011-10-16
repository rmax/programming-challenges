#include <iostream>
#include <cmath>

using namespace std;

int main()
{
#ifdef DEBUG
  cout << "DEBUG ON" << endl;
#endif

  unsigned long long n, m, l1, l2, a;

  while (cin >> n >> m >> a) {
    l1 = ceil(n / double(a));
    l2 = ceil(m / double(a));
    cout << l1*l2 << endl;
  }

  return 0;
}
