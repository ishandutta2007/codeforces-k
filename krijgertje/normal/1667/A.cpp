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
#include <functional>
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

const int MAXN = 5000;

int n;
int a[MAXN];

ll solve() {
	ll ret = LLONG_MAX;
	REP(i, n) {
		ll cur = 0;
		ll last = 0;
		FOR(j, i + 1, n) {
			ll times = (last + 1 + a[j] - 1) / a[j];
			cur += times;
			//printf("\t%d: %lld\n", j, times);
			last = times * a[j];
		}
		last = 0;
		for (int j = i - 1; j >= 0; --j) {
			ll times = (last + 1 + a[j] - 1) / a[j];
			cur += times;
			//printf("\t%d: %lld\n", j, times);
			last = times * a[j];
		}
		ret = min(ret, cur);
		//printf("%d: %lld\n", i, cur);
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}