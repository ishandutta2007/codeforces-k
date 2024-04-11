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

void solve() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i]; a[i] += 100;
    }
    vector<int> cnt(205, 0);
    for(int i =0 ; i < n; i++) {
      cin >> b[i]; b[i] += 100;
      cnt[b[i]]++;
    }
    sort(rall(a));
    bool fl = true;
    for(int i = 0; i < n; i++) {
      if(cnt[a[i] + 1]) {
        cnt[a[i] + 1]--;
      } else if(cnt[a[i]]) {
        cnt[a[i]]--;
      } else {
        fl = false;
        break;
      }
    }
    if(fl)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}