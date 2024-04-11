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
#define eb emplace_back
#define ld long double


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, r1, r2, r3, d;
    cin >> n >> r1 >> r2 >> r3 >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> d1(n), d2(n);
    for (int i = 0; i < n; i++) {
        d1[i] = min(r2 + r1, a[i] * r1 + 2 * r1);
        d2[i] = a[i] * r1 + r3;
    }
    int ans = 1e18;
    int tmp = 0, r = n - 1;
    for (auto x : d2) tmp += x;
    tmp += (n - 1) * d;
    ans = min(ans, tmp);
    vector<int> dp(n, 1e18), dp2(n, 1e18);
    dp[0] = d1[0];
    dp2[0] = d2[0];
    for (int i = 1; i < n; i++) {
        if (i == n - 1) {
            dp[i] = dp2[i - 1] + d + d1[i] + 2 * d;
            dp2[i] = dp2[i - 1] + d + d2[i];
            dp2[i] = min(dp2[i], dp[i - 1] + min(d1[i] + d + d + d, d2[i] + d + d));
            continue;
        }
        dp[i] = dp2[i - 1] + d + d1[i];
        dp2[i] = dp2[i - 1] + d + d2[i];
        dp2[i] = min(dp2[i], dp[i - 1] + d + d + d + min(d1[i], d2[i]));
    }
    //debug(dp, dp2);
    cout << min(dp[n - 1], dp2[n - 1]);
}