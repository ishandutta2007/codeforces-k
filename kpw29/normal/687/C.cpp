#include <bits/stdc++.h>
/*#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>*/
using namespace std;
#define e1 first
#define e2 second
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <int, int> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll mod = 1e9+7;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;

inline bool MN(PLL jed, PLL dwa) {
	return (jed.y < dwa.y || (jed.y == dwa.y && jed.x < dwa.x));
}
inline bool WI(PLL jed, PLL dwa) {
	return (jed.y > dwa.y || (jed.y == dwa.y && jed.x > dwa.x));
}
inline ll det(PLL &a, PLL &b) {
	return (ll)a.x * b.y - (ll)a.y * b.x;
}
inline ll area2(PLL &a, PLL &b, PLL &c) {
	return det(a, b) + det(b, c) + det(c, a);
}
inline ll aarea2(PLL &a, PLL &b, PLL &c) {
	return abs(area2(a, b, c));
}
inline bool na_lewo(PLL &a, PLL &b, PLL &c) {
	return area2(a, b, c) > 0;
}
inline bool na_prawo(PLL &a, PLL &b, PLL &c) {
	return area2(a, b, c) < 0;
}
inline bool linia(PLL &a, PLL &b, PLL &c) {
	return area2(a, b, c) == 0;
}
inline ll dist2(PLL &a, PLL &b) {
	return (ll)(a.x - b.x) * (ll)(a.x - b.x) + (ll)(a.y - b.y) * (ll)(a.y - b.y);
}
inline bool cmp(PLL &start, PLL &a, PLL &b) {
	if (WI(a, start) && MN(b, start)) return 1;
	if (WI(b, start) && MN(a, start)) return 0;
	ll D = area2(start, a, b);
	if (D == 0) return dist2(start, a) < dist2(start, b);
	return D > 0;
}

inline bool Inside(PLL &a, PLL &b, PLL &c) {
	return max(max(dist2(a, b), dist2(b, c)), dist2(a, c)) == dist2(a, b);
}

inline bool InTriangle(PLL &a, PLL &b, PLL &c, PLL &d) {
	if (area2(a, b, c) == 0) return Inside(a, b, d) || Inside(a, c, d) || Inside(b, c, d);
    return (aarea2(a, b, c) == aarea2(a, b, d) + aarea2(a, c, d) + aarea2(b, c, d));
}

int n, m, k, DL = 0, T, t0, a, b, f1, f2;
#define maxn 1010
bool ok[maxn][maxn];

bool sub[maxn];

int t[maxn];
int main() {
	boost;
	cin >> n >> k;
	FOR(i, 1, n) cin >> t[i];
	ok[0][0] = 1;
	FOR(i, 1, n) {
	  for (int a=k; a>=0; --a)
	    for (int b=k; b>=0; --b) {
			if (a >= t[i]) ok[a][b] |= ok[a - t[i]][b];
			if (b >= t[i]) ok[a][b] |= ok[a][b - t[i]];
		}

	}
	
	vector <int> v;
	v.clear();
	FOR(i, 0, k)
	  if (ok[i][k-i]) v.pb(i);
	  
	cout << v.size() << endl;
	for (auto u : v) cout << u << ' ';
}