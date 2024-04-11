#include <bits/stdc++.h>
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

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
const ll mod = 1000000007;
ll inv[10000100];
ll FactorialInv[10000100];
ll Factorial[10000100];
ll beki(ll a, ll b){
    if(b == 0){
        return 1;
    }
    ll ans = beki(a, b / 2);
    ans = ans * ans % mod;
    if(b % 2 == 1){
        ans = ans * a % mod;
    }
    return ans;
}
void init_combination(){
    const int MAX = 10000002;
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
    ll ans = Factorial[a] * FactorialInv[b] % mod;
    ans = ans * FactorialInv[a - b] % mod;
    return ans;
}

ll One[1005];
ll Free[1005];
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    init_combination();
    ll N, M;
    cin >> N >> M;
    for(ll i = 1; i <= N; i++) {
        Free[i] = combination(M + i - 1, M);
        One[i] = Free[i] - 2 * Free[i-1] + Free[i-2];
        One[i] %= mod;
        One[i] += mod;
        One[i] %= mod;
        //cerr << i << " " << One[i] << " " << Free[i] << endl;
    }
    ll ans = 0;
    for(ll i = 1; i <= N; i++) {
        ans += (Free[i] - Free[i-1]) * Free[N - i + 1];
        ans %= mod;
        ans += mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}