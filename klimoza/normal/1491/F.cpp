//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
//#pragma GCC target("avx2")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
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

//#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

const double PI = acos((double)-1);
const ld eps = 1e-8;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * 1ll * inf0;
const ll mod = 1e9 + 7;
// const ll mod = 998244353;

void solve();
void scan();

signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed;
  cout.precision(15);
  solve();
  return 0;
}

void solve() {
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    int x = -1;
    for(int i = 1; i < n; i++){
      cout << "? " << i << " " << 1 << endl;
      for(int j = 0; j < i; j++)
        cout << j + 1 << " ";
      cout << endl;
      cout << i + 1 << endl;
      int p; cin >> p;
      if(p){
        x = i;
        break;
      }
    }
    int l = -1, r = x - 1;
    while(r - l > 1){
      int m = l + r >> 1;
      cout << "? " << m + 1 << " " << 1 << endl;
      for(int j = 0; j <= m; j++)
        cout << j + 1 << " ";
      cout << endl;
      cout << x + 1 << endl;
      int p; cin >> p;
      if(p)
        r = m;
      else
        l = m;
    }
    vector<int> ans;
    for(int i = 0; i < x; i++)
      if(i != r)
        ans.push_back(i);
    for(int j = x + 1; j < n; j++){
      cout << "? " << 1 << " " << 1 << endl;
      cout << x + 1 << endl;
      cout << j + 1 << endl;
      int p; cin >> p;
      if(!p)
        ans.push_back(j);
    }
    cout << "! " << ans.size() << " ";
    for(int i :ans)
      cout << i + 1 << " ";
    cout << endl;
  }
  return;
}