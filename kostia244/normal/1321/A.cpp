#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
#include<bits/extc++.h>
using namespace __gnu_pbds;
using oset = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 404, mod = (119<<23)+1, lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vi a, b;
	int n;
	cin >> n;
	a = vi(n), b= vi(n);
	for(auto &i : a) cin >> i;
	for(auto &i : b) cin >> i;
	int xa = 0, xb = 0;
	for(int i = 0; i < n; i++) {
		if(a[i]^b[i]) (a[i]?xa:xb)++;
	}
	if(xa==0) return cout <<-1, 0;
	int ans = (xb+xa)/xa;
	cout << ans << '\n';
	return 0;
}