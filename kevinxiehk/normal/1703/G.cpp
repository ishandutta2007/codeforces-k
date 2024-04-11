#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1e18
#define ick cout<<"ickbmi32.9\n"
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
    int n, k;
    cin >> n >> k;
    int arr[n + 5];
    int dp[n + 5][35];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        for(int j = 0; j <= 30; j++) dp[i][j] = -inf;
    }
    dp[0][0] = arr[0] - k;
    dp[0][1] = arr[0] / 2;
    int ans = -inf;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 30; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j] - k + arr[i] / (1 << j));
            dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] + arr[i] / (1 << (j + 1)));
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= 30; j++) ans = max(ans, dp[i][j]);
    }
    cout << ans << '\n';
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