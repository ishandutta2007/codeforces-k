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

string to_string(const char* s) {
    return to_string((string) s);
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

void solve() {
    //int n;
    //cin >> n;
    //vector<int> a(n);
    //for (int i = 0; i < n; i++) cin >> a[i];
    int a, b, n;
    cin >> a >> b >> n;
    int ans = 0;
    while (a <= n && b <= n) {
        if (a > b) swap(a, b);
        a += b;
        ans++;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if (n % 2 == 0) {
        set<pii> ans;
        for (int i = 0; i < n; i++) {
            int x = i * 2, y = 0;
            ans.insert({x, y});
            ans.insert({x - 1, y});
            ans.insert({x, y - 1});
            ans.insert({x, y + 1});
            ans.insert({x + 1, y});
        }
        for (int i = 0; i < n; i += 2) {
            int x = i * 2, y = 0;
            ans.insert({x, y + 2});
            ans.insert({x + 1, y + 2});
            ans.insert({x + 2, y + 2});
            ans.insert({x, y - 2});
            ans.insert({x + 1, y - 2});
            ans.insert({x + 2, y - 2});
        }
        for (int i = 0; i >= -4; i--) ans.insert({-2, i});
        for (int i = -2; i <= n * 2; i++) ans.insert({i, -4});
        for (int i = 0; i >= -4; i--) ans.insert({2 * n, i});
        cout << ans.size() << endl;
        for (auto x : ans) {
            cout << x.fi << " " << x.se << endl;
        }
        return 0;
    }
    set<pii> ans;
    for (int i = 0; i < n; i++) {
        int x = i * 2, y = 0;
        ans.insert({x, y});
        ans.insert({x - 1, y});
        ans.insert({x, y - 1});
        ans.insert({x, y + 1});
        ans.insert({x + 1, y});
    }
    for (int i = 0; i < n - 1; i += 2) {
        int x = i * 2, y = 0;
        ans.insert({x, y + 2});
        ans.insert({x + 1, y + 2});
        ans.insert({x + 2, y + 2});
        ans.insert({x, y - 2});
        ans.insert({x + 1, y - 2});
        ans.insert({x + 2, y - 2});
    }
    for (int i = 0; i >= -4; i--) ans.insert({-2, i});
    for (int i = -2; i <= n * 2 - 2; i++) ans.insert({i, -4});
    for (int i = 0; i >= -4; i--) ans.insert({2 * n - 2, i});
    ans.insert({(n - 1) * 2, 2});
    ans.insert({(n - 1) * 2 + 1, 2});
    ans.insert({(n - 1) * 2 + 2, 2});
    ans.insert({(n - 1) * 2 + 2, 1});
    ans.insert({(n - 1) * 2 + 2, 0});
    cout << ans.size() << endl;
    for (auto x : ans) {
        cout << x.fi << " " << x.se << endl;
    }
}