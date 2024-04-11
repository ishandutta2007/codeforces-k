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
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<ll> num(26);
    for(auto c : S) {
        num[(int)(c - 'a')]++;
    }
    for(ll i = N; i >= 1; i--) {
        int g = __gcd(i, K);
        ll k = i / g;
        ll tmp = 0;
        for(int j = 0; j < 26; j++) {
            tmp += (num[j] / k) * k;
        }
        if(tmp >= i) {
            cout << i << endl;
            return;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}