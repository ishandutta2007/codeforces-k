#pragma comment (linker, "/STACK:526000000")
#define  _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()
void init() {
	iostream::sync_with_stdio(false);
	cout << fixed << setprecision(100);
}

#define int ll
void solve() {
	int n;
	cin >> n;
	REP(i, n) {
		string s;
		cin >> s;
		int a, b;
		cin >> a >> b;
		if (a >= 2400 && a < b) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}
#undef int
int main() {
	init();
	solve();
}