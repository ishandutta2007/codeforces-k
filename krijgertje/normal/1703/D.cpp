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

const int MAXN = 100000;
const int MAXLEN = 8;

int n;
char s[MAXN][MAXLEN + 1];
bool ans[MAXN];

void solve() {
	set<string> have;
	REP(i, n) have.insert(s[i]);
	REP(i, n) {
		ans[i] = false;
		int len = strlen(s[i]);
		FORE(a, 1, len - 1) {
			if (have.count(string(s[i] + 0, s[i] + a)) && have.count(string(s[i] + a, s[i] + len))) { ans[i] = true; break; }
		}
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%s", s[i]);
	solve();
	REP(i, n) printf("%d", ans[i] ? 1 : 0); puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}