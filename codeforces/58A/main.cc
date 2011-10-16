#include <iostream>

using namespace std;

int main()
{
#ifdef DEBUG
  cout << "DEBUG ON" << endl;
#endif

  string e("hello");
  string s;

  cin >> s;

  int k = 0;
  bool ok = false;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == e[k]) k++;
    if (k == e.length()) {
      ok = true;
      break;
    }
  }

  cout << ( ok ? "YES" : "NO" ) << endl;

  return 0;
}
