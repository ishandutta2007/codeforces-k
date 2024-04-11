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
    //freopen("/Users/alexandero/CLionProjects/cryptozoology/input.txt", "r", stdin);
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
    //cin >> t;
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

bool local = false;
int n;
vector<int> lens;
int query_count = 0;

void gen() {
  if (!local) {
    cin >> n;
    return;
  }
  query_count = 0;
  n = 2000;
  n = 500;
  //n = 2;
  for (int i = 0; i < n; ++i) {
    lens.push_back(rand() % 2000 + 1);
  }
}

map<int, int> cached;

int get_local_res(int w) {
  int ans = 0;
  for (int pos = 0; pos < n; ) {
    ++ans;
    int cur_sum = lens[pos], cur_pos = pos + 1;
    if (cur_sum > w) {
      return 0;
    }
    while (cur_pos < n && cur_sum + lens[cur_pos] + 1 <= w) {
      cur_sum += lens[cur_pos] + 1;
      ++cur_pos;
    }
    pos = cur_pos;
  }
  return ans;
}

int get_query(int w) {
  if (cached.count(w)) {
    return cached[w];
  }
  ++query_count;
  if (local) {
    return cached[w] = get_local_res(w);
  } else {
    cout << "? " << w << endl;
    int res;
    cin >> res;
    return cached[w] = res;
  }
}

void output(int area) {
  cout << "! " << area << endl;
  if (local) {
    li stupid = (li)1e18;
    for (int w = 1; w <= n * 2001; ++w) {
      int h = get_local_res(w);
      if (h != 0) {
        relax_min(stupid, h * 1LL * w);
      }
    }
    cerr << "area: " << area << " stupid: " << stupid << endl;
    assert(stupid == area);
  }
}

void solve(__attribute__((unused)) bool read) {
  gen();
  int L = 0, R = n * 2001;
  while (L + 1 < R) {
    int M = (L + R) / 2;
    if (get_query(M) != 1) {
      L = M;
    } else {
      R = M;
    }
  }
  int res = R;
  for (int h = 2; h <= n; ++h) {
    int candy = R - (R % h);
    //cout << "h: " << h << " candy: " << candy << endl;
    if (candy > res) {
      continue;
    }
    int w = candy / h;
    if (w <= 0) {
      continue;
    }
    int actual_h = get_query(w);
    if (actual_h != h) {
      continue;
    }
    relax_min(res,  candy);
  }
  output(res);

  //cerr << "query_count: " << query_count << " constraint: " << n + 30 << endl;
  assert(query_count <= n + 30);
}