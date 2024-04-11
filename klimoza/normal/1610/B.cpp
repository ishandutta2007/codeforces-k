#include <math.h>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

const double pi = acos((double) -1);
const ld eps = 1e-8;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = 4e18;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;

void solve();

signed main() {
#ifdef DEBUG
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#endif
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed;
  cout.precision(15);
  solve();
  return 0;
}

bool check(vector<int> &a) {
  int n = a.size();
  for(int i = 0; i < n; i++)
    if(a[i] != a[n - i - 1])
      return false;
  return true;
}

void solve() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int>a(n);
    for(int i = 0 ; i <n ;i++)
      cin >> a[i];
    if(check(a))
      cout << "YES\n";
    else {
      int l = 0;
      int x = -1, y = -1;
      while(true) {
        if(a[l] == a[n - 1 - l]) {
          l++;
          continue;
        }
        x = a[l];
        y = a[n - 1 - l];
        break;
      }
      vector<int> c1, c2;
      for(int i= 0; i < n; i++) {
        if(a[i] != x)
          c1.push_back(a[i]);
        if(a[i] != y)
          c2.push_back(a[i]);
      }
      if(check(c1) || check(c2))
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
}