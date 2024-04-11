#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/pb_ds/tag_and_trait.hpp>
// using namespace __gnu_pbds;
// #include<boost/multiprecision/cpp_int.hpp>
// namespace multiprecisioninteger = boost::multiprecision;
// using cint=multiprecisioninteger::cpp_int;
using namespace std;
using ll=long long;
#define double long double
using datas=pair<ll,ll>;
using ddatas=pair<double,double>;
using tdata=pair<ll,datas>;
using vec=vector<ll>;
using mat=vector<vec>;
using pvec=vector<datas>;
using pmat=vector<pvec>;
// using llset=tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;
#define For(i,a,b) for(i=a;i<(ll)b;++i)
#define bFor(i,b,a) for(i=b,--i;i>=(ll)a;--i)
#define rep(i,N) For(i,0,N)
#define rep1(i,N) For(i,1,N)
#define brep(i,N) bFor(i,N,0)
#define brep1(i,N) bFor(i,N,1)
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define vsort(v) sort(all(v))
#define vrsort(v) sort(allr(v))
#define endl "\n"
#define eb emplace_back
#define print(v) cout<<v<<endl
#define printyes cout<<"Yes"<<endl
#define printno cout<<"No"<<endl
#define printYES cout<<"YES"<<endl
#define printNO cout<<"NO"<<endl
#define output(v) do{bool f=0;for(auto outi:v){cout<<(f?" ":"")<<outi;f=1;}cout<<endl;}while(0)
#define matoutput(v) do{for(auto outimat:v)output(outimat);}while(0)
const ll mod=1000000007;
// const ll mod=998244353;
const ll inf=1LL<<60;
const double PI = acos(-1);
const double eps = 1e-9;
template<class T> inline bool chmax(T& a,T b){bool x=a<b;if(x)a=b;return x;} 
template<class T> inline bool chmin(T& a,T b){bool x=a>b;if(x)a=b;return x;} 
 
void startupcpp(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(15);
}
 
double distance(ddatas x,ddatas y){
  double a=x.first-y.first,b=x.second-y.second;
  return sqrt(a*a+b*b);
}
 
ll modinv(ll a) {
  ll b=mod,u=1,v=0,t;
  while(b){
    t=a/b;
    a-=t*b; swap(a,b);
    u-=t*v; swap(u,v);
  }
  return (u+mod)%mod;
}
 
ll moddevide(ll a,ll b){return (a*modinv(b))%mod;}
 
vec modncrlistp,modncrlistm;
 
ll modncr(ll n,ll r){
  if(n<r)return 0;
  ll i,size=modncrlistp.size();
  if(size<=n){
    modncrlistp.resize(n+1);
    modncrlistm.resize(n+1);
    if(!size){
      modncrlistp[0]=modncrlistm[0]=1;
      size++;
    }
    For(i,size,n+1){
      modncrlistp[i]=modncrlistp[i-1]*i%mod;
      modncrlistm[i]=modinv(modncrlistp[i]);
    }
  }
  return modncrlistp[n]*modncrlistm[r]%mod*modncrlistm[n-r]%mod;
}
 
ll modpow(ll a,ll n){
  ll res=1;
  while(n>0){
    if(n&1)res=res*a%mod;
    a=a*a%mod;
    n>>=1;
  }
  return res;
}
 
ll gcd(ll a,ll b){if(!b)return abs(a);return (a%b==0)?abs(b):gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
 
ll countdigits(ll n){
  ll ans=0;
  while(n){n/=10;ans++;}
  return ans;
}
 
ll sumdigits(ll n){
  ll ans=0;
  while(n){ans+=n%10;n/=10;}
  return ans;
}
struct unionfind{
  private:
  int maxN;
  vector<int> par,treesize;
  public:unionfind(int N) :maxN(N),par(N),treesize(N,1){
    int i;
    for(i=0;i<maxN;++i)par[i]=i;
  }
  int root(int x){
    if(par[x]==x)return x;
    int r=root(par[x]);
    if(par[x]!=r){
      treesize[r]+=treesize[x];
      treesize[x]=0;
      par[x]=r;
    }
    return r;
  }
  bool unite(int x,int y){
    int px=root(x);
    int py=root(y);
    if(px!=py){
      par[px]=py;
      treesize[py]+=treesize[px];
      treesize[px]=0;
    }
    return px!=py;
  }
  bool parcheck(int x,int y){
    return root(x)==root(y);
  }
  int size(int x){
    return treesize[root(x)];
  }
  void clear(){
    int i;
    for(i=0;i<maxN;++i){
      par[i]=i;
      treesize[i]=1;
    }
  }
};
int main(){
  // startupcpp();
  // int codeforces;cin>>codeforces;while(codeforces--){
  int i,j,N,M,anscnt=0;
  cin>>N>>M;
  vector<vector<int>> g(N),rg(N);
  vector<int> h(N,0),ans(N,0),rh(N,0);
  while(M--){
    cin>>i>>j;
    --i;--j;
    g[i].eb(j);
    rg[j].eb(i);
    ++h[j];
  }
  queue<int> que;
  rep(i,N){
    if(h[i]==0)que.push(i);
  }
  rep(i,N){
    if(que.empty()){
      print(-1);
      return 0;
    }
    int x=que.front();que.pop();
    for(int next:g[x]){
      --h[next];
      if(!h[next])que.push(next);
    }
  }
  rep(i,N){
    if(!h[i]&&!rh[i]){
      ans[i]=1;
    }
    que.push(i);
    while(!que.empty()){
      int x=que.front();que.pop();
      if(!chmax(h[x],1))continue;
      for(int next:g[x])que.push(next);
    }
    que.push(i);
    while(!que.empty()){
      int x=que.front();que.pop();
      if(!chmax(rh[x],1))continue;
      for(int next:rg[x])que.push(next);
    }
    anscnt+=ans[i];
  }
  print(anscnt);
  rep(i,N){
    if(ans[i])cout<<"A";
    else cout<<"E";
  }
  cout<<endl;
  // }return 0;
}