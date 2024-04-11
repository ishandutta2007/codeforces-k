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
    int n;
    cin >> n;
    if (n <= 3) {
        string ans;
        for (int i = 1; i <= n; ++i) {
            cout << "? " << i << " " << i << endl;
            string s;
            cin >> s;
            ans += s;
        }
        cout << "! " << ans << endl;
        return;
    }
    string ans;
    cout << "? " << n << " " << n << endl;
    cin >> ans;
    REP(i, n-1) {
        ans.pb('?');
    }
    reverse(ALL(ans));
    vector<string> inputs[2][200];
    REP(i, 2) {
        cout << "? 1 " << n - i << endl;
        int hoge = (n - i) * (n - i + 1) / 2LL;
        REP(q, hoge) {
            string s;
            cin >> s;
            sort(ALL(s));
            inputs[i][s.length()].pb(s);
        }
        REP(q, 200) {
            sort(ALL(inputs[i][q]));
        }
    }
    int cnt[26] = {};
    for (auto x : inputs[0][n][0]) {
        cnt[x - 'a']++;
    }
    for (int i = n - 1; i >= 1; --i) {
        map<string, int> cnt_st;
        for (int q = 0; q < inputs[1][i].size(); ++q) {
            cnt_st[inputs[1][i][q]]--;
        }
        for (int q = 0; q < inputs[0][i].size(); ++q) {
            cnt_st[inputs[0][i][q]]++;
            continue;
            int ok = 1;
            REP(j, inputs[1][i].size()) {
                if (inputs[1][i][j] == inputs[0][i][q]) {
                    ok = 0;
                    break;
                }
            }
            if (ok == 1) {
                //rightest determined.
                int copy_cnt[26] = {};
                REP(q, 26) {
                    copy_cnt[q] = cnt[q]; 
                }
                for (auto x : inputs[0][i][q]) {
                    copy_cnt[x - 'a']--;
                }
                for (int t = 0;; ++t) {
                    if(copy_cnt[t] == 1){
                        cnt[t]--;
                        ans[n - i - 1] = (char)(t + 'a');
                        break;
                    }
                }
                break;
            }
        }
        for (auto x : cnt_st) {
            if (x.second == 0) continue;
            int copy_cnt[26] = {};
            REP(q, 26) {
                copy_cnt[q] = cnt[q];
            }
            for (auto s : x.first) {
                copy_cnt[s - 'a']--;
            }
            for (int t = 0;; ++t) {
                if (copy_cnt[t] == 1) {
                    cnt[t]--;
                    ans[n - i - 1] = (char)(t + 'a');
                    break;
                }
            }
            break;
        }
    }
    cout << "! " << ans << endl;
    return;
}

#undef int
int main() {
    init();
    solve();
}