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
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 1000100;

int n, tab[maxn], res, last, spacecur, spacelast;

int main()
{
	boost;
	cin >> n;
	FOR(i, 1, n) cin >> tab[i];
	sort(tab+1, tab+n+1);
	FOR(i, 1, n)
	{
		if (tab[i] != tab[i-1])
		{
			spacecur += spacelast;
			spacelast = 0;
		}
		if (spacecur > 0) ++res, --spacecur;
		last = tab[i];
		++spacelast;
	}
	
	cout << res;
}