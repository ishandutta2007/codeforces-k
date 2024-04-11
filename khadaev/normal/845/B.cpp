#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n - 1); i >= (int)(a); --i)
#define fore(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

template<typename T>
inline void setmax(T& a, T b) {
    if (a < b) a = b;
}

template<typename T>
inline void setmin(T& a, T b) {
    if (a > b) a = b;
}

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int _n = n;
    int ans = INF;
    for (int i = 0; i < 1000000; ++i) {
        int _i = i;
        int s1 = 0, s2 = 0;
        forn(j, 0, 3) {
            s1 += i % 10;
            i /= 10;
        }
        forn(j, 0, 3) {
            s2 += i % 10;
            i /= 10;
        }
        i = _i;
        int loc = 0;
        if (s1 != s2) continue;
        forn(j, 0, 6) {
            loc += (n % 10 != i % 10);
            i /= 10;
            n /= 10;
        }
        n = _n;
        i = _i;
        setmin(ans, loc);
    }
    cout << ans << '\n';
}