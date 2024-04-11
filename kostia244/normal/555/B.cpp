#pragma GCC target ("avx2")
#pragma GCC target ("sse2")
#pragma GCC optimize ("Ofast")
#pragma GCC push_options
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.begin(), x.end()
#define oit ostream_iterator
#define mod 998244353ll
using namespace std;
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
		getv(v[i], ns...);
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
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef ll _I;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <ld> vd;
typedef __V <vd> vvd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
using AntonTsypko = void;
using arsijo = AntonTsypko;
using god = arsijo;
uniform_real_distribution<double> double_dist(0, 1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
struct seg {
	ll l, r, i;
	void get(ll a, ll t1, ll t2, ll b, int idx) {
		l = a, r = b;
		i = idx;
		r = (r - l);
		l = (t2 - t1);
	}
	bool operator<(const seg &o) const {
		return r < o.r || (r == o.r && l < o.l);
	}
};
int n, m;
vi ans;
vector<pi> pts;
vector<seg> segs;
int main() {
	doin();
	cin >> n >> m;
	segs.resize(n-1);
	pts.resize(m);
	ans.resize(n-1);
	int idx = 0;
	ll a, b, c, d;
	cin >> a >> b;
	for (auto& i : segs) {
		c = a, d = b;
		cin >> a >> b;
		i.get(c, d, a, b, idx++);
	}
	idx = 0;
	for (auto& i : pts)
		cin >> i.first, i.second = idx++;
	set<pi> pt(all(pts));
	sort(all(segs));
	for (auto i : segs) {
		auto it = pt.lower_bound({i.l, 0});
		if(it == pt.end() || it->first > i.r) {
			cout << "No";
			return 0;
		}
		ans[i.i] = it->second+1;
		pt.erase(it);
	}
	cout << "Yes\n";
	for(int i = 0; i < n-1; i ++) cout << ans[i] << " ";
}