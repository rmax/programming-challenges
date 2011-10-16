#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>

using namespace std;

#include <stdio.h>

#define REP(i,a) for(i=0;i<a;i++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define VE vector<int>
#define SZ size()
#define PB push_back
#define UI unsigned int
#define UL unsigned long
#define LL long long
#define ULL unsigned long long


const char* WIN = "You win.";
const char* LOSE = "You lose.";
const char* CHICKEN = "You chickened out.";
const unsigned int MAX_STROKES = 7;

const char* solve(string solution, string& guesses) {
  bool found;
  char c;
  set<char> wrongs;
  set<char>::iterator it;
  size_t idx;
  unsigned int strokes = 0, i;

  for (i = 0; i < guesses.length(); ++i) {
    c = guesses[i];
#ifdef DEBUG
    cout << "searching " << c << " in " << solution << endl;
    cout << "wrongs: ";
    for (it = wrongs.begin(); it != wrongs.end(); ++it) {
      cout << *it << " ";
    }
    cout << endl;
#endif
    // search for char and erase occurrences
    found = false;
    while ((idx = solution.find(c)) != string::npos) {
#ifdef DEBUG
      cout << "found idx: " << idx << endl;
#endif
      found = true;
      solution.erase(idx, 1);
    }

    if (found) {
#ifdef DEBUG
      cout << "solution remaining: " << solution << endl;
#endif
      if (solution.empty()) {
        return WIN;
      }
    // only count wrongs once
    // count strokes if wrong not found in set
    } else if (wrongs.find(c) == wrongs.end()) {
      ++strokes;
      wrongs.insert(c);
#ifdef DEBUG
      cout << "wrong " << c << " strokes " << strokes << endl;
#endif
      if (strokes >= MAX_STROKES) {
        break;
      }
    }
  }

  return (strokes < MAX_STROKES) ? CHICKEN: LOSE;
}

int main()
{
#ifndef ONLINE_JUDGE
  (void)freopen("input.txt", "rt", stdin);
#endif

  int n;
  string solution;
  string guesses;

  while (cin >> n) {
    if (n == -1) break;
    cin.ignore(1); // \n
    getline(cin, solution);
    getline(cin, guesses);
    cout << "Round " << n << endl;
#ifdef DEBUG
    cout << "solution: " << solution << endl;
    cout << "guesses: " << guesses << endl;
#endif
    cout << solve(solution, guesses) << endl;;
  }

  return 0;
}
