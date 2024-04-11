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

char s[10 + 1];

int solve() {
	int ret = 10;
	REP(win, 2) {
		int bal = 0;
		REP(i, 10) {
			char c = s[i] != '?' ? s[i] : i % 2 == win % 2 ? '1' : '0';
			if (c == '1') bal += i % 2 == win % 2 ? +1 : -1;
			int mnbal = bal;
			FOR(j, i + 1, 10) if (j % 2 != win % 2) --mnbal;
			if (mnbal > 0) ret = min(ret, i + 1);
		}
	}
	return ret;
}

void run() {
	scanf("%s", s);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}