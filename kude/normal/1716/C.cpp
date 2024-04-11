#include<bits/stdc++.h>
namespace {
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(i,n) for(int i = (int)(n) - 1; i >= 0; i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int m;
    cin >> m;
    VVI a(2, VI(m));
    rep(i, 2) rep(j, m) cin >> a[i][j];
    constexpr int INF = 1001001001;
    int l = -1, r = INF;
    while(r - l > 1) {
      int c = (l + r) / 2;
      bool ok = true;
      int i = 0, j = 0;
      int now = c;
      auto check = [&](int i, int sj, int now) {
        for(int j = sj + 1; j < m; j++) {
          if (now < a[i][j]) {
            ok = false;
            return;
          }
          now++;
        }
        for(int j = m - 1; j >= sj; j--) {
          if (now < a[1^i][j]) {
            ok = false;
            return;
          }
          now++;
        }
      };
      while(true) {
        if (now < a[1^i][j]) {
          check(i, j, now);
          break;
        }
        if (j == m - 1) break;
        if (now + 1 < a[1^i][j+1]) {
          check(i, j, now);
          break;
        }
        now += 2;
        i ^= 1;
        j++;
      }
      (ok ? r : l) = c;
    }
    int ans = r + 2 * m - 1;
    cout << ans << '\n';
  }
}