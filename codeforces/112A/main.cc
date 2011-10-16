#include <iostream>
#include <string>

using namespace std;

int compare(string const& s, string const& t) {
  size_t n = s.size(), m = t.size();
  if (n != m) {
    return (n < m) ? -1 : 1;
  }
  char a, b;
  for (int i = 0; i < n; i++) {
    a = tolower(s[i]);
    b = tolower(t[i]);
    if (a != b) {
      return (a < b) ? -1 : 1;
    }
  }
  return 0;
}

int main()
{
#ifdef DEBUG
  cout << "DEBUG ON" << endl;
#endif
  string s, t;
  cin >> s >> t;
  cout << compare(s, t) << endl;
  return 0;
}
