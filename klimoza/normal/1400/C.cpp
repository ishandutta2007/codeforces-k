/*#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC target("avx2")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
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
#include <stack>
#include <ctime>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

const double PI = acos((double)-1);
const double eps = 1e-5;
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

const int N = 1e5 + 7;

vector<int> f[N];

void solve() {
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int n = s.size();
		int x; cin >> x;
		for (int i = 0; i < x; i++)
			f[i].clear();
		for (int i = 0; i < n; i++) {
			f[i % x].push_back(i);
		}
		vector<char> ans(n, '?');
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < (int)f[i].size(); j++) {
				if ((!j || s[f[i][j - 1]] == '1') && (j == ((int)f[i].size() - 1) || s[f[i][j + 1]] == '1'))
					ans[f[i][j]] = '1';
				else
					ans[f[i][j]] = '0';
			}
		}
		bool fl = true;
		for (int i = 0; i < n; i++) {
			bool kek = ((i >= x && ans[i - x] == '1') || (i < (n - x) && ans[i + x] == '1'));
			if (kek && s[i] == '0') fl = false;
			if (!kek && s[i] == '1') fl = false;
		}
		if (!fl) cout << -1 << endl;
		else {
			for (char c : ans)
				cout << c;
			cout << endl;
		}
	}
	return;
}