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
const int inf = 1e9+9;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000100
int n, m, d,a,b,c;
int goal[5], t[5];
int main()
{
    cin >> t[1] >> t[2] >> t[3];
    cin >> goal[1] >> goal[2] >> goal[3];
    int oczekiwane = 0;
    int dobre = 0;
    for (int i=1; i<=3; ++i)
    {
        if (t[i] >= goal[i]) dobre += (t[i] - goal[i])/2;
        else oczekiwane += goal[i] - t[i];
    }
    if (dobre >= oczekiwane) puts("Yes");
    else puts("No");
}