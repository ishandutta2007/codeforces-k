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
    int n;
    cin >> n;
    VI a(n);
    rep(i, n) cin >> a[i];
    int now = 0;
    VI ans;
    while(true) {
      int mx = 0;
      int imx = -1;
      rep(i, n) if (chmax(mx, now | a[i])) {
        imx = i;
      }
      if (mx <= now) break;
      now |= a[imx];
      ans.emplace_back(a[imx]);
      swap(a[imx], a.back());
      a.pop_back();
      n--;
    }
    for(int x: a) ans.emplace_back(x);
    n = ans.size();
    rep(i, n) cout << ans[i] << " \n"[i + 1 == n];
  }
}