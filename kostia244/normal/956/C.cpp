#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,sse,fma,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 1e5 + 666, mlg = 18, mod =1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, t, m = 0, a[maxn], d[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		d[i]=a[i]+1;
		if(i) d[i] = max(d[i], d[i-1]);
	}
	for(int i = n-1; i--;)
		d[i] = max(d[i], d[i+1]-1);
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		ans += d[i]-a[i]-1;
	}
	cout << ans;
	return 0;
}