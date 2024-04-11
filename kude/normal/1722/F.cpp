#include<bits/stdc++.h>
namespace {
using namespace std;

#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

using namespace atcoder;
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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    dsu d(n * m);
    rep(i, n) rep(j, m - 1) if (s[i][j] == '*' && s[i][j+1] == '*') {
      d.merge(i * m + j, i * m + j + 1);
    }
    rep(i, n - 1) rep(j, m) if (s[i][j] == '*' && s[i+1][j] == '*') {
      d.merge(i * m + j, (i + 1) * m + j);
    }
    rep(i, n - 1) rep(j, m - 1) if (s[i][j] == '*' && s[i+1][j+1] == '*') {
      d.merge(i * m + j, (i + 1) * m + j + 1);
    }
    rep(i, n - 1) rep(j, m - 1) if (s[i+1][j] == '*' && s[i][j+1] == '*') {
      d.merge((i + 1) * m + j, i * m + j + 1);
    }
    cout << ([&]{
      for(const auto& g: d.groups()) {
        int li = g[0] / m, lj = g[0] % m;
        if (s[li][lj] == '.') continue;
        if (g.size() != 3) return false;
        int imn = n, imx = 0, jmn = m, jmx = 0;
        for(auto x: g) {
          int i = x / m, j = x % m;
          chmin(imn, i);
          chmax(imx, i);
          chmin(jmn, j);
          chmax(jmx, j);
        }
        if (imx - imn != 1 || jmx - jmn != 1) return false;
      }
      return true;
    }() ? "YES\n" : "NO\n");
  }
}