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

vector<int> fact;

int binpow(int x, int n, int MOD) {
    if (n == 0) return 1 % MOD;
    int res = 1;
    if (n % 2 == 1) res *= x;
    return (binpow((x * x) % MOD, n / 2, MOD) * res) % MOD;
}

void update(int x, int MOD) {
    fact.clear();
    fact.resize(x + 1, 1);
    for (int i = 2; i <= x; i++) fact[i] = (fact[i - 1] * i) % MOD;
}

int C(int n, int k, int MOD) {
    if (k > n) return 0;
    return (((fact[n] * binpow(fact[k], MOD - 2, MOD)) % MOD) * binpow(fact[n - k], MOD - 2, MOD)) % MOD;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    const int mod = 998244353;
    update(n + 22, mod);
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.pb(x);
        a.pb(-y);
    }
    sort(all(a), [&] (int x, int y) { return (abs(x) != abs(y) ? abs(x) < abs(y) : x > y); });
    int ans = 0, tmp = 0;
    for (auto x : a) {
        if (x > 0) tmp++;
        else {
            if (tmp >= k) ans = (ans + C(tmp - 1, k - 1, mod)) % mod;
            tmp--;
        }
    }
    cout << ans;
}