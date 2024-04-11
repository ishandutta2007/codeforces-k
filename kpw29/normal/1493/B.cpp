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

const int maxn = 1000100;
int n, u, r, d, l;

int let(char c) {
	return c - '0';
}
int H, M;

vector <int> mapa;

int becomes(int value) {
	int sec = (value % 10);
	value /= 10;
	
	if (mapa[value] == -1 || mapa[sec] == -1) return -1;
	return 10 * mapa[sec] + mapa[value];
}

bool mirror(int hour, int minute) {
	int bmin = becomes(minute), bhour = becomes(hour);
	
	if (bmin == -1 || bhour == -1) return false;
	if (bmin >= H) return false;
	if (bhour >= M) return false;
	
	return true;
}

void solveone() {
	cin >> H >> M;
	char h1, h2, m1, m2, _;
	cin >> h1 >> h2 >> _ >> m1 >> m2;
	int hour = 10 * let(h1) + let(h2);
	int minute = 10 * let(m1) + let(m2);
	
	while (!mirror(hour, minute)) {
		++minute;
		if (minute == M) {
			minute = 0;
			++hour;
			if (hour == H) {
				hour = 0;
			}
		}
	}
	
	h2 = hour % 10+ '0';
	hour /= 10;
	h1 = hour % 10+ '0';
	
	m2 = minute % 10 + '0';
	minute /= 10;
	m1 = minute % 10+ '0';
	
	debug("Output");
	cout << h1 << h2 << ":" << m1 << m2 << "\n";
}

int main() {
	mapa = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};
	boost;
	int tests;
	//tests = 1;
	cin >> tests;
	FOR(_, 1, tests) solveone();
}