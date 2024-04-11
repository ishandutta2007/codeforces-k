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
const int inf = 2e9+9;
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
	
}
const int RANGE = 1e9;

bool ask(int x, int y) {
	cout << x << ' ' <<y << endl;
	
	string ans;
	cin >> ans;
	return ans == "white";
}

int main() {
	int n;
	cin >> n;
	
	bool begin = ask(0, 0);
	int y1 = 0, y2 = inf;
	
	for (int iter = n - 2; iter >= 0; --iter) {
		int pot = (1 << iter);
		if (y2 == inf) {
			bool col = ask(y1 + pot, y1 + pot);
			if (col != begin) {
				y2 = y1 + pot;
			}
			else y1 += pot;
		}
		else {
			int mid = (y1 + y2) / 2;
			assert(y1 < mid);
			assert(mid < y2);
			bool col = ask(mid, mid);
			if (col == begin) y1 = mid;
			else y2 = mid;
		}
	}
	
	if (y2 == inf) {
		cout << 0 << ' ' << RANGE << ' ' << RANGE << ' ' << RANGE << endl;
	}
	else {
		assert(y1 < y2);
		cout << 0 << ' ' << y1 + 1 << ' ' << RANGE << ' ' << y2 - 1 << endl;
	}
	
	
	
}