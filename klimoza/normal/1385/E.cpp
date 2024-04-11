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

mt19937 mrand(239);

const double PI = acos((double)-1);
const double eps = 1e-5;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 7;
const ll mod = 998244353;

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

const int N = 2e5 + 7;

int used[N];
vector<int> g[N];

vector<int> topsort;
bool f = false;

void dfs(int v) {
	used[v] = 1;
	for (int u : g[v]) {
		if (used[u] == 1) {
			f = true;
			return;
		}
		if (used[u] == 2) continue;
		dfs(u);
	}
	used[v] = 2;
	topsort.push_back(v);
}

void solve(){
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		topsort.clear();
		for (int i = 0; i < n; i++) {
			used[i] = 0;
			g[i].clear();
		}
		f = false;
		vector<pair<int, int>> ed;
		vector<pair<int, int>> kek;
		for (int i = 0; i < m; i++) {
			int t, a, b; cin >> t >> a >> b; a--; b--;
			if (t == 0) {
				kek.push_back({ a, b }); 
			}
			else {
				ed.push_back({ a, b });
				g[a].push_back(b);
			}
		}
		for (int i = 0; i < n; i++) {
			if (!used[i]) {
				dfs(i);
			}
		}
		if (f) cout << "NO\n";
		else {
			reverse(all(topsort));
			vector<int> rv(n);
			for (int i = 0; i < n; i++) {
				rv[topsort[i]] = i;
			}
			cout << "YES\n";
			for (auto u : ed)
				cout << u.first + 1 << " " << u.second + 1 << endl;
			for (auto u : kek) {
				if (rv[u.first] > rv[u.second]) swap(u.first, u.second);
				cout << u.first + 1 << " " << u.second + 1 << endl;
			}
		}
	}
	return;
}