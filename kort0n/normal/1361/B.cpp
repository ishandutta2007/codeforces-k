#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
const ll mod = 1000000007;
vector<ll> inv, FactorialInv, Factorial;
ll beki(ll a, ll b){
    ll ret = 1 % mod;
    a %= mod;
    while(b) {
        if(b & 1LL) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}
void init_combination(ll MAX){
    Factorial.resize(MAX + 1);
    FactorialInv.resize(MAX + 1);
    inv.resize(MAX + 1);
    Factorial[0] = 1;
    inv[0] = 1;
    for(int i = 1; i <= MAX; i++){
        Factorial[i] = Factorial[i - 1] * i % mod;
    }
    FactorialInv[MAX] = beki(Factorial[MAX], mod - 2);
    for(ll i = MAX - 1; i >= 0; i--) {
        FactorialInv[i] = FactorialInv[i+1] * (i+1) % mod;
    }
    for(int i = 1; i <= MAX; i++) {
        inv[i] = FactorialInv[i] * Factorial[i-1] % mod;
    }
}
ll combination(ll a, ll b){
    if((a == b) || (b == 0)){
        return 1;
    }
    if(a < b) return 0;
    if(b < 0) return 0;
    ll ans = Factorial[a] * FactorialInv[b] % mod;
    ans = ans * FactorialInv[a - b] % mod;
    return ans;
}

void solve() {
    ll N, p;
    cin >> N >> p;
    vector<l_l> v;
    vector<ll> k(N);
    for(int i = 0; i < N; i++) {
        cin >> k[i];
    }
    sort(k.begin(), k.end(), greater<ll>());
    if(p == 1) {
        cout << (N & 1) << endl;
        return;
    }
    for(auto now : k) {
        if(v.empty()) {
            v.push_back({now, 1});
            continue;
        }
        if(v.back().first != now) {
            v.push_back({now, 0});
        }
        v.back().second--;
        while(v.size()) {
            if(v.back().second == -p) {
                ll tmp = v.back().first;
                v.pop_back();
                if(v.back().first != tmp+1) {
                    v.push_back({tmp+1, 0});
                }
                v.back().second--;
            } else if(v.back().second == 0) {
                v.pop_back();
            } else {
                break;
            }
        }
    }
    ll ans = 0;
    for(auto tmp : v) {
        ans += beki(p, tmp.first) * tmp.second;
        ans %= mod;
        ans += mod;
        ans %= mod;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}