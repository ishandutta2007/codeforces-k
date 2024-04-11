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
#include <chrono>
#include <random>
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
std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

const int MAXN = 100000;

int n, fst, step;
char a[MAXN + 1];
int makeonecost, remfirstcost;

ll dp[MAXN]; // cost 'from here', assuming this is the first spot that is hit

ll solve() {
	for (int i = n - 1; i >= 0; --i) {
		dp[i] = 0;
		if (a[i] == '0') dp[i] += makeonecost;
		if (i + step < n) dp[i] += dp[i + step];
	}
	ll ret = LLONG_MAX;
	FOR(i, fst, n) {
		ll cur = (ll)(i - fst) * remfirstcost + dp[i];
		ret = min(ret, cur);
	}
	return ret;
}

void run() {
	scanf("%d%d%d", &n, &fst, &step); --fst;
	scanf("%s", a); assert(strlen(a) == n);
	scanf("%d%d", &makeonecost, &remfirstcost);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}