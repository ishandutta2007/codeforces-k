#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ps push
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) int((x).size())
template<typename T>
using pq = priority_queue<T>;
#define FOR(i,k) for(int i = 0; i < (k); i++)
#define foll(i,k) for(long long i = 0; i < (k); i++)
#define FORr(i,k) for(int i = (k)-1; i >= 0; i--)
#define folr(i,k) for(long long i = (k)-1; i >= 0; i--)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD =   1000000007;//   998244353;

void solve(){
    ll N; cin >> N;
    vll v(N+2);
    FOR(i,N)cin >> v[i+1]; v[0] = v[N+1] = 0;
    ll ans = 0;
    for(int i = 1; i < N+1; i++){
        if(v[i] > max(v[i-1],v[i+1])){
            ans+=v[i]-max(v[i-1],v[i+1]);
            v[i] = max(v[i-1],v[i+1]);
        }
    }
    for(int i = 1; i < N+2; i++){
        ans += abs(v[i]-v[i-1]);

    }
    cout << ans << endl;
    return;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(NULL);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}