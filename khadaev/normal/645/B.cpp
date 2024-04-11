#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
	for (auto i : a) cerr << i << ' ';\
	cerr << '\n'

#ifndef M_PI
const ld M_PI = 3.1415926535897932384626433;
#endif
const ld eps = 1e-8;

ll c2(ll n) {
	return n * (n - 1) / 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	if (k <= n / 2) {
		cout << c2(n) - c2(n - 2 * k) << '\n';
	} else cout << c2(n) << '\n';
	return 0;
}