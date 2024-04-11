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
//int timer = 1;

int testNumber = 1;

bool todo = true;

int main() {
#ifdef AIM
    freopen("/home/alexandero/ClionProjects/ACM/input.txt", "r", stdin);
    //freopen("/home/alexandero/ClionProjects/ACM/output.txt", "w", stdout);
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
    cout.precision(10);
    cout << fixed;
    //cin >> t;
    int testNum = 1;
    while (t--) {
        //cerr << testNum << endl;
        //cout << "Case #" << testNum++ << ": ";
        solve(true);
        ++testNumber;
        //++timer;
    }

    /*while (true) {
        solve(false);
    }*/

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

void precalc() {

}

//#define int li

void solve(bool read) {
    int one = 20;
    int min90 = 50;
    int min1440 = 120;
    int n;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    int uk90 = 0, uk1440 = 0;
    vector<int> dp(n);
    dp[0] = 20;
    cout << dp[0] << "\n";
    for (int i = 1; i < n; ++i) {
        dp[i] = dp[i - 1] + one;
        while (uk90 < i && t[i] - t[uk90] >= 90) {
            ++uk90;
        }
        int cur_val = (uk90 == 0 ? 0 : dp[uk90 - 1]) + min90;
        dp[i] = min(dp[i], cur_val);
        while (uk1440 < i && t[i] - t[uk1440] >= 1440) {
            ++uk1440;
        }
        cur_val = (uk1440 == 0 ? 0 : dp[uk1440 - 1]) + min1440;
        dp[i] = min(dp[i], cur_val);
        cout << dp[i] - dp[i - 1] << "\n";
    }

}