#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(auto&i:a){
            cin >> i;
        }
        int ans = 0;
        for(int i = 0; i < n; ++i){
            int cnt = 0;
            for(int j = i; j < n; ++j){
                cnt += (a[j] == 0);
                ans += j - i + 1 + cnt;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}