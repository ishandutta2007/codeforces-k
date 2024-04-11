#include "bits/stdc++.h"
using namespace std;

typedef string::const_iterator State;
#define eps 1e-8L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
#define REP(a, b) for (long long(a) = 0; (a) < (b); ++(a))
#define ALL(x) (x).begin(), (x).end()

#define int long long

void solve() {
  int a, b;
  cin >> a >> b;
  int ans = abs(b - a);
  for(int q = 0;q <= b;++q){
    int x = b + q;
    int tmp_a = x | a;
    ans = min(ans, q + 1 + abs(tmp_a - x));
  }
  for(int q = 0;q <= b;++q){
    int tmp_a = a + q;
    tmp_a = b | tmp_a;
    ans = min(ans, q + 1 + abs(tmp_a - b));
  }
  cout << ans << endl;
}
#undef int

// generated by oj-template v4.7.2
// (https://github.com/online-judge-tools/template-generator)
int main() {
  // Fasterize input/output script
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(100);
  // scanf/printf user should delete this fasterize input/output script

  int t = 1;
  cin >> t; // comment out if solving multi testcase
  for (int testCase = 1; testCase <= t; ++testCase) {
    solve();
  }
  return 0;
}