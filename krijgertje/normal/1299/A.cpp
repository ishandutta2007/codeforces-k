#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 100000;

int n;
int a[MAXN];
int ans[MAXN];

void solve() {
	int mx = a[0]; FOR(i, 1, n) mx = max(mx, a[i]);
	if (mx == 0) { REP(i, n) ans[i] = a[i]; return; }
	int mxbit = 0; while ((2 << mxbit) <= mx) ++mxbit;
	for (int bit = mxbit; bit >= 0; --bit) {
		int fst = -1, cnt = 0;
		REP(i, n) if (a[i] & (1 << bit)) { if (fst == -1) fst = i; ++cnt; }
		if (cnt == 1) { ans[0] = a[fst]; int at = 1; REP(i, n) if (i != fst) ans[at++] = a[i]; return; }
	}
	REP(i, n) ans[i] = a[i];
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}