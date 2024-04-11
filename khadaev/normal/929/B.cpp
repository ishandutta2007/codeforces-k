#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n) - 1; i >= (int)(a); --i)
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

template<typename T, typename S>
istream& operator>> (istream& in, pair<S, T>& p) {
    in >> p.fs >> p.sn;
    return in;
}
template<typename T, typename S>
ostream& operator<< (ostream& out, pair<S, T>& p) {
    out << p.fs << ' ' << p.sn << ' ';
    return out;
}

template<typename T>
istream& operator>> (istream& in, vector<T>& v) {
    for (T& x : v) in >> x;
    return in;
}
template<typename T>
ostream& operator<< (ostream& out, vector<T>& v) {
    for (T& x : v) out << x << ' ';
    return out;
}

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;
const int LEN = 12;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n, k;
    cin >> n >> k;
    vector<string> in(n);
    cin >> in;
    vector<vector<pair<int, int>>> free(3);
    forn(i, 0, n) forn(j, 0, LEN) {
        if (in[i][j] != '.') continue;
        int cnt = 0;
        if (j != 0 && in[i][j - 1] == 'S') ++cnt;
        if (j != LEN - 1 && in[i][j + 1] == 'S') ++cnt;
        free[cnt].eb(i, j);
    }
    for (auto& v : free)
        for (auto& [i, j] : v) {
            if (k-- <= 0) break;
            in[i][j] = 'x';
        }
    int sum = 0;
    forn(i, 0, n) forn(j, 0, LEN) {
        if (in[i][j] != 'S') continue;
        if (j != 0 && in[i][j - 1] != '.' && in[i][j - 1] != '-') ++sum;
        if (j != LEN - 1 && in[i][j + 1] != '.' && in[i][j + 1] != '-') ++sum;
    }
    cout << sum << '\n';
    for (auto& s : in) cout << s << '\n';
}