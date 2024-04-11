#line 1 "Contests/Codeforces_1530/B/main.cpp"
using namespace std;
#line 2 "library/bits/stdc++.h"

// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
#line 3 "Contests/Codeforces_1530/B/main.cpp"

// add your library with double quotation #include"" here.
// add your library with double quotation #include"" here.
// define your macros here.
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
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()

#define int long long
vector<vector<int>> grid;
void fill(int x,int y){
  grid[x][y] = 2;
  REP(q,3){
    REP(j,3){
      int now_x = x - 1 + q;
      int now_y = y - 1 + j;
      if(now_x >= 0 and now_y >= 0 and now_x < grid.size() and now_y < grid[0].size()){
        grid[now_x][now_y] |= 1;
      }
    }
  }
}
void solve(){
  int h,w;
  cin >> h >> w;
  grid = vector<vector<int>>(h,vector<int>(w,0));
  fill(0,0);
  fill(h-1,0);
  fill(0,w-1);
  fill(h-1,w-1);
  REP(i,h){
    REP(q,w){
      if(i == 0 or i == h-1 or q == 0 or q == w-1){
        if(grid[i][q] == 0){
          fill(i,q);
        }
      }
    }
  }
  REP(i,h){
    REP(q,w){
      cout << grid[i][q] / 2;
    }
    cout << endl;
  }
}
#undef int

// generated by oj-template v4.7.2 (https://github.com/online-judge-tools/template-generator)
int main() {
    // Fasterize input/output script
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(100);
    // scanf/printf user should delete this fasterize input/output script

    int t = 1;
    cin >> t; // comment out if solving multi testcase
    for(int testCase = 1;testCase <= t;++testCase){
        solve();
    }
    return 0;
}