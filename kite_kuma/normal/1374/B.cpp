#include <bits/stdc++.h>
using namespace std;

#pragma region macros_and_aliases

#define rep(i, n) for(long long i = 0; i < (n); i++)
#define rrep(i, n) for(long long i = (n)-1; i > -1; i--)
#define Rep(i, m, n) for(long long i = (m); i < (n); i++)
#define rRep(i, m, n) for(long long i = (n)-1; i >= (m); i--)
#define REP(i, m, n, p) for(long long i = m; i < n; i += p)
#define foa(s, v) for(auto &s : v)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define bcnt(n) __builtin_popcountll(n)
#define endk endl
#define ednl endl
#define enld endl

using ll = long long;
using ld = long double;
using vb = vector<bool>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using mll = map<long long, long long>;
using pll = pair<long long, long long>;
using qll = queue<long long>;
using sll = set<long long>;
using vpll = vector<pair<long long, long long>>;
template <class T = ll>
using V = vector<T>;
template <class T = ll>
using VV = V<V<T>>;
template <class T = ll>
using VVV = V<V<V<T>>>;
//pq()
template <class T = ll>
using pqup = priority_queue<T, vector<T>, greater<T>>;
//pq()
template <class T = ll>
using pqdn = priority_queue<T>;

#pragma region debug
#define debug(var)                  \
	do {                            \
		std::cout << #var << " : "; \
		view(var);                  \
	} while(0)

template <typename T>
void view(T e) {
	std::cout << e << "\n";
}
template <typename T>
void view(const std::vector<T> &v) {
	for(const auto &e : v) {
		std::cout << e << " ";
	}
	std::cout << "\n";
}
template <typename T>
void view(const std::set<T> &s) {
	for(auto &t : s) {
		std::cout << t << " ";
	}
	std::cout << "\n";
}
template <typename T>
void view(const std::vector<std::vector<T>> &vv) {
	std::cout << "\n";
	for(const auto &v : vv) {
		view(v);
	}
}
template <typename T, typename U>
void view(const std::vector<std::pair<T, U>> &v) {
	std::cout << "\n";
	for(const auto &c : v) {
		std::cout << c.first << " " << c.second << "\n";
	}
}
template <typename T, typename U>
void view(const std::map<T, U> &m) {
	std::cout << "\n";
	for(auto &t : m) {
		std::cout << t.first << " " << t.second << "\n";
	}
}

#pragma endregion

#pragma region input
#define VEC(type, name, size) \
	vector<type> name(size);  \
	IN(name)
#define VVEC(type, name, h, w)                     \
	vector<vector<type>> name(h, vector<type>(w)); \
	IN(name)
#define INT(...)     \
	int __VA_ARGS__; \
	IN(__VA_ARGS__)
#define LL(...)            \
	long long __VA_ARGS__; \
	IN(__VA_ARGS__)
#define STR(...)        \
	string __VA_ARGS__; \
	IN(__VA_ARGS__)
#define CHAR(...)     \
	char __VA_ARGS__; \
	IN(__VA_ARGS__)
#define DOUBLE(...)     \
	double __VA_ARGS__; \
	IN(__VA_ARGS__)
#define LD(...)              \
	long double __VA_ARGS__; \
	IN(__VA_ARGS__)

template <class T>
void scan(T &a) {
	cin >> a;
}
template <class T>
void scan(vector<T> &a) {
	for(auto &i : a) scan(i);
}
template <class T, class L>
void scan(pair<T, L> &p) {
	scan(p.first);
	scan(p.second);
}
void IN() {}
template <class Head, class... Tail>
void IN(Head &head, Tail &... tail) {
	scan(head);
	IN(tail...);
}
template <class T>
inline void print(T x) {
	cout << x << '\n';
}

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
	os << p.first << " " << p.second;
	return os;
}
template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
	is >> p.first >> p.second;
	return is;
}
#pragma endregion

#pragma endregion

#pragma region constants

long long const limLL = 9223372036854775807;  // POW(2,63)-1 ~ 9.22e18
long long const dekai = 3e16;
const long double pi = acos(-1);
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ddx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int ddy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

const int mod = 1000000007;
// const int mod = 998244353;
#pragma endregion

#pragma region basic_procedure

template <class T>
inline bool isin(T x, T lef, T rig) {
	return ((lef <= x) && (x < rig));
}

