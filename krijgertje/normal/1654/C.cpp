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

const int MAXN = 200000;

int n;
int a[MAXN];

bool solve() {
	ll sum = 0;
	REP(i, n) sum += a[i];
	multiset<ll> rem;
	REP(i, n) rem.insert(a[i]);
	queue<ll> q;
	q.push(sum);
	while (!q.empty()) {
		if (SZ(q) > SZ(rem)) return false;
		ll cur = q.front(); q.pop();
		auto it = rem.find(cur);
		if (it != rem.end()) { rem.erase(it); continue; }
		ll a = cur / 2, b = cur - a;
		if (a <= 0 || b <= 0) return false;
		q.push(a);
		q.push(b);
	}
	assert(SZ(rem) == 0);
	return true;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%s\n", solve() ? "YES" : "NO");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}