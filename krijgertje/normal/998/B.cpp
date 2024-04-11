#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
using namespace std;

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN = 100;

int n, budget;
int a[MAXN];

int opt[MAXN], nopt;

void run() {
	scanf("%d%d", &n, &budget); REP(i, n) scanf("%d", &a[i]);
	
	nopt = 0; int bal = 0;
	REP(i, n) { bal += (a[i] % 2 == 0 ? +1 : -1); if (i != n - 1 && bal == 0) opt[nopt++] = abs(a[i] - a[i + 1]); }
	sort(opt, opt + nopt);
	int ret = 0, rem = budget;
	REP(i, nopt) if (rem >= opt[i]) { rem -= opt[i]; ++ret; }
	printf("%d\n", ret);
}

int main() {
	run();
	return 0;
}