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

string s; int k;

string solve() {
	vector<string> patterns;
	patterns.PB(s);
	for (int i = SZ(s) - 1; i >= 0; --i) for (int x = s[i] - '0' + 1; x <= 9; ++x) patterns.PB(s.substr(0, i) + string(1, '0' + x) + string(SZ(s) - i - 1, '*'));
	patterns.PB("1" + string(SZ(s), '0'));
	patterns.PB(string(SZ(s) + 1, '1'));
	for (auto p : patterns) {
		//printf("\t%s\n", p.c_str());
		int have = 0;
		vector<bool> seen(10, false);
		REPSZ(i, p) if (p[i] != '*') { int x = p[i] - '0'; if (seen[x]) continue; seen[x] = true; ++have; }
		if (have > k) continue;
		int lo = 0; if (have == k) while (!seen[lo]) ++lo;
		REPSZ(i, p) if (p[i] == '*') p[i] = '0' + lo;
		return p;
	}
	assert(false);
	return "";
}

void run() {
	cin >> s; scanf("%d", &k);
	printf("%s\n", solve().c_str());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}