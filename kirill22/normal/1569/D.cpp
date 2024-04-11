#include<bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(const char& s) {
    string res = "'";
    res += s;
    res += "'";
    return res;
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (i) res += ", ";
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(a) (int) (a).size()
#define eb emplace_back
#define ld long double
#define ve vector
#define forn(i, n) for (int i = 0; i < n; i++)

int solve(set<int> a, ve<pii> A) {
    sort(all(A));
    //debug(a, A);
    int res = 0, i = 0;
    map<int, int> dp;
    while (i < sz(A)) {
        dp.clear();
        int j = i;
        auto it = a.lower_bound(A[i].fi);
        if (it == a.end()) j = sz(A) - 1;
        else {
            while (j + 1 < sz(A) && A[j + 1].fi < *it) j++;
        }
        for (int v = i; v <= j; v++) {
            res += v - i;
            res -= dp[A[v].se];
            dp[A[v].se]++;
        }
        i = j + 1;
    }
    //debug(res);
    return res;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    set<int> a, b;
    forn (i, n) {
        int x;
        cin >> x;
        a.insert(x);
    }
    forn (i, m) {
        int x;
        cin >> x;
        b.insert(x);
    }
    ve<pii> A, B;
    forn (i, k) {
        int x, y;
        cin >> x >> y;
        if (a.find(x) != a.end() && b.find(y) != b.end()) {
            
        } else if (a.find(x) != a.end()) {
            A.pb({y, x});
            //debug(i);
        } else {
            B.pb({x, y});
            //debug(i, 'F');
        }
    }
    cout << solve(a, B) + solve(b, A) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}