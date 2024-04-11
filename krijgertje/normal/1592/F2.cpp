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

const int MAXDIM = 500;

int h, w;
char g[MAXDIM][MAXDIM + 1];

int a[MAXDIM][MAXDIM];

int nl, nr;
vector<vector<int>> adj;
vector<bool> done;
vector<int> match;

bool augment(int at) {
	if (done[at]) return false;
	done[at] = true;
	for (int to : adj[at]) {
		if (match[to] == -1 || augment(match[to])) {
			match[to] = at;
			return true;
		}
	}
	return false;
}

int calcmxmatch() {
	int ret = 0;
	match = vector<int>(nr, -1);
	done = vector<bool>(nl, false);
	REP(i, nl) {
		if (augment(i)) {
			++ret;
			done = vector<bool>(nl, false);
		}
	}
	return ret;
}

int solve() {
	REP(x, h) REP(y, w) {
		int cnt = 0;
		REP(dx, 2) REP(dy, 2) {
			int nx = x + dx, ny = y + dy;
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (g[nx][ny] == 'B') ++cnt;
		}
		a[x][y] = cnt % 2;
	}
	//REP(x, h) { REP(y, w) printf("%d", a[x][y]); puts(""); }

	nl = w - 1;
	nr = h - 1;
	adj = vector<vector<int>>(nl);
	REP(x, h - 1) REP(y, w - 1) if (a[x][y] && a[h - 1][y] && a[x][w - 1]) adj[y].PB(x);
	int nmatch = calcmxmatch();
	int ret = 0;
	REP(x, h) REP(y, w) if (a[x][y]) ++ret;
	ret -= nmatch;
	if (nmatch % 2 == 1) ret += a[h - 1][w - 1] == 1 ? -1 : +1;
	return ret;
}

void run() {
	scanf("%d%d", &h, &w);
	REP(x, h) scanf("%s", g[x]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}