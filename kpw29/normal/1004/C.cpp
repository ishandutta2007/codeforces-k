#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); }
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
typedef pair <PLL, PLL > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 1000100;
int fi[maxn], la[maxn];
int tab[maxn], pref[maxn];
int n;


int main()
{
	boost;
	cin >> n;
	ll res = 0;
	FOR(i, 1, n) {
		pref[i] = pref[i - 1];
		cin >> tab[i];
		if (fi[tab[i]] == 0) fi[tab[i]] = i, pref[i]++;
		la[tab[i]] = i;
	}
	
	FOR(i, 1, n) {
		if (la[tab[i]] == i) res += pref[i - 1];
	}
	
	cout << res;
}