#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int nsize = 5;
const string names[nsize] = {
  "Sheldon",
  "Leonard",
  "Penny",
  "Rajesh",
  "Howard",
};


int main()
{
  unsigned long n, z, x, p, y, pos, i;
  while (cin >> n) {
    n--;
    while (n >= 5) {
      n = (n-5) >> 1;
    }
    cout << names[n] << endl;
  }

  return 0;
}
