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
const int mod = 1e8;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 2000100
int n, m, k,  b, c;


int main()
{
    ll wyn = 0;
    cin >> n;
    if (n % 2 == 1) OUT(0);
    n /= 2;
    wyn = (n) / 2;
    if (n % 2 == 0) --wyn;
    cout << wyn;
    
}