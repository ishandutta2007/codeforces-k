#pragma comment(linker, "/STACK:512000000")
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <memory>
#include <chrono>
#include <cassert>
#include <random>
#include <queue>
#include <set>
#include <map>
#include <array>
#include <bitset>
#include <sstream>
#ifdef PINELY
#include <sys/resource.h>
#endif

using namespace std;

#define all(a) a.begin(), a.end()
using li = long long;
using ld = long double;
void solve(bool);
void precalc();
clock_t start;
int main() {
#ifdef PINELY
    freopen("/Users/alexandero/CLionProjects/cryptozoology/input.txt", "r", stdin);
  //freopen("/Users/alexandero/CLionProjects/cryptozoology/output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;

#ifdef PINELY
  const rlim_t kStackSize = 60 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
    if (rl.rlim_cur < kStackSize)
    {
      rl.rlim_cur = kStackSize;
      result = setrlimit(RLIMIT_STACK, &rl);
      if (result != 0)
      {
        fprintf(stderr, "setrlimit returned result = %d\n", result);
      }
    }
  }
#endif
#ifndef PINELY
    cout.sync_with_stdio(0);
    cin.tie(0);
#endif
    cout.precision(20);
    cout << fixed;
    cin >> t;
    precalc();
    int test_num = 1;
    while (t--) {
      //cout << "Case #" << test_num++ << ": ";
      solve(true);
    }
    cout.flush();

#ifdef PINELY1
    while (true) {
    solve(false);
  }
#endif

#ifdef PINELY
    cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif
    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

template<typename T>
T binpow(T q, T w, T mod) {
    if (!w)
        return 1 % mod;
    if (w & 1)
        return q * 1LL * binpow(q, w - 1, mod) % mod;
    return binpow(q * 1LL * q % mod, w / 2, mod);
}

template<typename T>
T gcd(T q, T w) {
    while (w) {
        q %= w;
        swap(q, w);
    }
    return q;
}
template<typename T>
T lcm(T q, T w) {
    return q / gcd(q, w) * w;
}

template <typename T>
void make_unique(vector<T>& vec) {
    sort(all(vec));
    vec.erase(unique(all(vec)), vec.end());
}

template<typename T>
void relax_min(T& cur, T val) {
    cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
    cur = max(cur, val);
}

template<typename T>
void print_vec(const vector<T>& vals) {
  for (int x : vals) {
    cout << x << " ";
  }
  cout << endl;
}

mt19937 rng((unsigned long long)chrono::steady_clock::now().time_since_epoch().count());

void precalc() {

}

//#define int li
//const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;

vector<vector<int>> g;
vector<char> used;
vector<int> tout;
int TIMER = 0;

void dfs(int v) {
  if (used[v]) {
    return;
  }
  used[v] = true;
  for (int to : g[v]) {
    if (!used[to]) {
      dfs(to);
    }
  }
  tout[v] = TIMER++;
}

void solve(__attribute__((unused)) bool read) {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  map<int, int> cnt;
  for (int& x : a) {
    cin >> x;
    --x;
    ++cnt[x];
  }
  for (int& x : b) {
    cin >> x;
    --x;
  }
  int mx_val = 0;
  for (auto& item : cnt) {
    relax_max(mx_val, item.second);
  }
  int skip = -1;
  for (auto& item : cnt) {
    if (item.second == mx_val) {
      skip = item.first;
      break;
    }
  }
  assert(skip != -1);
  int N = 2 * n;
  g.clear();
  g.resize(N);
  tout.assign(N, -1);
  for (int i = 0; i < n; ++i) {
    if (a[i] != skip) {
      g[i].push_back(a[i] + n);
    }
    if (b[i] != skip) {
      g[b[i] + n].push_back(i);
    }
  }
  used.assign(N, false);
  for (int i = 0; i < N; ++i) {
    dfs(i);
  }
  for (int i = 0; i < N; ++i) {
    for (int to : g[i]) {
      if (tout[i] < tout[to]) {
        cout << "WA\n";
        return;
      }
    }
  }
  cout << "AC\n";

}