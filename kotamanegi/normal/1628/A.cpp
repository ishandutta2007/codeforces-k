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
  vector<int> inputs;
  REP(i, n)
  {
    int a;
    cin >> a;
    inputs.push_back(a);
  }
  vector<int> ans;
  map<int, int> findings;
  priority_queue<int, vector<int>, greater<int>> nexts;
  REP(i, n)
  {
    findings[0]++;
    ans.push_back(0);
    int x = inputs[i];
    if (findings[x] != 0)
    {
      while (findings[x] != 1 or ans.back() != x)
      {
        findings[ans.back()]--;
        ans.pop_back();
      }

      findings[x] = 0;
      ans.back()++;
      while (nexts.empty() == false)
      {
        int now = nexts.top();
        if (now < ans.back())
        {
          nexts.pop();
          continue;
        }
        if (now == ans.back())
        {
          nexts.pop();
          ans.back()++;
          continue;
        }
        break;
      }
      findings[ans.back()]++;
      continue;
    }
    nexts.push(x);
  }
  cout << ans.size() << endl;
  REP(i, ans.size())
  {
    if (i != 0)
      cout << " ";
    cout << ans[i];
  }
  cout << endl;
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