#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#define forn(i, n) for (i = 0; i < n; i++)
#define forv(i, v) for (i = 0; i < v.size(); i++)
#define forit(i, it) for (i = it.begin(); i != it.end(); i++)

using namespace std;

const int MAX_INT = 1<<15;
const int MAX_UINT = 1<<16;

typedef unsigned int uint;

typedef struct laptop_t {
  uint index;
  uint speed;
  uint ram;
  uint hdd;
  uint cost;

  bool outdated_by(laptop_t* other) {
    return speed < other->speed && ram < other->ram && hdd < other->hdd;
  };

  string str() {
    stringstream ss;
    ss << "[" << index << "] "
       << speed << " "
       << ram << " "
       << hdd << " "
       << cost;
    return ss.str();
  };

} laptop_t;


int main()
{
#ifdef DEBUG
  cout << "DEBUG ON" << endl;
#endif

  uint n, i;

  cin >> n;

  vector<laptop_t*> choices;
  vector<laptop_t*> candidates;
  vector<laptop_t*>::iterator it1;
  vector<laptop_t*>::iterator it2;

  forn(i, n) {
    laptop_t* l = new laptop_t;
    l->index = i+1;
    cin >> l->speed;
    cin >> l->ram;
    cin >> l->hdd;
    cin >> l->cost;
    choices.push_back(l);
  }

#ifdef DEBUG
  cout << "choices:" << endl;
  forv(i, choices) {
    cout << choices[i]->str() << endl;
  }
#endif

  bool outdated;
  forit(it1, choices) {
    outdated = false;
    forit(it2, choices) {
      if ((*it1)->outdated_by((*it2))) {
        outdated = true;
        break;
      }
    }
    if (!outdated) {
      candidates.push_back(*it1);
    }
  }

#ifdef DEBUG
  cout << "candidates:" << endl;
  forv(i, candidates) {
    cout << candidates[i]->str() << endl;
  }
#endif

  pair<uint, uint> best(MAX_UINT, 0); // cost, index

  forv(i, candidates) {
    if (best.first > candidates[i]->cost) {
      best.first = candidates[i]->cost;
      best.second = candidates[i]->index;
    }
  }

  cout << best.second << endl;

  // cleanup
  forv(i, choices) {
    delete choices[i];
  }

  return 0;
}
