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
	int max, i, j;
	string line;
	vector<int>  sizes;
	vector<string> lines;

	while (getline(cin, line)) {
		lines.push_back(line);
		sizes.push_back(line.length());
#ifdef DEBUG
		cout << line << endl;
#endif
	}

	max = *max_element(sizes.begin(), sizes.end());
#ifdef DEBUG
	cout << "max: " << max << endl;
#endif

	REP(i, max) {
		for (j=lines.size()-1; j >= 0; --j) {
			if (i < sizes[j]) {
				cout << lines[j][i];
			} else {
				cout << " ";
			}
		}
		cout << endl;
	}

	return 0;
}
