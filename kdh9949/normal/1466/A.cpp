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

template<typename... Args>
void readln(Args&... args) { ((cin >> args), ...); }
template<typename... Args>
void writeln(Args... args) { ((cout << args << " "), ...); cout << '\n'; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ints(t);
  while(t--) {
    ints(n);
    vint a(n);
    for(int &x : a) cin >> x;
    sort(all(a));
    set<int> s;
    for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++)
      s.insert(a[j] - a[i]);
    writeln(s.size());
  }

  return 0;
}