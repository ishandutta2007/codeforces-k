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

const int N = 1e3 + 2;

int p[N], sz[N];

void build(int n) {
  for(int i = 0; i < n; i++) {
    p[i] = i;
    sz[i] = 1;
  }
}

int get_par(int k) {
  if(p[k] == k) return k;
  return p[k] = get_par(p[k]);
}

void merge(int a, int b) {
  a = get_par(a);
  b = get_par(b);
  if(a == b) return;
  if(sz[a] < sz[b]) swap(a, b);
  sz[a] += sz[b];
  p[b] = a;
}

void solve() {
  int n, d; cin >> n >> d;
  build(n);
  int cnt = 1;
  while(d--) {
    int x, y; cin >> x >> y; x--; y--;
    if(get_par(x) != get_par(y))
      merge(x, y);
    else {
      cnt++;
    }
    vector<pair<int, int>> kek;
    for(int i = 0; i < n; i++) {
      if(i != get_par(i))
        continue;
      kek.push_back({sz[i], i});
    }
    sort(rall(kek));
    ll ans = 0;
    for (int i = 0; i < min(cnt, n); i++)
      ans += kek[i].first;
    cout << ans - 1 << endl;
  }
}