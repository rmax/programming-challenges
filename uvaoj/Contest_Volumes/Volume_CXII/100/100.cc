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

#define TSIZE 1000001
unsigned short table[TSIZE];

int next(int n) {
	return (n % 2 == 0) ? n >> 1 : 3*n + 1;
}

int calcCycle(int n) {
		if (n < TSIZE && table[n])
		 	return table[n];

		int m = n, c = 0;
		while (n > 1) {
			if (n < TSIZE && table[n]) {
				c += table[n] - 1;
				break;
			}
			n = next(n);
			c += 1;
		}
		table[m] = c + 1;
		return table[m];
}

int main()
{
#ifndef ONLINE_JUDGE
#ifndef DEBUG
	freopen("input.txt", "rt", stdin);
#endif
#endif

	unsigned long a, b, i, max, c, from, to;
	table[1] = 1;

	while (cin >> a >> b) {
		max = 0;
		if (a > b) {
			from = b;
			to = a;
		} else {
			from = a;
			to = b;
		}
		FOR(i, from, to+1) {
			c = calcCycle(i);
#ifdef DEBUG
			printf("(i, c) = (%lu, %lu)\n", i, c);
#endif
			max = (c > max) ? c : max;
		}
		printf("%lu %lu %lu\n", a, b, max);
	}

	return 0;
}
