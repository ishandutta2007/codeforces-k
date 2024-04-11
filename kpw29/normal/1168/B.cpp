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
const int maxn = 1001010;

vector <int> v[2];
int tab[maxn];

int main()
{
	boost;
	string s;
	cin >> s;
	int n = s.length();
	for (int i=0; i<n; ++i) tab[i + 1] = s[i] - '0';
	
	int MAX = 0;
	ll result = 0;
	for (int i=1; i<=n; ++i) {
		int r = tab[i];
		for (int xd = v[r].size()-1; xd>=0; --xd) {
			int u = v[r][xd];
			if (u + u - i <= MAX) break;
			if (tab[u + u - i] == tab[i]) {
				MAX = u + u - i;
				break;
			}
		}
		
		v[r].pb(i);
		result += MAX;
	}
	
	cout << result;
}