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
    sort(all(a));
    VI d;
    for(int i = 0; i < n;) {
      int j = i + 1;
      while(j < n && a[j] == a[i]) j++;
      d.emplace_back(min(j - i, 2));
      i = j;
    }
    int tot = 0;
    for(int x: d) tot += x;
    int ans = 0;
    for(int x: d) chmax(ans, 1 + (tot - x) / 2);
    cout << ans << '\n';
  }
}