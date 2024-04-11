#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <random>
#include <deque>
#include <bitset>
#include <string>
#include <queue>
#include <complex>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-8;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod1 = 1e9 + 7;
const ll mod2 = 777777773;
//const ll mod2 = 998244353;

void solve();
void scan();

signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;
}

void solve() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<ll> a(n);
		ll s = 0;
		vector<ll> p(n);
		multiset<ll> pref = { 0 };
		ll maxi = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			s += a[i];
			p[i] = s;
			if (i == n - 1) pref.erase(pref.find(0));
			maxi = max(maxi, p[i] - *pref.begin());
			pref.insert(p[i]);
		}
		if (s > maxi) cout << "YES\n";
		else cout << "NO\n";
	}
	return;
}