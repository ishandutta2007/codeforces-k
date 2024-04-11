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
int a[205];

void solve() {
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> a[i];
    bool clear = true;
    for(int i = 1; i < N; i++) {
        if(a[i] - a[i+1] != 1 && a[i] - a[i+1] != 1 - N) clear = false;
    }
    if(clear) {
        cout << "YES" << endl;
        return;
    }
    clear = true;
    for(int i = 1; i < N; i++) {
        if(a[i] - a[i+1] != -1 && a[i] - a[i+1] != N - 1) clear = false;
    }
    if(clear) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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