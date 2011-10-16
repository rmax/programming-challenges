#include <iostream>

using namespace std;

int main()
{
  unsigned int w, p, r;
  cin >> w;
  p = w / 2;
  r = w % 2;
  cout << ((r == 0 && p >= 2) ? "YES" : "NO");
  return 0;
}
