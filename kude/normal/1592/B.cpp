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
        int n, x;
        cin >> n >> x;
        VI a(n);
        rep(i, n) cin >> a[i];
        vector<char> conn(n);
        rep(i, n) if (i + x < n) conn[i] = conn[i + x] = true;
        VI b;
        rep(i, n) if (conn[i]) b.push_back(a[i]);
        sort(rall(b));
        rep(i, n) if (conn[i]) a[i] = b.back(), b.pop_back();
        bool ok = true;
        rep(i, n - 1) if (a[i] > a[i + 1]) ok = false;
        cout << (ok ? "YES\n" : "NO\n");
    }
}