#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string tostring(int n) {
  stringstream ss;
  ss << n;
  return ss.str();
}

int main()
{
#ifdef DEBUG
  cout << "DEBUG ON" << endl;
#endif
  string n;
  int i, c;

  cin >> n;
  for (i = 0, c = 0; i < n.length(); i++) {
    if (n[i] == '4' || n[i] == '7') c++;
  }

  bool lucky = true;
  n = tostring(c);
  for (i = 0; i < n.length(); i++) {
    if (n[i] != '4' && n[i] != '7') {
      lucky = false;
      break;
    }
  }

  cout << (lucky ? "YES" : "NO");

  return 0;
}
