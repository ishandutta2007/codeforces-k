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
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()

void solve() {
    int n, k, l;
    cin >> n >> k >> l;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> p(2 * k);
    for (int i = 0; i <= k; i++) p[i] = i;
    for (int i = k + 1; i < 2 * k; i++) p[i] = 2 * k - i;
    vector<bool> dp(2 * k, true);
    for (int i = 0; i < n; i++) {
        int x = a[i];
        vector<bool> dp2(2 * k, false);
        for (int j = 0; j < 2 * k; j++) {
            if (a[i] + p[j] > l) continue;
            if (dp[(j - 1 + 2 * k) % (2 * k)] == true) dp2[j] = true;
        }
        dp = dp2;
        bool f = false;
        for (auto x : dp) f = f | x;
        for (int j = 0; j < 2 * k; j++) {
            if (dp[j] == true) {
                for (int j2 = 1; j2 < 2 * k; j2++) {
                    if (x + p[(j + j2) % (2 * k)] <= l) {
                        dp[(j + j2) % (2 * k)] = true;
                    }
                    else break;
                }
            }
        }
        if (!f) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        solve();
    }
}