#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,popcnt,sse4.1,sse4.2,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1<<20, mod = 998244353, rt = 565042129, i2 = (mod+1)/2;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m;
int a[maxn][4], dp[110][1<<4];
void solve() {
	memset(dp, 0, sizeof dp);
	cin >> n >> m;
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < m; j++)
			cin >> a[j][i];
	for(int i = 0; i < m; i++) {
		for(int msk = 0; msk < 1 << n; msk++) {
			for(int s = 0; s < n; s++) {
				int m2 = msk;
				while(true) {
					int add = 0;
					for(int x = 0; x < n; x++)
						if((m2>>x)&1) add += a[i][(x+s)%n];
					dp[i+1][msk^m2] = max(dp[i+1][msk^m2], dp[i][msk]+add);
					if(!m2) break;
					m2 = msk&(m2-1);
				}
			}
		}
	}
	cout << dp[m][0] << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}