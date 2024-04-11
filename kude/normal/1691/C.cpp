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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (auto p = s.find_last_of('1'); p != string::npos && n - 1 - (int)p <= k) {
      k -= n - 1 - (int)p;
      rotate(s.begin() + p, s.begin() + p + 1, s.end());
    }
    if (auto p = s.find_first_of('1'); p != string::npos && (int)p != n - 1 && (int)p <= k) {
      k -= (int)p;
      rotate(s.begin(), s.begin() + p, s.begin() + p + 1);
    }
    int ans = 0;
    ans += 10 * (s[0] - '0') + (s[n-1] - '0');
    for(int i = 1; i < n - 1; i++) {
      ans += 11 * (s[i] - '0');
    }
    cout << ans << '\n';
  }
}