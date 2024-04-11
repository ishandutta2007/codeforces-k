#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define e1 first
#define e2 second
#define pb push_back
#define OUT(x) {cout << x << "\n"; exit(0); }
#define TCOUT(x) {cout << x << "\n"; return; }
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define rep(i, l, r) for(int i = (l); i < (r); ++i)
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define sz(x) int(x.size())
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
/*#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
vector <mint> fac, inv;
mint binom(int n, int k) {
	if (n < k || n < 0) return 0;
	return fac[n] * inv[k] * inv[n-k];
}

void prep(int N) {
	fac.resize(N+1, 1); inv.resize(N+1, 1);
	for (int i=1; i<=N; ++i) fac[i] = fac[i-1] * i;
	inv[N] = fac[N].inv();
	for (int i=N-1; i>0; --i) inv[i] = inv[i+1] * (i + 1);
}*/

mt19937_64 rng(time(0));
int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}
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
const int maxn = 100100;

//Did you REAALLY consider sample tests?
bool TEST = 0;
void solve(int tc) {
	int n;
	if (!TEST) cin >> n;
	else n = random(2, 10);
	vector <pii> v(n);
	if (!TEST){
		rep(i, 0, n) cin >> v[i].e1 >> v[i].e2;
	}
	else {
		rep(i, 0, n) v[i].e1 = random(0, n-1), v[i].e2 = random(0, n-1);
	}
	
	auto brut = [&]() -> int {
		int top = (1 << n);
		int wynik = 0;
		rep(mask, 0, top) {
			bool ok = 1;
			vector <bool> taken(n, 0);
			rep(i, 0, n) {
				if (mask & (1 << i)) taken[i] = 1;
			}
			
			int smaller = 0;
			rep(i, 0, n) {
				if (taken[i]) {
					if(smaller > v[i].e2) ok = 0;
					smaller++;
				}
			}
			
			int larger = 0;
			for (int i=n-1; i>=0; --i) {
				if (taken[i]) {
					if (larger > v[i].e1) ok = 0;
					larger++;
				}
			}
			
			if (ok) wynik = max(wynik, __builtin_popcount(mask));
		
		}
		
		return wynik;	
				
	};
	
	auto check = [&](int len) {
		int taken = 0;
		rep(i, 0, n) {
			if (taken <= v[i].e2 && taken + v[i].e1 + 1 >= len){
				++taken;
			}
		}
		return taken >= len;
	};
	
	int x = 0, y = n;
	while (x < y) {
		int sr = (x + y) / 2 + 1;
		if (!check(sr)) {
			y=--sr;
		}else x = sr;
	}
	
	if (TEST) {
		int ok = brut();
		if (x != ok) {
			debug(v);
			debug(x, ok);
			
		}
		assert(x == ok);
	}
	cout << x << "\n";
		
}

int main() {
	boost;
	int tests;
	cin >> tests;
	//tests = 1;
	FOR(test, 1, tests) {
		solve(test);
	}
}