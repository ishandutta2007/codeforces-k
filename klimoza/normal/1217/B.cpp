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

#define endl '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-8;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;

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
		int n, x; cin >> n >> x;
		int maxi1 = -inf0, maxi2 = -inf0;
		for (int i = 0; i < n; i++) {
			int a, b; cin >> a >> b;
			maxi1 = max(maxi1, a - b);
			maxi2 = max(maxi2, a);
		}
		if (x - maxi2 <= 0) cout << 1 << endl;
		else {
			if (maxi1 <= 0) cout << -1 << endl;
			else {
				int d = ((max(0, x - maxi2) + maxi1 - 1) / maxi1);
				cout << d + 1 << endl;
			}
		}
	}
}