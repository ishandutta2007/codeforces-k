#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(bool);
void precalc();
clock_t start;
int main() {
#ifdef AIM
  freopen("/home/alexandero/CLionProjects/ACM/input.txt", "r", stdin);
  //freopen("/home/alexandero/CLionProjects/ACM/output.txt", "w", stdout);
  //freopen("out.txt", "w", stdout);
#else
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif
  start = clock();
  int t = 1;
  cout.sync_with_stdio(0);
  cin.tie(0);
  precalc();
  cout.precision(20);
  cout << fixed;
  //cin >> t;
  while (t--) {
    solve(true);
  }
  cout.flush();

#ifdef AIM1
  while (true) {
      solve(false);
  }
#endif

#ifdef AIM
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

void precalc() {

}

//#define int li
//const int mod = 1000000007;

enum Type {
  VAR = 0,
  AND = 1,
  OR = 2
};

string dp[256][3];

bool relax(int mask, int type, string new_val) {
  bool relaxed = false;
  while (type < 3) {
    auto& cur_dp = dp[mask][type];
    if (cur_dp.empty() || cur_dp.length() > new_val.length() || cur_dp.length() == new_val.length() && cur_dp > new_val) {
      cur_dp = new_val;
      //cout << mask << " " << type << " " << cur_dp << endl;
      relaxed = true;
    }
    ++type;
  }
  return relaxed;
}

void solve(bool read) {
  relax((1 << 4) + (1 << 5) + (1 << 6) + (1 << 7), VAR, "x");
  relax((1 << 2) + (1 << 3) + (1 << 6) + (1 << 7), VAR, "y");
  relax((1 << 1) + (1 << 3) + (1 << 5) + (1 << 7), VAR, "z");
  while (true) {
    bool found = false;
    for (int mask = 0; mask < 256; ++mask) {
      if (!dp[mask][OR].empty()) {
        found |= relax(mask, VAR, "(" + dp[mask][OR] + ")");
      }
      if (!dp[mask][VAR].empty()) {
        found |= relax(mask ^ 255, VAR, "!" + dp[mask][VAR]);
      }
    }
    for (int mask1 = 0; mask1 < 256; ++mask1) {
      for (int mask2 = 0; mask2 < 256; ++mask2) {
        if (!dp[mask1][AND].empty() && !dp[mask2][AND].empty()) {
          found |= relax(mask1 & mask2, AND, dp[mask1][AND] + "&" + dp[mask2][AND]);
        }
        if (!dp[mask1][OR].empty() && !dp[mask2][OR].empty()) {
          found |= relax(mask1 | mask2, OR, dp[mask1][OR] + "|" + dp[mask2][OR]);
        }
      }
    }
    if (!found) {
      break;
    }
  }
  for (int mask = 0; mask < 256; ++mask) {
    assert(!dp[mask][OR].empty());
    //cout << mask << " " << dp[mask][OR] << endl;
  }

  int T;
  cin >> T;
  while (T--) {
    string cur;
    cin >> cur;
    int mask = 0;
    for (int i = 0; i < 8; ++i) {
      if (cur[i] == '1') {
        mask |= (1 << i);
      }
    }
    cout << dp[mask][OR] << endl;
  }

}