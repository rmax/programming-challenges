#include <iostream>
#include <map>
#include <cassert>
#include <cmath>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

typedef unsigned long long ll;

const char base[37] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const ll roval[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
const string ronum[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

ll ctoi(char c)
{
  int i;
  for (i = 0; i < 37; i++) {
    if (base[i] == c) return ll(i);
  }
  assert(i < 37);
}

char itoc(int n)
{
  assert(n < 37);
  return base[n];
}


ll stol(string const& s, int base)
{
  ll ret = 0;
  int l = s.length();
  int i, j;
  for (i = 0; i < l; i++) {
    if (s[i] != '0') break;
  }
  for (j = l; j > i; j--) {
    ret += ll(ctoi(s[j-1])) * pow(ll(base), ll(l-j));
  }
  return ret;
}

string ltos(ll n, int base)
{
  string ret;
  ll lbase = ll(base);
  ll r;
  while (n >= lbase) {
    r = n % lbase;
    n /= lbase;
    ret += itoc(r);
  }
  assert(n < lbase);
  ret += itoc(int(n));
  return string(ret.rbegin(), ret.rend());
}

string ltor(ll n)
{
  string r;
  for (int i = 0; i < 13; i++) {
    while (n >= ll(roval[i])) {
      n -= ll(roval[i]);
      r.append(ronum[i]);
    }
  }
  return r;
}

int main()
{
#ifdef DEBUG
  cout << "DEBUG ON" << endl;
#endif
  int a, b = 0;
  ll  n;
  string c;
  char roman[3];

  cin >> a;
  cin >> roman;
  c.reserve(1000);
  cin >> c;
  n = stol(c, a);
#ifdef DEBUG
  cout << a << " " << b << " " << c << endl;
  cout << n << endl;
#endif

  if (roman[0] == 'R') {
    cout << ltor(n) << endl;
  } else {
    b = atoi(roman);
#ifdef DEBUG
    cout << b << endl;
#endif
    cout << ltos(n, b) << endl;
  }
  return 0;
}
