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

void solve()
{
  int n;
  cin >> n;
  vector<vector<int>> inputs(n);
  REP(i, n)
  {
    REP(q, n)
    {
      int a;
      cin >> a;
      inputs[i].push_back(a);
    }
  }
  int ans = 0;
  REP(tea, 2)
  {
    int steps = 4;
    int x = 0;
    int y = 0;
    while (x < n and y < n)
    {
      if (steps == 4)
      {
        steps = 0;
        for (int q = 0; x - q >= 0 and y + q < n; q += 2)
        {
          ans ^= inputs[x - q][y + q];
        }
      }
      steps++;
      if (x == n - 1)
        y++;
      else
        x++;
    }
    reverse(ALL(inputs));
  }
  cout << ans << endl;
}
#undef int

// generated by oj-template v4.7.2
// (https://github.com/online-judge-tools/template-generator)
int main()
{
  // Fasterize input/output script
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(100);
  // scanf/printf user should delete this fasterize input/output script

  int t = 1;
  cin >> t; // comment out if solving multi testcase
  for (int testCase = 1; testCase <= t; ++testCase)
  {
    solve();
  }
  return 0;
}