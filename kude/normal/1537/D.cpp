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
        int n;
        cin >> n;
        if (n % 2) {
            cout << "Bob" << '\n';
            continue;
        }
        int k = 0;
        while(n % 2 == 0) n /= 2, k++;
        if (n > 1) {
            cout << "Alice" << '\n';
            continue;
        }
        if (k % 2 == 0) cout << "Alice" << '\n';
        else cout << "Bob" << '\n';
    }
}