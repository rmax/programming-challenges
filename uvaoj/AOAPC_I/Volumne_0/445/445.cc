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

	char c;
	int i, n = 0;

	while ((c = getchar()) != EOF) {
		if (c == '!' || c == '\n') {
			printf("\n");
		} else if (48 <= c && c <= 57) {
			n += atoi(&c);
		} else {
			REP(i, n) {
				printf("%c", c == 'b' ? ' ' : c);
			}
			n = 0;
		}
	}

#ifdef DEBUG
#endif

	return 0;
}