template <class T>
inline bool chmin(T &a, T b) {
	if(a > b) {
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool chmax(T &a, T b) {
	if(a < b) {
		a = b;
		return true;
	}
	return false;
}

void Yes(bool f = 1) { cout << (f ? "Yes" : "No") << "\n"; }
void No() { cout << "No\n"; }
void YES(bool f = 1) { cout << (f ? "YES" : "NO") << "\n"; }
void NO() { cout << "NO\n"; }
void err() {
	cout << -1 << "\n";
	exit(0);
}

vector<long long> vin(long long n) {  //n
	vector<long long> v(n);
	for(long long i = 0; i < n; i++) {
		cin >> v[i];
	}
	return v;
}

//()
// vector 
template <class T>
void vout(vector<T> &v, bool tate = 0) {
	if(v.size() > 0) {
		for(auto it = v.begin(); it < v.end(); it++) {
			cout << *it;
			if(it != v.end() - 1) {
				if(tate)
					cout << endl;
				else
					cout << " ";
			}
		}
	}
	cout << endl;
}

template <class T>
void add(vector<T> &v, T val) {	 //
	for(auto &a : v) a += val;
	return;
}

// vector map<,>
template <class T>
map<T, long long> cntv(vector<T> v) {
	map<T, long long> m;
	for(auto &g : v) {
		if(m.count(g))
			m[g]++;
		else
			m[g] = 1;
	}
	return m;
}

//()
//{1,36,1,3,8,-2,-92}
//{2, 5,2,3,4, 1,  0}
template <class T>
vector<long long> press(vector<T> &v) {
	long long n = v.size();
	vector<long long> w(n);
	map<T, long long> m;
	for(T &p : v) m[p] = 0;
	long long i = 0;
	for(auto &p : m) {
		p.second = i;
		i++;
	}
	for(long long i = 0; i < n; i++) w.at(i) = m[v.at(i)];
	return w;
}

template <class T>
T divup(T a, T b) {
	//
	assert(b != 0);
	T x = abs(a);
	T y = abs(b);
	T z = (x + y - 1) / y;
	if((a < 0 && b > 0) || (a > 0 && b < 0))
		return -z;
	else if(a == 0)
		return 0;
	else
		return z;
}

long long POW(long long a, long long n) {
	long long res = 1;
	while(n > 0) {
		if(n & 1) res = res * a;
		a = a * a;
		n >>= 1;
	}
	return res;
}

template <class T>
int sgn(T x) {	//
	if(x < 0) return -1;
	if(x == 0) return 0;
	return 1;
}

long long modpow(long long a, long long n, long long mod) {	 // a^n mod
	if(mod == 1) return 0LL;
	long long res = 1;
	while(n > 0) {
		if(n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

// a * x % mod == __gcd(a,mod)x
// a  mod
long long modinv(long long a, long long mod) {
	long long b = mod, u = 1, v = 0;
	while(b) {
		long long t = a / b;
		a -= t * b;
		swap(a, b);
		u -= t * v;
		swap(u, v);
	}
	u %= mod;
	if(u < 0) u += mod;
	return u;
}

vvll comb(100, vll(100, -1));
long long com(long long n, long long k) {  //(overflow)
	assert(n < 100 && k < 100);
	if(n < k || k < 0 || n < 0) return 0;
	if(comb[n][k] != -1) return comb[n][k];
	ll res;
	if(n - k < k)
		res = com(n, n - k);
	else if(k == 0)
		res = 1;
	else
		res = com(n - 1, k - 1) + com(n - 1, k);
	comb[n][k] = res;
	return res;
}

// nCk mod
const ll MAX = 5100000;
// 
// MAX=3*10^71900ms
// MAX=5*10^6(300ms)
long long fac[MAX], finv[MAX], inv[MAX];

void cominit() {
	// 
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for(ll i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = mod - inv[mod % i] * (mod / i) % mod;
		finv[i] = finv[i - 1] * inv[i] % mod;
	}
}
long long commod(ll n, ll k) {	// 
	if(n < k) return 0;
	if(n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}
long long pmod(ll n, ll k) {  //
	if(n < k) return 0;
	if(n < 0 || k < 0) return 0;
	return fac[n] * finv[n - k] % mod;
}
long long hmod(ll n, ll k) {  // nHk
	// nok
	//(n+k-1)C(k-1)
	return commod(n + k - 1, n);
}
#pragma endregion

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// cout << fixed << setprecision(15);
	int t;
	cin >> t;
	vector<long long> ans(t);
	for(int i = 0; i < t; i++) {
		long long res = 0;
		LL(n);
		ll cnt = 0;
		while(n % 3 == 0) {
			n /= 3, cnt++;
		}
		ll c = 0;
		while(n % 2 == 0) {
			n /= 2, c++;
		}

		if(n > 1)
			res = -1;
		else {
			if(c > cnt)
				res = -1;
			else {
				res = cnt - c + cnt;
			}
		}

		ans[i] = res;
	}
	for(int i = 0; i < t; i++) {
		cout << ans[i] << endl;
	}
}