#include <bits/stdc++.h>
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

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
//const ll mod = 1000000007;

void solve() {
    ll n;
    cin >> n;
    if(n % 2 == 1) {
        cout << "7";
        n -= 3;
    }
    for(int i = 0; i < n / 2; i++) {
        cout << "1";
    }
    cout << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--) solve();
    return 0;
}