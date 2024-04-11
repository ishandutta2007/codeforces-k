// Problem: G. Move by Prime
// Contest: Codeforces - IndiaHacks 2016 - Online Edition (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/653/problem/G
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
const int mod = 1e9 + 7;
namespace math {
const int A = 1<<20;

#define INLINE inline __attribute__ (( always_inline ))
struct mint {
	uint32_t v;
	template<class T = int>
	mint(T x = 0) {
		x %= mod;
		if(x < 0) x += mod;
		v = x;
	}
	mint operator-() const {
		return mint(v ? mod-v : 0);
	}
	mint &operator*=(const mint &r) {
		v = v*1ll*r.v%mod;
		return *this;
	}
	mint &operator+=(const mint &r) {
		v = v+r.v>=mod ? (v+r.v-mod) : (v+r.v);
		return *this;
	}
	mint &operator-=(const mint &r) { 
		return *this += -r;
	}
	mint &operator/=(const mint &r) {
		return *this *= r.inv();
	}
	friend mint operator+(mint a, const mint &b) {
		return a += b;
	}
	friend mint operator-(mint a, const mint &b) {
		return a -= b;
	}
	friend mint operator*(mint a, const mint &b) {
		return a *= b;
	}
	friend mint operator/(mint a, const mint &b) {
		return a /= b;
	}
	
	template<class T = int>
	mint pow(T p) const {
		mint res = 1, cur = *this;
		while(p) {
			if(p&1) res = res*cur;
			cur = cur*cur, p>>=1;
		}
		return res;
	}
	mint inv() const {
		return mint(*this).pow(mod-2);
	}
	
	friend bool operator==(const mint &a, const mint &b) {
		return a.v == b.v;
	}
	friend bool operator!=(const mint &a, const mint &b) {
		return !(a == b);
	}
	
	friend istream& operator>>(istream &is, mint &m) {
		is >> m.v;
		m = mint(m.v);
		return is;
	}
	friend ostream& operator<<(ostream &os, const mint &m) {
		os << m.v; 
		return os;
	}
};

mint fact[A], inum[A], ifact[A];
void calc_inum() {
	inum[1] = 1;
	for(int i = 2; i < A; i++) inum[i] = -inum[mod%i]*(mod/i);
}
void calc_combi() {
	if(0 == inum[1]) calc_inum();
	fact[0] = ifact[0] = 1;
	for(int i = 1; i < A; i++) fact[i] = fact[i-1]*i;
	for(int i = 1; i < A; i++) ifact[i] = ifact[i-1]*inum[i];
}

mint nck(int n, int k) {
	if(0 == fact[0]) calc_combi();
	if(k > n || k < 0) return 0;
	return fact[n]*ifact[k]*ifact[n-k];
}
}
using namespace math;
const int N = 300300;
int lp[N], cnt[N][20];
vector<int> pr;
void sieve() {
	for(int i = 2; i < N; i++) {
		if(lp[i] == 0)
			pr.push_back(lp[i] = i);
		for(int j = 0; j < pr.size() && pr[j] <= lp[i] && pr[j]*i < N; j++)
			lp[pr[j]*i] = pr[j];
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	sieve();
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &i : a) cin >> i;
	for(auto i : a) {
		while(i>1) {
			int t = lp[i], c = 0;
			while(i%t == 0) i/=t, c++;
			cnt[t][c]++;
		}
	}
	vector<mint> pws(n+2);
	for(int i = 0; i < pws.size(); i++)
		pws[i] = mint(2).pow(i);
	//min(x, y)
	auto solve = [&](int x, int y) {
		mint ans = 0;
		mint A = pws[x]-1, B = pws[y]-1;
		for(int c = 1; c <= min(x, y); c++) {
			A -= nck(x, c);
			B -= nck(y, c);
			ans += c*(nck(x, c)*B+A*nck(y, c)+nck(x, c)*nck(y, c));
		}
		return ans;
	};
	mint ans = 0;
	for(auto i : pr) {
		int c1 = 0;
		//20*primes total
		for(int z = 20; z-->1;) {
			c1 += cnt[i][z];
			ans += solve(n-c1, c1);//20*nlog(n) total
		}
	}
	cout << ans << '\n';
}