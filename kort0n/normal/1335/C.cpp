#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
//const ll mod = 1000000007;

void solve() {
    ll N;
    cin >> N;
    map<ll, ll> mp;
    for(int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        mp[a]++;
    }
    ll num = mp.size();
    ll maxi = 0;
    for(auto tmp : mp) chmax(maxi, tmp.second);
    ll ans = min(maxi, num);
    if(ans == maxi and ans == num) ans--;
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}