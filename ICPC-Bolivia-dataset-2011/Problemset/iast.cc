#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;


void lower(string& s) {
  transform(s.begin(), s.end(), s.begin(), ::tolower);
}

bool iat(string const& s) {
  // min 4
  int i, len = s.length(), last = len - 1;
  string sub;

  if (len < 4) {
#ifdef DEBUG
    cout << "* IAT length < 4: " << s << endl;
#endif
    return false;
  }
  if (s[0] != 'u' && s[0] != 'e') {
#ifdef DEBUG
    cout << "* IAT not starts [ue]: " << s << endl;
#endif
    return false;
  }
  if (s[1] == 'f') {
    // move cursor above all f's
    i = 2;
    while (s[i] == 'f' && i < len) ++i;
#ifdef DEBUG
    cout << "* f's for " << s << " until " << i << endl;
#endif
    if (i == last-1 && s[i] == 'a' && s[i+1] == 'r') {
#ifdef DEBUG
      cout << "* IAT ends with ar" << endl;
#endif
      return true;
    }
    if (i == last-2 && s[i] == 'i' && s[i+1] == 'a' && s[i+2] == 'g') {
#ifdef DEBUG
      cout << "* IAT ends with iag" << endl;
#endif
      return true;
    }
    sub = s.substr(i, len-i);
#ifdef DEBUG
    cout << "* checking for IAT: " << sub << endl;
#endif
    if (iat(sub)) {
      return true;
    }
  } else {
#ifdef DEBUG
  cout << "* no follows f: " << s << endl;
#endif
  }
  return false;
}

bool ias(string const& s) {
  // min 2 or 4
  size_t len = s.length(), last = len - 1;
  if (s[0] != 'o') return false;
  if (len == 2 && s[1] == 'h') return true;
  if (len < 4) return false;
  if (s[1] == 'w' && s[last] == 'a' && len > 3 && ias(s.substr(2, last-2))) return true;
  if (s[last] == 'a' && iat(s.substr(1, last-1))) return true;
  return false;
}

bool iast(string const& s) {
  size_t len = s.length(), last = len - 1;
  string sub;

  if (len < 7) {
#ifdef DEBUG
    cout << "* lower than 7" << endl;
#endif
    return false;
  }
  if (s[last] != '!' && s[last] != '?') {
#ifdef DEBUG
    cout << "* no ending [!?]" << endl;
#endif
    return false;
  }
  // search for IAS until length - 4
  int i, j;
  bool found = false;
  for (i = 2; i < len - 4; i++) {
    sub = s.substr(0, i);
#ifdef DEBUG
    cout << "* checking for IAS: " << sub << endl;
#endif
    if (ias(sub)) {
      found = true;
      break;
    }
  }

#ifdef DEBUG
  if (found) cout << "* found IAS: " << sub << " at 0-" << i << endl;
  else cout << "* no IAS found until " << i << endl;
#endif

  sub = s.substr(i, last-i);
  if (found && iat(sub)) {
#ifdef DEBUG
  cout << "* found IAT: " << sub << endl;
#endif
    return true;
  }

#ifdef DEBUG
  cout << "* not IAT: " << sub << endl;
#endif

  return false;
}


int main()
{
#ifdef DEBUG
  cout << "* DEBUG ON" << endl;
#endif

  int n;
  string s;

  cin >> n;

  do {
    cin >> s;
    lower(s);
#ifdef DEBUG
    cout << "* string: " << s << endl;
#endif
    cout << (iast(s) ? "ES IAST" : "NO IAST") << endl;
  } while (--n);

  return 0;
}
