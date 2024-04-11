#include <bits/stdc++.h>
//#include <atcoder/all>
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
    vector<ll> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    map<ll, ll> Last, num;
    for(int i = 0; i < N; i++) {
        if(i != 0) {
            if(Last.count(a[i]) == 0 or Last[a[i]] != i - 1)
            num[a[i]]++;
        }
        Last[a[i]] = i;
    }
    ll ans = INF;
    for(int i = 0; i < N; i++) {
        if(Last[a[i]] != N - 1) num[a[i]]++;
        chmin(ans, num[a[i]]);
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}