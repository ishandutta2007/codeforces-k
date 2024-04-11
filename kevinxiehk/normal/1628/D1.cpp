#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1e18
#define ick cout<<"ickbmi32.9\n"
const int mod = 1e9 + 7;
using namespace std;
bool isprime(int k) {
    for(int i = 2; i <= sqrt(k); i++) if(k % i == 0) return false; 
    return true;
}
int bm(int a, int b, int mod) {
    if(b == 0) return 1; 
    int t = bm(a, b / 2, mod); 
    t = t * t % mod; 
    return (b % 2 == 1 ? t * a % mod : t);
}
int inv(int a, int mod) {return bm(a, mod - 2, mod);}
void gay(int TC) {cout << "Case #" << TC << ": ";}
void solve(int TC) {
    int n, m, k;
    cin >> n >> m >> k;
    // m = n - m;
    int dp[n + 5][m + 5];
    for(int i = 0; i <= n; i++) for(int j = 0; j <= m; j++) dp[i][j] = 0;
    for(int i = 0; i <= m; i++) dp[n - i][m - i] = i;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = max(-1LL, m - n + i) + 1; j < min(i + 1, m); j++) {
            dp[i][j] = (dp[i + 1][j] + dp[i + 1][j + 1]) % mod * inv(2, mod) % mod;
            // dp[i][j] %= mod;
            // int lef = m - j, lefr = n - i;
            // // lef = lefr - lef;
            // if(lef < 0) continue;
            // double x = 1.0 * lef * k / lefr;
            // int xx = lef * k % mod * inv(lefr, mod) % mod;
            // // cerr << i << ' ' << j << ' ' << lef << ' ' << lefr << ' ' << x << '\n';
            // if(dp[i][j].se - x >= dp[i + 1][j].se || j == 0) {
            //     dp[i + 1][j] = mp((dp[i][j].fi - xx + mod) % mod, dp[i][j].se - x);
            // }
            // dp[i + 1][j + 1] = mp((dp[i][j].fi + xx + mod) % mod, dp[i][j].se + x);
        }
    }
    // for(int i = 0; i <= m; i++) {for(int j = 0; j <= n; j++) cout << dp[j][i] << ' '; cout << '\n';}
    cout << dp[0][0] * k % mod << '\n';
    // cout << dp[n][m].se * k << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}