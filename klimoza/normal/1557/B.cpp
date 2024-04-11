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

const double PI = acos((double) -1);
const ld eps = 1e-8;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = 4e18;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;

void solve();
signed main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
  cout << fixed; cout.precision(15);
  solve();
  return 0;
}

void solve() {
  int t; cin >> t;
  while(t--) {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    int cnt = 1;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b = a;
    sort(all(b));
    map<int, int> id;
    for(int i = 0; i < n; i++)
      id[b[i]] = i;
    for(int i = 1; i < n; i++) {
      if(id[a[i]] != id[a[i - 1]] + 1)
        cnt++;
    }
    if(cnt <= k)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}