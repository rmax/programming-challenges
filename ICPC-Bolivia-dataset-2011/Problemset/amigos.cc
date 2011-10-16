#include <iostream>

using namespace std;

unsigned long sumDivisors(unsigned long k) {
  unsigned long sum = 1;
  for (int i = 2; i < (k/2) + 1; i++) {
    if (k % i == 0) sum += i;
  }
  return sum;
}

int main()
{
#ifdef DEBUG
  cout << "DEBUG ON" << endl;
#endif

  unsigned long n, m;

  while (cin >> n) {
    if (n == 0) break;
    if (n > 5) {
      m = sumDivisors(n);
      if (n == sumDivisors(m)) {
        cout << m << endl;
        continue;
      }
    }
    cout << -1 << endl;
  }
  return 0;
}
