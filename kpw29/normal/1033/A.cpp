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
const int maxn = 1020000;

string s1, s2, s;
int n, m, k;

vector <PII> moves;
int ban[1010][1010], x, y;

int type(int p, int q) {
	if (p > 0 && q > 0) {
		return 0;
	}
	if (p > 0 && q < 0) {
		return 2;
	}
	if (p < 0 && q < 0) {
		return 4;
	}
	if (p < 0 && q > 0) {
		return 6;
	}
}

int main()
{
	boost;
	cin >> n; m = n;
	cin >> x >> y;
	int X1, X2, Y1, Y2;
	cin >> X1 >> Y1;
	cin >> X2 >> Y2;
	X2 -= x; Y1 -= y;
	X1 -= x; Y2 -= y;
	
	//cout << X1 << ' ' << Y1 << endl;
	//cout << X2 << ' ' << Y2 << endl;
	if (type(X1, Y1) == type(X2, Y2)) cout << "YES";
	else cout << "NO";
}