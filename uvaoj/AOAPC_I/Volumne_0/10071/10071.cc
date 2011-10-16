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

//#pragma comment(linker, "/STACK:16777216")


/**
 *  two integers each line (v, t)
 *  -100 <= v <= 100
 *  0 <= t <= 200
 */
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif

	int v, t;

	while (scanf("%d %d", &v, &t) != EOF) {
#ifdef DEBUG
		printf("%d %d ", v, t);
#endif
		printf("%d\n", v*2*t);
	}

	return 0;
}
