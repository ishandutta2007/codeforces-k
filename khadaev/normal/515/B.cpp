#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
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

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int d = __gcd(n, m);
    vector<char> ok(d, 0);
    int b;
    for (int it = 0; it < 2; ++it) {
        cin >> b;
        while (b--) {
            int i;
            cin >> i;
            ok[i % d] = 1;
        }
    }
    forn(i, 0, d) {
        if (!ok[i]) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}