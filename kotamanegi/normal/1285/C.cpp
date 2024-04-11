#pragma comment (linker, "/STACK:256000000")
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;
typedef string::const_iterator State;
const long double Ma_PI = 3.1415926535897932384626433832795028841971L;
#define eps 1e-7
#define LONG_INF 2000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144*2
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long a = 0;a < b;++a)
#define ALL(x) (x).begin(),(x).end()
void init() {
    iostream::sync_with_stdio(false);
    cout << fixed << setprecision(20);
}
unsigned long xor128() {
    static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned long t = (x ^ (x << 11));
    x = y; y = z; z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
#define int ll
void solve(){
    int x;
    cin >> x;
    if (x == 1) {
        cout << "1 1" << endl;
        return;
    }
    vector<int> nya;
    for (int i = 2; i <= sqrt(x); ++i) {
        if (x % i == 0) {
            int cnt = 1;
            while (x % i == 0) {
                x /= i;
                cnt*= i;
            }
            nya.pb(cnt);
        }
    }
    if (x != 1) {
        nya.push_back(x);
    }
    pair<int, int> ans = mp(1e13, 1e13);
    REP(i, (1 << nya.size())) {
        pair<int, int> tmp = mp(1, 1);
        REP(q, nya.size()) {
            if ((i & (1 << q)) != 0) {
                tmp.first *= nya[q];
            }
            else {
                tmp.second *= nya[q];
            }
        }
        if (max(ans.first, ans.second) > max(tmp.first, tmp.second)) {
            ans = tmp;
        }
    }
    cout << ans.first << " " << ans.second << endl;
}
#undef int
int main() {
    init();
    solve();
}