#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define pb push_back
#define __V vector
#define all(x) x.begin(), x.end()
#define oit ostream_iterator
#define mod 1000000007ll
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
typedef float ld;
typedef int _I;
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
int main() {
	doin();
	int n, k;
	string s;
	cin >> n >> k >> s;
	vi o[2];
	int pr[2] = { 0 }, sf[2] = { 0 };
	for (int i = 0; i < n; i++) {
		o[s[i] - '0'].pb(i);
		if (i >= k)
			sf[s[i] - '0']++;
	}
	if (o[0].empty() || o[1].empty() || o[0].back() - o[0][0] < k
			|| o[1].back() - o[1][0] < k)
		return cout << "tokitsukaze", 0;
	bool w = n <= 2*k;
	pr[s[0] - '0']++;
	if (k < n)
		sf[s[k] - '0']--;
	for (int i = 1; w && i + k < n; i++) {
		w &= !((pr[0]>0)&&(pr[1]>0));
		w &= !((sf[0]>0)&&(sf[1]>0));
		w &= i==0||i+k==n||(pr[0]!=sf[0]&&pr[1]!=sf[1]);
		pr[s[i] - '0']++;
		if (i + k < n)
			sf[s[i + k] - '0']--;
	}
	if (w)
		return cout << "quailty", 0;
	cout << "once again";
	return 0;
}