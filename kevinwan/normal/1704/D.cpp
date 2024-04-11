#include "bits/stdc++.h"
 
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using lll = __int128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
const int mn = 1e6+10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int iinf = 0x3f3f3f3f;
const ll mod = 998244353;

ll score[mn];
ll a[mn];
void solve() {
  int n,m;
  cin >> n >> m;
  ll mis=inf;
  for(int i=0;i<n;i++){
    for(int i=0;i<m;i++)cin>>a[i];
    ll s=0;
    for(int i=0;i<m;i++)s+=a[i]*i;
    score[i]=s;
    mis=min(mis,score[i]);
  }
  for(int i=0;i<n;i++)if(score[i]!=mis){
    printf("%d %lld\n",i+1,score[i]-mis);
  }
}
 
int main(){
  cin.tie(0);
  cin.sync_with_stdio(false);
  int tc;
  cin >> tc;
  for(int tcc=1;tcc<=tc;tcc++){
    //printf("Case #%d: ",tcc);
    solve();
  }
}