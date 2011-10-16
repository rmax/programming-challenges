#include <iostream>

using namespace std;

int main()
{
#ifdef DEBUG
  cout << "DEBUG ON" << endl;
#endif
  int m, n;
  cin >> m >> n;
  cout << (m*n) / 2;
  return 0;
}
