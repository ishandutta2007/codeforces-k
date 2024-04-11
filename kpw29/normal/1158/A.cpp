#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define REYNA(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, pair <int, ll> > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 200100;

ll pref[maxn];
int a[maxn], b[maxn];
int n, m;

int main()
{
	boost;
	cin >> n >> m;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, m) cin >> b[i];
	sort(a+1, a+n+1);
	sort(b+1, b+m+1);
	
	if (a[n] > b[1]) OUT(-1);
	ll sum = 0, s1 = 0, s2 = 0;
	FOR(i, 1, n) sum += (ll)a[i] * m;
	for (int i=m; i>1; --i) {
		sum += (b[i] - a[n]);
	}
	
	if (a[n] != b[1]) sum += (b[1] - a[n-1]);
	cout << sum;
}