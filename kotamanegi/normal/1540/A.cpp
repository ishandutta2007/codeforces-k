#line 1 "Contests/Codeforces_1540/A/main.cpp"
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
#line 3 "Contests/Codeforces_1540/A/main.cpp"

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
void solve(){
    // write your solution here.
    int n;
    cin >> n;
    vector<int> d;
    REP(i,n){
        int a;
        cin >> a;
        d.push_back(a);
    }
    sort(ALL(d));
    int ans = d.back();
    int cnt = 0;
    for(int i = 0;i < n;++i){
        ans -= i * d[i] - cnt;
        cnt += d[i];
    }
    cout << ans << endl;
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