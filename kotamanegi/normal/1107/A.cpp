#define  _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#pragma comment (linker, "/STACK:526000000")

#include "bits/stdc++.h"
#define int ll

using namespace std;
typedef string::const_iterator State;
#define eps 1e-9L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()
void init() {
	iostream::sync_with_stdio(false);
	cout << fixed << setprecision(20);
}
void solve() {
	int n;
	string s;
	cin >> n >> s;
	if (s.length() == 2) {
		if (s[0] >= s[1]) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	cout << 2 << endl;
	cout << s[0] << " ";
	s.erase(s.begin());
	cout << s << endl;
}
#undef int
int main() {
	init();
	int t;
	cin >> t;
	REP(tea, t) {
		solve();
	}
}