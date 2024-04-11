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

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

void solve() {
    int x, y;
    cin >> x >> y;
    if(x == 1) {
        if(y == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    } else if(x == 2 || x == 3) {
        if(y <= 3) cout << "YES" << endl;
        else cout << "NO" << endl;
    } else cout << "YES" << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}