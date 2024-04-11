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
    int a,N; cin >> N;
    vi v(N), pos(N+1), g(N);
    for(int &i: v)cin >> i;
    FOR(i,N){
        cin >> a;
        pos[a] = i;
    }
    vi vis(N+1,0);
    int ans = 1;
    for(auto x: v){
        if(vis[x])continue;
        ans*=2;
        ans%=MOD;
        int c = x;
        do{
            vis[c] = 1;
            c = v[pos[c]];
        }while(c != x);
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