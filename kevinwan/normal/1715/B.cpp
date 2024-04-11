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

string s[11];

void solve() {
  ll n,k,b,s;
  cin>>n>>k>>b>>s;
  ll ex=s-b*k;
  if(ex<0||ex>(k-1)*n){
    printf("-1\n");
    return;
  }
  for(int i=0;i<n;i++){
    if(ex>=(k-1)){
      printf("%lld ",k-1+(i==0?b*k:0));
      ex-=k-1;
    }
    else {
      printf("%lld ",ex+(i==0?b*k:0));
      ex=0;
    }
  }
  printf("\n");
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