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

const int MAXN = 200000;

int n;
int b[MAXN];

int x[MAXN];
int xx[MAXN], nxx;
ll sum[MAXN];

ll solve() {
	REP(i, n) x[i] = b[i] - i;
	nxx = 0; REP(i, n) xx[nxx++] = x[i]; sort(xx, xx + nxx); nxx = unique(xx, xx + nxx) - xx; REP(i, n) x[i] = lower_bound(xx, xx + nxx, x[i]) - xx;
	//printf("x:"); REP(i, n) printf(" %d", x[i]); puts("");
	REP(i, nxx) sum[i] = 0;
	REP(i, n) sum[x[i]] += b[i];
	ll ret = 0; REP(i, nxx) ret = max(ret, sum[i]); return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &b[i]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}