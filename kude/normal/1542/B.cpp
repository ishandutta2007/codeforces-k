#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        ll n, a, b;
        cin >> n >> a >> b;
        if (a == 1) {
            cout << ((n - 1) % b == 0 ? "Yes" : "No") << '\n';
            continue;
        }
        __int128_t x = 1;
        while(x <= n && (n - x) % b) {
            x *= a;
        }
        cout << (x <= n && (n - x) % b == 0 ? "Yes" : "No") << '\n';
    }
}