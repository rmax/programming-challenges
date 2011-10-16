#include <iostream>
#include <string>

using namespace std;

string clean(string const& s)
{
  string t;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ';' || s[i] == '-' || s[i] == '_') continue;
    t.push_back(tolower(s[i]));
  }
  return t;
}

int main()
{
#ifdef DEBUG
  cout << "DEBUG ON" << endl;
#endif
  string input[3];
  string combs[6];
  int i, j, k, c;

  for (i = 0; i < 3; i++) {
    cin >> input[i];
    input[i] = clean(input[i]);
    //cout << input[i] << endl;
  }

  c = 0;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (j == i) continue;
      for (k = 0; k < 3; k++) {
        if (k == j || k == i) continue;
        combs[c++] = input[i] + input[j] + input[k];
      }
    }
  }

  int n;
  bool found;
  string t;

  cin >> n;
  while (n--) {
    found = false;
    cin >> t;
    t = clean(t);
    for (i = 0; i < 6; i++) {
      if (t == combs[i]) {
        found = true;
        break;
      }
    }
    cout << (found ? "ACC" : "WA") << endl;
  }
  return 0;
}
