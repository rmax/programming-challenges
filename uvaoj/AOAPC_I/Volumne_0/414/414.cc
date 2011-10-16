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

#define REP(i,a) for(i=0;i<a;i++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define VE vector<int>
#define SZ size()
#define PB push_back
#define UI unsigned int
#define UL unsigned long
#define LL long long
#define ULL unsigned long long

#pragma comment(linker, "/STACK:16777216")


int main()
{
	UI n, i, min, ret;
	string line;
	VE spaces;

	while (1) {
		cin >> n;
		if (n == 0) break;
		cin.ignore(1); // \n

		REP(i, n) {
			getline(cin, line, '\n');
			spaces.push_back(count(line.begin(), line.end(), ' '));
#ifdef DEBUG
			cout << line << endl;
#endif
		}

#ifdef DEBUG
		cout << "spaces: ";
		REP(i, spaces.size()) {
			cout << spaces[i] << " ";
		}
		cout << endl;
#endif

		min = *min_element(spaces.begin(), spaces.end());
#ifdef DEBUG
		cout << "min: " << min << endl;
#endif
		ret = 0;
		REP(i, spaces.size()) {
			ret += spaces[i] - min;
		}
		cout << ret << endl;

		spaces.clear();
	}

	return 0;
}
