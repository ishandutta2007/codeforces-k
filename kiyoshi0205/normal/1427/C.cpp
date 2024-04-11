#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
#define print(x) cout<<x<<endl
#define printyes print("Yes")
#define printno print("No")
#define printYES print("YES")
#define printNO print("NO")
#define output(v) do{bool f=0;for(auto outi:v){cout<<(f?" ":"")<<outi;f=1;}cout<<endl;}while(0)
#define matoutput(v) do{for(auto outimat:v)output(outimat);}while(0)
const ll mod=1000000007;
// const ll mod=998244353;
const ll inf=1LL<<60;
const double PI=acos(-1);
const double eps=1e-9;
template<class T,class E> ostream& operator<<(ostream& os,pair<T,E>& p){return os<<"{"<<p.first<<","<<p.second<<"}";}
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

ll modinv(ll a,ll m=mod) {
  ll b=m,u=1,v=0,t;
  while(b){
    t=a/b;
    a-=t*b; swap(a,b);
    u-=t*v; swap(u,v);
  }
  return (u+m)%m;
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

ll modpow(ll a,ll n,ll m=mod){
  ll res=1;
  while(n>0){
    if(n&1)res=res*a%m;
    a=a*a%m;
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

template<typename T> struct segtree{
private:
  int N=1;
  T E;
  using func=function<T(T,T)>;
  func f,g;
  vector<T> tree;
public:
  segtree(vector<T>& v,T e,func Merge,func Act):E(e),f(Merge),g(Act){
    int i,K=v.size();
    while(N<K)N<<=1;
    tree.resize(N<<1);
    For(i,N,N+K)tree[i]=v[i-N];
    For(i,N+K,N<<1)tree[i]=E;
    brep1(i,N)tree[i]=f(tree[i<<1],tree[(i<<1)|1]);
  }
  segtree(vector<T>& v,T e,func Merge){*this=segtree(v,e,Merge,Merge);};
  segtree(int N,T e,func F){
    vector<T> res(N,e);
    *this=segtree(res,e,F);
  }
  void action(int i,T a){
    if((i<0)|(i>=N))return;
    i+=N;
    tree[i]=g(tree[i],a);
    while(i>1){
      i>>=1;
      tree[i]=f(tree[i<<1],tree[(i<<1)|1]);
    }
  }
  void input(int i,T a){
    if((i<0)|(i>=N))return;
    tree[i+=N]=a;
    while(i>1){
      i>>=1;
      tree[i]=f(tree[i<<1],tree[(i<<1)|1]);
    }
  }
  T queli(int a,int b){
    if((a>=b)|(a<0)|(b<=0)|(a>=N)|(b>N))return E;
    T l(E),r(E);
    for(a+=N,b+=N;a<b;a>>=1,b>>=1){
      if(a&1)l=f(l,tree[a++]);
      if(b&1)r=f(tree[--b],r);
    }
    return f(l,r);
  }
};
ll N,M,K,H,W,A,B,C,D;
string s,t;
ll ans;
int main(){
  startupcpp();
  // int codeforces;cin>>codeforces;while(codeforces--){
  ll i,j;
  cin>>K>>N;K=K*2+2;
  vec dp(N+1,0),Lazy(N+2,0);
  vector<tdata> v(N+1);
  v[0]=tdata(0,datas(0,0));
  rep(i,N){
    cin>>v[i+1].first>>A>>B;
    --A;--B;
    v[i+1].second=datas(A,B);
    if(A+B>v[i+1].first){
      --N;--i;
    }
  }
  // out/put(v);
  rep(i,N+1){
    ll x=max(dp[i],Lazy[i]);
    For(j,i+1,i+K){
      if(j>N)break;
      if(v[j].first-v[i].first>=abs(v[i].second.first-v[j].second.first)+abs(v[i].second.second-v[j].second.second)){
        chmax(dp[j],x+1);
      }
    }
    chmax(Lazy[j],x+1);
    if(i)chmax(ans,x);
    chmax(Lazy[i+1],Lazy[i]);
    // output(dp);
    // output(Lazy);
    // print("");
  }
  print(ans);
}