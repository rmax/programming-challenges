#include <iostream>
#include <vector>
#include <cmath>

#define SQ(x) ((x)*(x))
#define YES "SI"
#define NO "NO"

using namespace std;

double dist(vector<int>& x, vector<int>& y) {
  long double sum = 0;
  for (int i = 0; i < 3; i++) {
    sum += SQ(x[i] - y[i]);
  }
  return sqrt(sum);
}

int main()
{
  unsigned short int i;
  unsigned int r1, r2, temp;
  double d;
  vector<int> v1(3, 0), v2(3, 0);

  while (cin >> r1 >> r2) {
    if (r1 == 0 || r2 == 0) break;

    for (i = 0; i < 3; i++) {
      cin >> v1[i];
    }
    for (i = 0; i < 3; i++) {
      cin >> v2[i];
    }

    for (i = 0; i < 3; i++) {
      cin >> temp;
      v1[i] += temp;
    }
    for (i = 0; i < 3; i++) {
      cin >> temp;
      v2[i] += temp;
    }

    d = dist(v1, v2);
    cout << ((d > r1 + r2) ? NO : YES) << endl;
  }

  return 0;
}
