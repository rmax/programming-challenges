#include <iostream>
#include <vector>

using namespace std;

typedef unsigned short int uint;

uint const DISHES_SIZE = 40;
uint const DAYS = 50;
uint const DNA_SIZE = 10;
uint const INITIAL_DISH = 20;
uint const MAX_DENSITY = 4;


const char repr(uint const& d) {
  switch (d) {
    case 0: return 'b';
    case 1: return '.';
    case 2: return 'x';
    case 3: return 'W';
  }
  return '?';
}

uint sum_density(uint left, uint center, uint right) {
#ifdef DEBUG
  if (left != 0 && center != 0 && right != 0) {
    cout << "sum_density: " << left << center << right << endl;
  }
#endif
  return (left + center + right) % MAX_DENSITY;
}

vector<uint> evolve(vector<uint> const& dishes, vector<uint> const& dna) {
  uint i;
  vector<uint> result(DISHES_SIZE, 0);

  result[0] = dna[sum_density(0, dishes[0], dishes[1])];
  for (i = 1; i < DISHES_SIZE-1; i++) {
    result[i] = dna[sum_density(dishes[i-1], dishes[i], dishes[i+1])];
  }
  result[DISHES_SIZE-1] = dna[sum_density(dishes[DISHES_SIZE-2], dishes[DISHES_SIZE-1], 0)];

  return result;
}

int main()
{
#ifdef DEBUG
  cout << "DEBUG ON" << endl;
#endif

  unsigned int n;
  uint i, j;

  cin >> n;
  do {
    vector<uint> dna(DNA_SIZE, 0);
    vector<uint> dishes(DISHES_SIZE, 0);
    dishes[INITIAL_DISH] = 1;

    for (i = 0; i < DNA_SIZE; i++) {
      cin >> dna[i];
    }

#ifdef DEBUG
    for (i = 0; i < DNA_SIZE; i++) {
      cout << dna[i] << " ";
    }
    cout << endl;
#endif

    for (i = 0; i < DAYS; i++) {
#ifdef DEBUG
      cout << "dishes size: " << dishes.size() << endl;
#endif
      for (j = 0; j < dishes.size(); j++) {
        cout << repr(dishes[j]);
      }
      cout << endl;
#ifdef DEBUG
    for (i = 0; i < dishes.size(); i++) {
      cout << dishes[i];
    }
    cout << endl;
#endif
      dishes = evolve(dishes, dna);
    }

    if (n > 1) {
      cout << endl;
    }
  } while (--n);
  return 0;
}
