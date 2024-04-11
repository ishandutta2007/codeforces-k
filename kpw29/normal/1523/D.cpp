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
mt19937_64 rng(0);
int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
const LL INF = 1e18;
const int maxn = 1000100;

void solve() {
	int n, m, p;
	cin >> n >> m >> p;
	vector <string> s(n);
	FOR(i, 0, n-1) {
		cin >> s[i];
	}
	
	string best(m, '0');
	int best_score = 0;
	while (clock() <= 2.69 * CLOCKS_PER_SEC) {
		int r = random(0, n-1);
		vector <int> cols = {};
		for (int i=0; i<m; ++i) {
			if (s[r][i] == '1') cols.pb(i);
		}
		
		int sz = cols.size();
		vector <int> cnt(1 << sz, 0);
		
		for (int i=0; i<n; ++i) {
			int liczba = 0;
			for (int j=0; j<sz; ++j) {
				if (s[i][cols[j]] == '1') liczba += (1 << j);
			}
			
			cnt[liczba]++;
		}
		
		for (int bit = 0; bit < sz; ++bit) {
			for (int i=0; i<(1<<sz); ++i) {
				if (!(i & (1 << bit))) cnt[i] += cnt[i + (1 << bit)];
			}
		}
		
		for (int i=0; i<(1<<sz); ++i) {
			if (cnt[i] >= (n + 1) / 2) {
				if (__builtin_popcount(i) > best_score) {
					best_score = __builtin_popcount(i);
					string opt(m, '0');
					for (int j=0; j<sz; ++j) {
						if (i & (1 << j)) opt[cols[j]] = '1';
					}
					
					best = opt;
				}
			}
		}	
	}
	
	cout << best << "\n";
}

int main() {
	srand(time(0));
	boost;
	int tests;
	tests = 1;
	//cin >> tests;
	while (tests--) {
		solve();
	}
}