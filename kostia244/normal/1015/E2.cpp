#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma comment(linker, "/STACK:16777216")
//#pragma GCC target ("avx2,tune=native")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define pb push_back
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oit ostream_iterator
#define mod 1000000007ll
using namespace std;
using namespace __gnu_pbds;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
}
template<typename X, typename Y>
istream& operator>>(istream& in, pair<X, Y> &a) {
	in >> a.first >> a.second;
	return in;
}
template<typename T>
void getv(T& i) {
	cin >> i;
}
template<typename T, typename ... Ns>
void getv(vector<T>& v, int n, Ns ... ns) {
	v.resize(n);
	for (auto& i : v)
		getv(i, ns...);
}
template<typename T>
void getv1(T& i) {
	cin >> i;
}
template<typename T, typename ... Ns>
void getv1(vector<T>& v, int n, Ns ... ns) {
	v.resize(n + 1);
	for (int i = 1; i <= n; i++)
		getv1(v[i], ns...);
}
#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
inline void getch(char &x) {
	while (x = getchar_unlocked(), x < 33) {
		;
	}
}
inline void getstr(string &str) {
	str.clear();
	char cur;
	while (cur = getchar_unlocked(), cur < 33) {
		;
	}
	while (cur > 32) {
		str += cur;
		cur = getchar_unlocked();
	}
}
template<typename T> inline bool sc(T &num) {
	bool neg = 0;
	int c;
	num = 0;
	while (c = getchar_unlocked(), c < 33) {
		if (c == EOF)
			return false;
	}
	if (c == '-') {
		neg = 1;
		c = getchar_unlocked();
	}
	for (; c > 47; c = getchar_unlocked())
		num = num * 10 + c - 48;
	if (neg)
		num *= -1;
	return true;
}
template<typename a, typename b>
void minq(a& x, b y) {
	if (x > y)
		x = y;
}
template<typename a, typename b>
void maxq(a& x, b y) {
	if (x < y)
		x = y;
}
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef int _I;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <string> vs;
typedef __V <ld> vd;
typedef __V <vd> vvd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
using AntonTsypko = void;
using arsijo = AntonTsypko;
using god = arsijo;
//store differences, not the elements for rsq in fenwick or array(for write-only)
//Sum Over Subsets + inclusion-exclusion is a thing! (Solved div1E (383E) using it!)
//SQRT-heuristic divide items into groups: >sqrt and <=sqrt and do something according to group(eg. trie for one, z-func for other) - 1202E
//f-e+v=2
uniform_real_distribution<double> double_dist(0, 1);
uniform_int_distribution<int> dist(31, 55);
//WHEN DOING MODULAR SUBTRACTION ALWAYS **ALWAYS** ADD MOD
//don't use AVX at AtCoder(=RE)
//Trie: MAXDEPTH!=MAXSIZE
//suspiciously big numbers? use python, seriosly you don't wanna waste your time if it overflows
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//SQRT IS PROBABLY THE ANSWER
int n, m, sm[1021][1021], b[1021][1021];
vvc mat;

int get(int x, int y, int x1, int y1) {
	return sm[x1][y1] - sm[x1][y] - sm[x][y1] + sm[x][y];
}

void add(int x, int y, int x1, int y1) {
	x1++, y1++;
	++b[x1][y1], --b[x1][y], --b[x][y1], ++b[x][y];
}

bool can(int i, int j, int rad) {
	int u = i - rad, d = i + rad, l = j - rad, r = j + rad;
	if (u < 1 || l < 1 || d > n || r > m)
		return false;
	--l, --u;
	return get(u, j - 1, d, j) == d - u && get(i - 1, l, i, r) == r - l;
}

int main() {
	doin();
	memset(b, 0, sizeof b);
	cin >> n >> m;
	getv1(mat, n, m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			sm[i][j] = sm[i - 1][j] + sm[i][j - 1] - sm[i - 1][j - 1]
					+ (mat[i][j] == '*');
	vector<pair<pi, int>> ans;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			int lo = 0, hi = min(n, m), mid;
			while (lo < hi) {
				mid = lo + (hi - lo + 1) / 2;
				if (can(i, j, mid)) {
					lo = mid;
				} else {
					hi = mid - 1;
				}
			}
			if(hi) {
			ans.pb( { { i, j }, hi });
			add(i, j-hi, i, j+hi);
			add(i-hi, j, i+hi, j);
			}
		}
	ll val = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			b[i][j]+=b[i][j-1]+b[i-1][j]-b[i-1][j-1];
			if((b[i][j]>0)^(mat[i][j]=='*'))
				return cout << -1, 0;
		}
	cout << ans.size() << "\n";
	for(auto i : ans) cout << i.first.first << " " << i.first.second << " " << i.second << "\n";

}