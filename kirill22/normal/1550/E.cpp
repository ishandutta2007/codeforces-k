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

signed main() {
    //
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    //
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int l = 0, r = n + 1;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        int mx = (1 << k);
        ve<int> can(mx);
        ve<queue<pii>> go(k);
        auto upd = [&] (int msk, int id) {
            if (can[msk]) return;
            can[msk] = 1;
            forn (j, k) {
                if ((msk & (1 << j)) == 0) {
                    go[j].push({msk, id});
                }
            }
        };
        upd(0, -1);
        ve<int> tmp(k);
        forn (i, m - 1) if (s[i] != '?') tmp[s[i] - 'a']++;
        for (int i = m - 1; i < n; i++) {
            //if (m == 6) debug(can);
            if (s[i] != '?') tmp[s[i] - 'a']++;
            if (i >= m && s[i - m] != '?') tmp[s[i - m] - 'a']--;
            int cnt = 0, j = 0;
            forn (v, k) if (tmp[v] > 0) cnt++, j = v;
            ve<int> U;
            if (cnt == 0) {
                U.resize(k);
                iota(all(U), 0);
            }
            else if (cnt == 1) {
                U = {j};
            }
            for (auto j : U) {
                while (sz(go[j]) && go[j].front().se <= i - m) {
                    auto v = go[j].front();
                    go[j].pop();
                    upd(v.fi | (1 << j), i);
                }
            }
        }
        if (can[mx - 1]) l = m;
        else r = m;
    }
    cout << l;
}