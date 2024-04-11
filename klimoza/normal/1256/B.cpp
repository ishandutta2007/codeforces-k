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
	int q; cin >> q;
	while (q--) {
		int n; cin >> n;
		vector<int> a(n);
		vector<int> f(n + 1);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			f[a [i]] = i;
		}
		vector<bool> used(n, false);
		for (int i = 1; i <= n; i++) {
			for (int j = f[i] - 1; j >= 0; j--) {
				if (!used[j] && a[j] > a[j + 1]) {
					f[a[j]]++;
					used[j] = true;
					swap(a[j], a[j + 1]);
				}
				else {
					break;
				}
			}
		}
		for (int i : a) cout << i << " ";
		cout << endl;

	}
}