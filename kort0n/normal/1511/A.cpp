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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        int ans = 0;
        for(int i = 0; i < N; i++) {
            int a;
            cin >> a;
            if(a == 1 or a == 3) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}