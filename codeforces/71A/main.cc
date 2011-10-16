#include <iostream>
#include <string>
#include <iterator>

using namespace std;

int main()
{
  string s;
  short int n;

  cin >> n;
  while(n--) {
    cin >> s;
    if (s.length() > 10) {
      cout << s[0] << distance(s.begin()+1, s.end()-1) << s[s.length()-1];
    } else {
      cout << s;
    }
    cout << endl;
  }
  return 0;
}
