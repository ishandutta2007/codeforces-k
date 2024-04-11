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
//const ll mod = 1e9 + 9;
const ll mod = 998244353;
const ll mod2 = mod * mod;

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
	int t; cin >> t;
	while (t--) {
		int n, p, k; cin >> n >> p >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(all(a));
		vector<ll> tmp(k, 0);
		int ans = 0;
		ll cur = 0;
		for (int i = 0; i < min(k - 1, n); i++) {
			cur += a[i];
			if (cur > p) {
				tmp[(i + 1) % k] = -1;
				continue;
			}
			ans = max(ans, i + 1);
			tmp[(i + 1) % k] = cur;
		}
		for (int i = k - 1; i < n; i++) {
			if (tmp[(i + 1) % k] == -1) continue;
			tmp[(i + 1) % k] += a[i];
			if (tmp[(i + 1) % k] > p) {
				tmp[(i + 1) % k] = -1;
				continue;
			}
			ans = max(ans, i + 1);
		}
		cout << ans << endl;
	}
	return;
}