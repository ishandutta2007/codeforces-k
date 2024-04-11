#include<bits/stdc++.h>
namespace {
using namespace std;
#define rep(i,n)for (int i = 0; i < int(n); ++i)
#define rrep(i,n)for (int i = int(n)-1; i >= 0; --i)
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
    bool ok = true;
    rep(i, n - 1) if (a[i] == 0 && a[i + 1] == 0) {
      ok = false;
      break;
    }
    if (!ok) {
      cout << -1 << '\n';
      continue;
    }
    int now = 1;
    rep(i, n) if (a[i]) {
      if (i && a[i - 1]) now += 5;
      else now++;
    }
    cout << now << '\n';
  }
}