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

#pragma comment(linker, "/STACK:16777216")


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif

	int c, inword = 0;
	ULL words = 0;

	while ((c = getchar()) != EOF) {
		if (c == 10) { // \n
			if (inword) {
				words += 1;
				inword = 0;
			}
			printf("%d\n", words);
			words = 0;
		} else {
			// A-Z or a-z
			if ((65 <= c and c <= 90) || (97 <= c and c <= 122)) {
				inword = 1;
			} else {
				if (inword) {
					words += 1;
					inword = 0;
				}
			}
		}
	}

	return 0;
}
