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
	UL a, b, c;

	while (scanf("%ld %ld", &a, &b) != EOF) {
		c = a > b ? a -b : b - a;
#ifdef DEBUG
		printf("%ld %ld %ld\n", a, b, c);
#else
		printf("%ld\n", c);
#endif
	}

	return 0;
}
