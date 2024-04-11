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

int n;
int a[MAXN];

bool canpref[MAXN + 1];
bool cansuff[MAXN + 1];

bool used[2 * MAXN + 1];

int solve() {
	{
		FORE(i, 1, 2 * n) used[i] = false;
		REP(i, n) used[a[i]] = true;
		int at = 0;
		canpref[0] = true;
		REP(i, n) {
			while (at <= 2 * n && (at < a[i] || used[at])) ++at;
			if (at <= 2 * n) used[at] = true;
			canpref[i + 1] = canpref[i] && at <= 2 * n;
		}
	}
	{
		FORE(i, 1, 2 * n) used[i] = false;
		REP(i, n) used[a[i]] = true;
		int at = 2 * n;
		cansuff[0] = true;
		REP(i, n) {
			while (at >= 1 && (at > a[n - i - 1] || used[at])) --at;
			if (at >= 1) used[at] = true;
			cansuff[i + 1] = cansuff[i] && at >= 1;
		}
	}

	int ret = 0;
	REPE(i, n) if (canpref[i] && cansuff[n - i]) ++ret;
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i,1,ncase) run();
	return 0;
}