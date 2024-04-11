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
typedef pair <PLL, PLL > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 998244353;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 4LL * 1000000LL * 1000000LL * 1000000LL;

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
#ifdef DEBUG
  struct Nl{~Nl(){cerr << '\n';}};
# define debug(x...) cerr << (strcmp(#x, "") ? #x ":  " : ""), dump(x), Nl(), cerr << ""
#else
# define debug(...) 0 && cerr
#endif
mt19937_64 rng(0);
int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
inline void addmod(int &x, int val) {
	x += val;
	while (x >= mod) x -= mod;
}

const int maxn = 100100;
ll L, S;
int n;
ll w[maxn], dist[maxn];
vector <int> v[maxn];
int STOS[maxn], DL, nast[maxn];
int taken[maxn];

inline ll check(int pocz, int kon) {
	return dist[STOS[kon]] - dist[STOS[pocz]] + w[STOS[pocz]];
}

void dfs(int x) {
	STOS[++DL] = x;
	dist[x] += w[x];
	
	for (auto u : v[x]) {
		dist[u] = dist[x];
		dfs(u);
	}
	
	int xx = max(1LL, DL - L + 1), yy = DL;
	while (xx < yy) {
		int sr = (xx + yy) >> 1;
		if (check(sr, DL) > S) xx = ++sr;
		else yy = sr;
	}
	
	nast[x] = STOS[xx];
	
	--DL;
}

ll res;
void greedy(int x) {
	int best_option = INT_MAX;
	for (auto u : v[x]) {
		greedy(u);
		best_option = min(best_option, taken[u]);
	}
	
	if (best_option > x) {
		++res;
		taken[x] = nast[x];
	}
	else taken[x] = best_option;
}

int main() {
	boost;
	cin >> n >> L >> S;
	FOR(i, 1, n) {
		cin >> w[i];
		if (w[i] > S) OUT(-1);
	}
	
	if (n == 1) OUT(n);
	
	FOR(i, 2, n) {
		int p;
		cin >> p;
		v[p].push_back(i);
	}
	
	dfs(1);
	greedy(1);
	cout << res;
}