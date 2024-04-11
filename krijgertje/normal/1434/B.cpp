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

int n;
char kind[2*MAXN]; int val[2*MAXN];
int ans[MAXN];

bool solve() {
	set<int> display;
	int at = n - 1;
	for (int i = 2 * n - 1; i >= 0; --i) {
		if (kind[i] == '-') {
			if (SZ(display) >= 1 && val[i] > * display.begin()) return false;
			display.insert(val[i]);
		} else {
			if (SZ(display) == 0) return false;
			ans[at--] = *display.begin();
			display.erase(display.begin());
		}
	}
	assert(at == -1);
	return true;
}

void run() {
	scanf("%d", &n);
	REP(i, 2 * n) { scanf(" %c", &kind[i]); if (kind[i] == '-') scanf("%d", &val[i]); }
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}