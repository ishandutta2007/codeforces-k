
//Karol Kaszuba

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef double D;
typedef long double LD;
typedef vector<PII> VII;
typedef unordered_set<int> USI;
typedef unordered_set<LL> USLL;

#define FOR(i,x,y) for(auto i=(x);i<=(y);++i)
#define REP(i,x) FOR(i,0,(x)-1)
#define FORD(i,x,y) for(auto i=(x);i>=(y);--i)
#define VAR(i,c) __typeof(c) i=(c)
#define FORE(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define SIZE(c) (int)((c).size())
#define ALL(c) (c).begin(),(c).end()
#define PB push_back
#define EB emplace_back
#define IN insert
#define ER erase
#define MP make_pair
#define ST first
#define ND second
#define IOSYNC ios_base::sync_with_stdio(0)
#define FREOPEN(f) freopen(f, "r", stdin),freopen(f, "w", stdout)

void jebaj() {
	int n;
	cin >> n;
	unordered_map<int, int> opens, closes;
	int zeros = 0;
	REP(i, n) {
		string s;
		cin >> s;
		int op = 0;
		int minop =0;
		for (auto c : s) {
			if (c == '(') op++;
			else op--;
			minop = min(minop, op);
		}
		if (op > 0 && minop >= 0) {
			opens[op]++;
		} else if (op == 0 && minop == 0) {
			zeros++;
		} else if (op < 0 && minop == op) {
			closes[op]++;
		}
	}
	int res = zeros/2;
	for (auto& p : opens) {
		res += min(p.ND, closes[-p.ST]);
	}
	cout << res << "\n";
}

int main() {
	IOSYNC;
	int t;
	t = 1;
	while(t--) jebaj();
	return 0;
}