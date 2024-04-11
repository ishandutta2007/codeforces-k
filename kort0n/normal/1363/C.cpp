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
    ll n, x;
    cin >> n >> x;
    ll d = 0;
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        d += (a == x);
        d += (b == x);
    }
    if(d <= 1) {
        cout << "Ayush" << endl;
        return;
    }
    if(n & 1) {
        cout << "Ashish" << endl;
    } else {
        cout << "Ayush" << endl;
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