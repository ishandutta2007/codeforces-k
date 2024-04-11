#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

using vint = vector<int>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define x first
#define y second
#define all(v) (v).begin(),(v).end()
#define ints(args...) int args; readln(args);
#define lls(args...) ll args; readln(args);
#define strs(args...) string args; readln(args);

template<typename... Args>
void readln(Args&... args) { ((cin >> args), ...); }
template<typename... Args>
void writeln(Args... args) { ((cout << args << " "), ...); cout << '\n'; }


int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  ints(t);
  while(t--) {
    ints(n);
    vint a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    struct Gugan { int s, e, i; };
    vector<Gugan> v;
    for(int i = 1; i <= n; i++) {
      // a[i] <= i / x < a[i] + 1
      // a[i] * x <= i < (a[i] + 1) * x
      // i / (a[i] + 1) < x <= i / a[i]
      v.push_back({i / (a[i] + 1) + 1, (a[i] ? i / a[i] : n), i});
    }
    sort(all(v), [&](Gugan p, Gugan q) { return p.e < q.e; });
    set<int> s;
    for(int i = 1; i <= n; i++) s.insert(i);
    vint ans(n + 1);
    for(Gugan &g : v) {
      ans[g.i] = *s.lower_bound(g.s);
      s.erase(ans[g.i]);
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
  }

  return 0;
}