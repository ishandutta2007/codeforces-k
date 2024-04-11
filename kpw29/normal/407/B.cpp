#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000100
#define tys 5010
int n, m, k, a, b, c, w, h;
ll dp[maxn];
int p[maxn];

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) scanf("%d", &p[i]);
	dp[1] = 2;
	ll res = 2;
	
	for (int i=2; i<=n; ++i) 
	{
		dp[i] = 2;
		for (int j=p[i]; j < i; ++j) 
		{
			dp[i] += dp[j];
			dp[i] %= mod;
		}
	}
	for (int i=2; i<=n; ++i) res += dp[i], res %= mod;
	cout << res;
}