#include <iostream>

using namespace std;

int main()
{
#ifdef DEBUG
  cout << "DEBUG ON" << endl;
#endif
  string a, b;

  cin >> a >> b;
  for (int i = 0; i < a.length(); i++) {
    if (a[i] != b[i]) cout << 1;
    else cout << 0;
  }
  cout << endl;
  return 0;
}
