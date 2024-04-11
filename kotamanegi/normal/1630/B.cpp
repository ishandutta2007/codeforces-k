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
  int n, k;
  cin >> n >> k;
  vector<int> inputs,moto;
  REP(i, n)
  {
    int a;
    cin >> a;
    inputs.push_back(a);
  }
  moto = inputs;
  sort(ALL(inputs));
  priority_queue<int, vector<int>, greater<int>> nexts;
  pair<int, int> ans = {0, 1e18};
  REP(i, n)
  {
    nexts.push(inputs[i]);
    while((int)nexts.size() * 2 >= k + n + 2){
      nexts.pop();
    }
    if((int)nexts.size() * 2 >= k + n){
      pair<int, int> go = {nexts.top(), inputs[i]};
      if(go.second - go.first < ans.second - ans.first){
        ans = go;
      }
    }
  }
  cout << ans.first << " " << ans.second << endl;
  int now = 0;
  int backs = 1;
  int cnt = 1;
  inputs = moto;
  REP(i, n)
  {
    if(cnt == k)
      continue;
    if(inputs[i] >= ans.first and inputs[i] <= ans.second){
      now++;
    }else{
      now--;
    }
    if(now == cnt){
      cout << backs << " " << i + 1 << endl;
      backs = i + 2;
      cnt++;
    }
  }
  cout << backs << " " << n << endl;
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