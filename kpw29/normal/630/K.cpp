#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define e1 first
#define e2 second
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
const int mod = 100;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 4e18 + 3;
#define maxn 1500100
int n, m, a, b, c, d;
const long double T = 1.000000011;
ll a1, a2, b1, b2;

int main()
{
	ll suma = 210, result = 0;
	for (int i=0; i<=suma; ++i)
	{
		int bit = 1;
		for (int j=2; j<=10; ++j)
		  if (i % j == 0) bit = 0;
		result += bit;
	}
	ll N;
	cin >> N;
	ll ile = (N / suma);
	ll R = (ile * result);
	N %= suma;
	for (int i=1; i<=N; ++i)
	{
		int bit = 1;
		for (int j=2; j<=10; ++j)
		  if (i % j == 0) bit = 0;
		R += bit;
	}
	cout << R;
}