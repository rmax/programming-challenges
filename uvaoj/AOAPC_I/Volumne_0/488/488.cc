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

	unsigned int n, a, f, i, j, ln;

	scanf("%d", &n);
	do {
		scanf("%d", &a);
		scanf("%d", &f);
#ifdef DEBUG
		printf("n a f -> %d %d %d\n", n, a, f);
#endif

		do {
			REP(i, a) {
				ln = i + 1;
				REP(j, ln) {
					printf("%d", ln);
				}
				printf("\n");
			}
			REP(i, a-1) {
				ln = a-1-i;
				REP(j, ln) {
					printf("%d", ln);
				}
				printf("\n");
			}
			if (f > 1) printf("\n");
		} while (--f);

		if (n > 1) printf("\n");
	} while (--n);

	return 0;
}
