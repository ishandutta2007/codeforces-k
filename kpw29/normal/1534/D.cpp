#include <bits/stdc++.h>
using namespace std;

#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PII, PII> PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
#ifdef DEBUG
template<class T> int size(T &&x) {
	return int(x.size());
}
template<class A, class B> ostream& operator<<(ostream &out, const pair<A, B> &p) {
	return out << '(' << p.first << ", " << p.second << ')';
}
template<class T> auto operator<<(ostream &out, T &&x) -> decltype(x.begin(), out) {
	out << '{';
	for(auto it = x.begin(); it != x.end(); ++it)
		out << *it << (it == prev(x.end()) ? "" : ", ");
	return out << '}';
}
void dump() {}
template<class T, class... Args> void dump(T &&x, Args... args) {
	cerr << x << ";  ";
	dump(args...);
}
#endif
#ifdef DEBUG
  struct Nl{~Nl(){cerr << '\n';}};
# define debug(x...) cerr << (strcmp(#x, "") ? #x ":  " : ""), dump(x), Nl(), cerr << ""
#else
# define debug(...) 0 && cerr
#endif
mt19937_64 rng(time(0));
int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

/*#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;

mint fac[maxn], ifac[maxn];

inline mint dwumian(int n, int k) {
	if (n < 0 || n < k) return 0;
	return fac[n] * ifac[k] * ifac[n-k];
}

void precalc(int N) {
	fac[0] = ifac[0] = 1;
	FOR(i, 1, N) fac[i] = fac[i-1] * i;
	ifac[N] = fac[N].inv();
	for (int i=N-1; i>0; --i) {
		ifac[i] = ifac[i + 1] * (i + 1);
	}
}*/

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
const LL INF = 1e18;
const int maxn = 210;
const int mod = 1e9+7;
int n;
vi ask(int node) {
	cout << "? " << node << endl;
	vector <int> ret(n + 1);
	FOR(i, 1, n) cin >> ret[i];
	return ret;
}

map <PII, bool> edges;
void put(int a, int b) {
	if (a > b) swap(a, b);
	edges[{a, b}] = 1;
}

void solve() {
	cin >> n;
	int root = 1;
	edges.clear();
	
	vi rootans = ask(root);
	int odd = 0, even = 0;
	FOR(i, 1, n) {
		if (rootans[i] == 0) continue;
		if (rootans[i] % 2 == 0) ++even;
		else ++odd;
		
		if (rootans[i] == 1) {
			put(root, i);
		}
	}
	
	int key = 0;
	if (odd < even) key = 1;
	FOR(i, 1, n) {
		if (rootans[i] == 0) continue;
		if (rootans[i] % 2 == key) {
			vi tmp = ask(i);
			FOR(j, 1, n) {
				if (tmp[j] == 1) put(i, j);
			}
		}
	}
	
	
	
	assert((int)edges.size() + 1 == n);
	cout << "!\n";
	trav(u, edges) cout << u.e1.e1 << ' ' << u.e1.e2 << endl;
}

int main() {
	solve();
}