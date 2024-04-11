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

const int MAXN = 1000;
struct Op { char kind; int x, y; Op() {} Op(char kind, int x, int y) :kind(kind), x(x), y(y) {} };

int n;
int a[MAXN];
vector<Op> ans;

void solve() {
	ans.clear();
	for (int x = 0; x < n; x += 2) {
		int y = x + 1;
		ans.PB(Op('1', x, y));
		ans.PB(Op('2', x, y));
		ans.PB(Op('1', x, y));
		ans.PB(Op('1', x, y));
		ans.PB(Op('2', x, y));
		ans.PB(Op('1', x, y));
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) printf("%c %d %d\n", ans[i].kind, ans[i].x + 1, ans[i].y + 1);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}