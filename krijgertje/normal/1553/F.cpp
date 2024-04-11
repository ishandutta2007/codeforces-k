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

const int MAXN = 200000;
const int MAXVAL = 300000;

int n;
int a[MAXN];
ll ans[MAXN];

struct BIT {
	int n; vector<ll> val;
	void init(int _n) { n = _n; val = vector<ll>(n + 1, 0); }
	void mod(int idx, ll by) { ++idx; while (idx <= n) { val[idx] += by; idx += idx & -idx; } }
	ll get(int idx) { ++idx; ll ret = 0; while (idx > 0) { ret += val[idx]; idx -= idx & -idx; } return ret; }
};
BIT bit;


void solve() {
	int mxval = a[0]; FOR(i, 1, n) mxval = max(mxval, a[i]);
	REP(i, n) ans[i] = 0;
	{ // i<j: a[i]%a[j]
		bit.init(mxval + 1);
		ll sum = 0; int cnt = 0;
		REP(i, n) {
			ans[i] += sum;
			for (int t = 1; t * a[i] <= mxval; ++t) {
				int cur = cnt - bit.get(t * a[i] - 1);
				ans[i] -= (ll)cur * a[i];
			}
			sum += a[i]; ++cnt;
			bit.mod(a[i], +1);
		}
	}
	{ // i<j: a[j]%a[i]
		bit.init(mxval + 1);
		ll sum = 0; int cnt = 0;
		REP(i, n) {
			ans[i] += (ll)cnt * a[i];
			ll cur = bit.get(a[i]);
			ans[i] -= cur;
			for (int t = 1; t * a[i] <= mxval; ++t) {
				bit.mod(t * a[i], a[i]);
			}
			sum += a[i]; ++cnt;
		}
	}

	FOR(i, 1, n) ans[i] += ans[i - 1];
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%lld", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}