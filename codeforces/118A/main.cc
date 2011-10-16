#include <iostream>

using namespace std;

int main()
{
#ifdef DEBUG
  cout << "DEBUG ON" << endl;
#endif

  string s, t;
  char c;
  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    c = tolower(s[i]);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
      continue;
    }
    t += ".";
    t += c;
  }

  cout << t << endl;

  return 0;
}
