#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<unsigned long> solve(unsigned long const& m, unsigned long const& n) {
  unsigned long i, lastpos;
  vector<unsigned long> s(n, 1); // initial stairs
  unsigned long b = m-n; // available bricks after initialization of stairs
  unsigned long h = 2 * sqrt(b) - 1; // max initial value for larger column

#ifdef DEBUG
  cout << endl << "solve() -> ";
  cout << m << " " << n << " " << b << " " << h << endl;
#endif

  // initial fill by h-2 each time in reverse
  for (i = n-1; i >= 0; --i) {
    s[i] += h;
    b -= h;
    if (h < 2) {
      h -= 1;
    } else {
      h -= 2;
    }
    if (!h) {
      break;
    }
  }

  // locate position to start filling remaining bricks
  if (s[i] == 3) {
    lastpos = i - 1;
  } else {
    lastpos = i;
  }

  // fill remaining bricks
  while (b > 0) {
    for (i = lastpos; i < n; i++) {
      if (!b) break;
      s[i] += 1;
      b -= 1;
    }
    lastpos -= 1;
  }
  return s;
}

int main()
{
#ifdef DEBUG
  cout << "DEBUG ON" << endl;
#endif

  unsigned long c, i, j;
  unsigned long m, n;
  vector<unsigned long> solution;
  size_t size;

  cin >> c;
  for (i = 1; i <= c; i++) {
    cout << "Caso " << i << ": ";
    cin >> m >> n;
    if (m > n*(n+1)) { // limit
      cout << "IMPOSIBLE";
    } else {
      solution = solve(m, n);
      size = solution.size();
      for (j = 0; j < size; j++) {
        cout << solution[j];
        if (j < size - 1) {
          cout << " ";
        }
      }
    }
    cout << endl;
  }

  return 0;
}
