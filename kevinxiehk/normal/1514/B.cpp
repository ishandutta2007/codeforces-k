#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define ick cout<<"ickbmi32.9\n"
using namespace std;
void solve() {
    int n, k;
    int ans = 1;
    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        ans *= n;
        ans %= 1000000007LL;
    }
    cout << ans << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}