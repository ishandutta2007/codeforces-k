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

const int MAXN = 150000;
const int MOD = 998244353;

int n;
int a[2 * MAXN];

int inv[2 * MAXN + 1];
int fac[2 * MAXN + 1];
int ifac[2 * MAXN + 1];

int solve() {
	inv[1] = 1; FORE(i, 2, 2 * n) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, 2 * n) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, 2 * n) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;

	sort(a, a + 2 * n);
	int lo = 0; REP(i, n) lo = (lo + a[i]) % MOD;
	int hi = 0; REP(i, n) hi = (hi + a[n + i]) % MOD;
	
	int ret = hi - lo; if (ret < 0) ret += MOD;
	int mlt = (ll)fac[2 * n - 1] * ifac[n - 1] % MOD * ifac[n] % MOD;
	return (ll)2 * ret * mlt % MOD;
}

void run() {
	scanf("%d", &n);
	REP(i, 2 * n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}