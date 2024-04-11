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
using datas=pair<ll,ll>;
using ddatas=pair<long double,long double>;
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
#define uniq(v) vsort(v),(v).erase(unique(all(v)),(v).end())
#define endl "\n"
#define popcount __builtin_popcountll
#define eb emplace_back
#define print(x) cout<<x<<endl
#define printyes print("Yes")
#define printno print("No")
#define printYES print("YES")
#define printNO print("NO")
#define output(v) do{bool f=0;for(auto outi:v){cout<<(f?" ":"")<<outi;f=1;}cout<<endl;}while(0)
#define matoutput(v) do{for(auto outimat:v)output(outimat);}while(0)
// constexpr ll mod=1000000007;
constexpr ll mod=998244353;
constexpr ll inf=1LL<<60;
constexpr long double eps=1e-9;
const long double PI=acosl(-1);
template<class T,class E> ostream& operator<<(ostream& os,const pair<T,E>& p){return os<<"("<<p.first<<","<<p.second<<")";}
template<class T> ostream& operator<<(ostream& os,const vector<T>& v){
  os<<"{";bool f=false;
  for(auto& x:v){if(f)os<<",";os<<x;f=true;}
  os<<"}";
  return os;
}
template<class T> ostream& operator<<(ostream& os,const set<T>& v){
  os<<"{";bool f=false;
  for(auto& x:v){if(f)os<<",";os<<x;f=true;}
  os<<"}";
  return os;
}
template<class T> ostream& operator<<(ostream& os,const multiset<T>& v){
  os<<"{";bool f=false;
  for(auto& x:v){if(f)os<<",";os<<x;f=true;}
  os<<"}";
  return os;
}
template<class T,class E> ostream& operator<<(ostream& os,const map<T,E>& v){
  os<<"{";bool f=false;
  for(auto& x:v){if(f)os<<",";os<<x;f=true;}
  os<<"}";
  return os;
}
template<class T> inline bool chmax(T& a,const T b){bool x=a<b;if(x)a=b;return x;}
template<class T> inline bool chmin(T& a,const T b){bool x=a>b;if(x)a=b;return x;}
#ifdef DEBUG
void debugg(){cout<<endl;}
template<class T,class... Args>void debugg(const T& x,const Args&... args){cout<<" "<<x;debugg(args...);}
#define debug(...) cout<<__LINE__<<" ["<<#__VA_ARGS__<<"]:",debugg(__VA_ARGS__)
#else
#define debug(...) (void(0))
#endif

inline void startupcpp(void) noexcept{
  cin.tie(0)->sync_with_stdio(0);
  cout<<fixed<<setprecision(15);
}

ll modinv(ll a,const ll m=mod) noexcept{
  ll b=m,u=1,v=0,t;
  while(b){
    t=a/b;
    a-=t*b; swap(a,b);
    u-=t*v; swap(u,v);
  }
  return (u+m)%m;
}

ll moddevide(const ll a,const ll b) noexcept{return (a*modinv(b))%mod;}

vec modncrlistp,modncrlistm;

ll modncr(const ll n,const ll r) noexcept{
  if(n<r||r<0)return 0;
  ll i,size=modncrlistp.size();
  if(size<=n){
    modncrlistp.resize(n+1);
    modncrlistm.resize(n+1);
    if(!size){
      modncrlistp[0]=modncrlistm[0]=1;
      size++;
    }
    For(i,size,n+1)modncrlistp[i]=modncrlistp[i-1]*i%mod;
    modncrlistm[n]=modinv(modncrlistp[n]);
    for(i=n;i>size;--i)modncrlistm[i-1]=modncrlistm[i]*i%mod;
  }
  return modncrlistp[n]*modncrlistm[r]%mod*modncrlistm[n-r]%mod;
}

ll modpow(ll a,ll n,const ll m=mod){
  if(n<0)return 0;
  ll res=1;
  while(n>0){
    if(n&1)res=res*a%m;
    a=a*a%m;
    n>>=1;
  }
  return res;
}

constexpr ll gcd(const ll a,const ll b) noexcept{return (!b)?abs(a):(a%b==0)?abs(b):gcd(b,a%b);}
constexpr ll lcm(const ll a,const ll b) noexcept{return a/gcd(a,b)*b;}

// #include<atcoder/all>
// using mint=atcoder::modint998244353;
// void operator>>(istream& is,mint& v){long long x;is>>x;v=x;}
// ostream& operator<<(ostream& os,const mint& v){return os<<v.val();}
template<typename T> struct segtree{
private:
  int N=1;
  T E;
  using func=function<T(T,T)>;
  func f,g;
  vector<T> tree;
public:
  segtree(){}
  segtree(const vector<T>& v,T e,func Merge,func Act):E(e),f(Merge),g(Act){
    int i,K=v.size();
    while(N<K)N<<=1;
    tree.resize(N<<1);
    For(i,N,N+K)tree[i]=v[i-N];
    For(i,N+K,N<<1)tree[i]=E;
    brep1(i,N)tree[i]=f(tree[i<<1],tree[(i<<1)|1]);
  }
  segtree(const vector<T>& v,T e,func Merge){*this=segtree(v,e,Merge,Merge);};
  segtree(int N,T e,func F){
    vector<T> res(N,e);
    *this=segtree(res,e,F);
  }
  void action(int i,T a){
    if((i<0)|(i>=N))return;
    i|=N;
    tree[i]=g(tree[i],a);
    while(i>1){
      i>>=1;
      tree[i]=f(tree[i<<1],tree[(i<<1)|1]);
    }
  }
  void set(int i,T a){
    if((i<0)|(i>=N))return;
    tree[i|=N]=a;
    while(i>1){
      i>>=1;
      tree[i]=f(tree[i<<1],tree[(i<<1)|1]);
    }
  }
  T prod(int a,int b){
    if((a>=b)|(a<0)|(b<=0)|(a>=N)|(b>N))return E;
    T l(E),r(E);
    for(a|=N,b+=N;a<b;a>>=1,b>>=1){
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
  ll i,j,Q;
  cin>>N>>Q;
  segtree<ll> segx(vec(N,0),inf,[](ll a,ll b){return min(a,b);});
  segtree<ll> segy(vec(N,0),inf,[](ll a,ll b){return min(a,b);});
  while(Q--){
    ll t;
    cin>>t;
    if(t==1){
      cin>>i>>j;
      --i;--j;
      segx.set(i,segx.prod(i,i+1)+1);
      segy.set(j,segy.prod(j,j+1)+1);
    }
    if(t==2){
      cin>>i>>j;
      --i;--j;
      segx.set(i,segx.prod(i,i+1)-1);
      segy.set(j,segy.prod(j,j+1)-1);
    }
    if(t==3){
      ll a,b,c,d;
      cin>>a>>b>>c>>d;
      --a;--b;
      if(segx.prod(a,c)||segy.prod(b,d))printyes;
      else printno;
    }
  }
// }
}