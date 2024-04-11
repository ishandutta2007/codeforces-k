#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first.first
#define yy first.second
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oit ostream_iterator
#define mod 1000000007ll
using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
#ifdef LOCAL
//	freopen("in", "r", stdin);
#endif
}
typedef long long ll;
typedef ll _I;
typedef double ld;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <ld> vd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, m,ans, la;
vpi a;

int main() {
	doin();
	cin >> n;
	a.resize(n);
	for(auto& i : a) cin >> i.first >> i.second;
	sort(all(a), [](const pi& a, const pi& b) {
		return ((1*a.first + (n-2)*a.second) + (2*b.first + (n-3)*b.second)) < ((1*b.first + (n-2)*b.second) + (2*a.first + (n-3)*a.second));
	});
	ans = 0;
	for(int i = 0; i < n; i++)
		ans += (i)*a[i].first + (n-i-1)*a[i].second;
	sort(all(a), [](const pi& a, const pi& b) {
		return a.second < b.second || (a.second == b.second && a.first > b.first);
	});
	la = 0;
	for(int i = 0; i < n; i++)
		la += (i)*a[i].first + (n-i-1)*a[i].second;
	cout << fixed << min(ans, la);
}