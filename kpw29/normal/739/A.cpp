#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 1001000;
int n, m, a, b, root; char zn;
int A[maxn], B[maxn];

int main()
{
	int wyn = inf;
	boost;
	cin >> n >> m;
	FOR(i, 1, m) {
		cin >> A[i] >> B[i];
		wyn = min(wyn, B[i] - A[i] + 1);
	}
	cout << wyn << endl;
	FOR(i, 1, n) cout << (i % wyn) << ' ';
}