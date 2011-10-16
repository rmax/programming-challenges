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

	// positive integers <= 100000
	UI n, f, a, b, c;
	// result can be 1e5^2 * 20
	ULL result;

	scanf("%d", &n);
	do {
		scanf("%d", &f);
		result = 0;
		do {
			scanf("%d %d %d", &a, &b, &c);
			result += a * c;
		} while (--f > 0);
		printf("%ld\n", result);
	} while (--n > 0);

	return 0;
}
