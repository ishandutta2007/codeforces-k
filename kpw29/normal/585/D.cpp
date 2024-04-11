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
const int maxn = 1000100;

//Did you REAALLY consider sample tests?
vector <char> names = {'L', 'M', 'W'};
const ll INF = 1e18+3;

ll tab[30][30];
vector <int> rozloz(int mask, int len) {
	vi wynik;
	rep(i, 0, len) {
		wynik.push_back(mask % 3);
		mask /= 3;
	}
	return wynik;
}

void solve(int tc) {
	int n;
	ll best_score = -INF;
	cin >> n;
	rep(i, 0, n) rep(j, 0, 3) cin >> tab[i][j];
	if (n == 1) {
		auto tryzero = [&](int a, int b) {
			if (tab[0][a] == 0 && tab[0][b] == 0) {
				cout << names[a] << names[b];
				exit(0);
			}
		};
		tryzero(0, 1);
		tryzero(0, 2);
		tryzero(1, 2);
	}
	
	int half = (n / 2);
	int pot = 1;
	rep(i, 0, half) pot *= 3;
	map <pair <ll, ll>, pair<ll, ll> > M;
	
	rep(mask, 0, pot) {
		vector <ll> sum(3, 0);
		vi bits = rozloz(mask, half);
		rep(i, 0, half) {
			rep(j, 0, 3) {
				if (bits[i] != j) sum[j] += tab[i][j];
			}
		}
		pll gdzie = {sum[0] - sum[1], sum[0] - sum[2]};
		if (M.find(gdzie) == M.end()) M[gdzie] = {sum[0], mask};
		else M[gdzie] = max(M[gdzie], {sum[0], mask});
		
		debug("First");
		debug(bits);
		debug(sum);
	}
	
	int ile = n - half;
	pot = 1;
	rep(i, 0, ile) pot *= 3;
	pii best_masks;
	
	rep(mask, 0, pot) {
		vector <ll> sum(3, 0);
		vi bits = rozloz(mask, ile);
		rep(i, 0, ile) {
			rep(j, 0, 3) {
				if (bits[i] != j) sum[j] += tab[i+half][j];
			}
		}
		
		pll pytaj = {sum[1] - sum[0], sum[2] - sum[0]};
		if (M.find(pytaj) != M.end()) {
			ll option = sum[0] + M[pytaj].e1;
			if (option > best_score) {
				best_score = option;
				best_masks = {M[pytaj].e2, mask};
			}
		}
		
		debug("Second");
		debug(bits);
		debug(sum);
	}
	
	if (best_score == -INF) TCOUT("Impossible");
	debug(best_score);
	debug(best_masks);
	vi bits = rozloz(best_masks.e1, half);
	vll sum(3, 0);
	
	rep(i, 0, half) {
		rep(j, 0, 3) {
			if (bits[i] != j) sum[j] += tab[i][j], cout << names[j];
		}
		cout << "\n";
	}
	bits = rozloz(best_masks.e2, ile);
	rep(i, 0, ile) {
		rep(j, 0, 3) {
			if (bits[i] != j) sum[j] += tab[i+half][j], cout << names[j];
		}
		cout << "\n";
	}
	
	debug(sum);
	
}

int main() {
	int tests;
	//cin >> tests;
	tests = 1;
	FOR(test, 1, tests) {
		solve(test);
	}
}