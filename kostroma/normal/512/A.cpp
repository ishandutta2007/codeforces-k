#pragma comment (linker, "/STACK:128000000")
//#include "testlib.h"
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>
#include <ctime>
#include <stack>
#include <queue>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve();
void precalc();
clock_t start;
//int timer = 1;

bool doing = true;

int main() {
#ifdef room111
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen(FILENAME".in", "r", stdin);
	//freopen(FILENAME ".out", "w", stdout);
#endif
	int t = 1;
	cout.sync_with_stdio(0);
	cin.tie(0);
	precalc();
	cout.precision(10);
	cout << fixed;
	//cin >> t;
	start = clock();
	int testNum = 1;
	while (t--) {
		//cout << "Case #" << testNum++ << ": ";
		solve();
		//++timer;
	}

#ifdef room111
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

	return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

void precalc() {
	

}

int binpow(int q, int w, int mod) {
	if (!w)
		return 1;
	if (w & 1)
		return q * binpow(q, w - 1, mod) % mod;
	return binpow(q * q % mod, w / 2, mod);
}

int gcd(int q, int w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

//int mod = 1000000007;

//ld eps = 1e-9;

int n;
vector<string> s;

vector<int> edges[26];

vector<int> topsort;
vector<char> used;

void dfs(int v) {
	if (used[v])
		return;
	used[v] = true;
	for (int to : edges[v]) {
		dfs(to);
	}
	topsort.push_back(v);
}

void solve() {
	cin >> n;
	s.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	
	for (int i = 0; i + 1 < n; ++i) {
		bool f = true;
		for (int j = 0; j < s[i].length() && j < s[i + 1].length(); ++j) {
			if (s[i][j] != s[i + 1][j]) {
				edges[s[i][j] - 'a'].push_back(s[i + 1][j] - 'a');
				f = false;
				break;
			}
		}
		if (f && s[i].length() >= s[i + 1].length()) {
			cout << "Impossible\n";
			return;
		}
	}

	used.assign(26, false);

	for (int i = 0; i < 26; ++i) {
		if (!used[i]) {
			dfs(i);
		}
	}

	vector<int> pos(26);
	for (int i = 0; i < 26; ++i) {
		pos[topsort[i]] = i;
	}

	for (int i = 0; i < 26; ++i) {
		for (int to : edges[i]) {
			if (pos[to] > pos[i]) {
				cout << "Impossible\n";
				return;
			}
		}
	}

	for (int i = 0; i < 26; ++i) {
		cout << char('a' + topsort[25 - i]);
	}

}