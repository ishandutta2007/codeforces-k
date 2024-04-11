//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e6 + 100;
const ll mod = 998244353;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()
#define lc (id << 1)
#define rc (lc | 1)

ll pw(ll a, ll b, ll mod = mod){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

ll rev[maxn];
 
void NTT(vector<ll>& A,  ll _lg, bool inv = 0){
	for(ll i = 1; i < (1 << _lg); i++){
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (_lg - 1));
	}
	ll n = (1 << _lg);
	for(ll i = 0; i < (1 << _lg); i++){
		if(rev[i] < i) swap(A[i], A[rev[i]]);
	}
	for(ll ln = 1; ln < n; ln <<= 1){
		ll w = pw(3, mod / 2 / ln);
		if(inv) w = pw(w, mod - 2);
		for(ll i = 0; i < n; i += ln + ln){
			ll wn = 1;
			for(ll j = i; j < i + ln; j++){
				ll x = A[j], y = A[j + ln] * wn % mod;
				A[j] = (x + y) % mod;
				A[j + ln] = (x - y + mod) % mod;
				wn = wn * w % mod;
			}
		}
	}
	if(inv){
		ll invn = pw(1 << _lg, mod - 2);
		for(ll i = 0; i < n; i++){
			A[i] = A[i] * invn % mod;
		}
	}
}

ll arr[maxn];

vector<ll> vec[maxn];
 
void solve(ll id, ll s, ll e, ll h){
	vec[id].resize(1 << (h + 1));
	if(e - s == 1){
		vec[id][0] = 1;
		vec[id][1] = arr[s];
		return;
	}
	ll mid = (s + e) >> 1;
	solve(lc, s, mid, h - 1);
	solve(rc, mid, e, h - 1);
	NTT(vec[lc], h, 0);
	NTT(vec[rc], h, 0);
	for(ll i = 0; i < (1 << h); i++){
		vec[id][i] = vec[lc][i] * vec[rc][i] % mod;
	}
	NTT(vec[id], h, 1);
	return;
}

int n, A, B;
ll ans;

int main(){
	fast_io;
	
	cin >> n >> A >> B;
	if(A == 0 || B == 0 || A + B > n + 1){
		cout << 0;
		return 0;
	}
	n--;
	A--;
	B--;
	ans = 1;
	for(int i = B + 1; i <= A + B; i++){
		ans = ans * i % mod;
	}
	for(int i = 1; i <= A; i++){
		ans = ans * pw(i, mod - 2) % mod;
	}
	for(int i = 1; i < n; i++){
		arr[i - 1] = i;
	}
	ll m = n;
	while(__builtin_popcount(n) != 1) n++;
	solve(1, 0, n, __builtin_popcount(n - 1) + 1);
	cout << ans * vec[1][m - A - B] % mod << "\n";
	
	return 0;
}