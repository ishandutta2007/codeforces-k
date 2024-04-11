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
#define uniq(v) vsort(v);(v).erase(unique(all(v)),(v).end())
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
constexpr ll mod=1000000007;
// constexpr ll mod=998244353;
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
template<class T,class E> ostream& operator<<(ostream& os,const map<T,E>& v){
  os<<"{";bool f=false;
  for(auto& x:v){if(f)os<<",";os<<x;f=true;}
  os<<"}";
  return os;
}
template<class T> inline bool chmax(T& a,T b){bool x=a<b;if(x)a=b;return x;}
template<class T> inline bool chmin(T& a,T b){bool x=a>b;if(x)a=b;return x;}
#ifdef DEBUG
void debugg(){cout<<endl;}
template<class T,class... Args>void debugg(const T& x,const Args&... args){cout<<" "<<x;debugg(args...);}
#define debug(...) cout<<__LINE__<<" ["<<#__VA_ARGS__<<"]:",debugg(__VA_ARGS__)
#else
#define debug(...) (void(0))
#endif

void startupcpp(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(15);
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
    For(i,size,n+1)modncrlistp[i]=modncrlistp[i-1]*i%mod;
    modncrlistm[n]=modinv(modncrlistp[n]);
    for(i=n;i>size;--i)modncrlistm[i-1]=modncrlistm[i]*i%mod;
  }
  return modncrlistp[n]*modncrlistm[r]%mod*modncrlistm[n-r]%mod;
}

ll modpow(ll a,ll n,ll m=mod){
  if(n<0)return 0;
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
namespace FastFactorize {
    ll mul(ll a, ll b, ll c) { return (__int128)a * b % c; }
    ll power(ll a, ll b, ll mod) {
        ll res = 1;
        while(b) {
            if(b & 1) { res = mul(res, a, mod); }
            a = mul(a, a, mod);
            b >>= 1;
        }
        return res;
    }
    bool isPrime(ll n) {
        if(!(n & 1) && n != 2) { return false; }
        ll d = n - 1;
        int s = __builtin_ctzll(d);
        d >>= s;
        vector<int> A;
        if(n <= 1000000000) {
            A = {2, 3, 5, 7};
        } else {
            A = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
        }
        for(int a : A) {
            ll p = power(a, d, n);
            int i = s;
            while(p != 1 && p != n - 1 && a % n && (--i)) { p = mul(p, p, n); }
            if(p != n - 1 && i != s) { return false; }
        }
        return true;
    }
    ll rho(ll n) {
        auto f = [&](ll a) { return mul(a, a, n) + 1; };
        ll x = 0, y = 0, p = 2, q;
        int i = 1, t = 0;
        while((t++) % 40 || gcd(p, n) == 1) {
            if(x == y) {
                x = ++i;
                y = f(x);
            }
            if(q = mul(p, abs(y - x), n)) { p = q; }
            x = f(x);
            y = f(f(y));
        }
        return gcd(p, n);
    }
    vector<ll> factor(ll n) {
        if(n == 1) { return {}; }
        if(isPrime(n)) { return {n}; }
        ll a = rho(n);
        assert(a != n && a != 1);
        auto l = factor(a), r = factor(n / a);
        l.insert(l.end(), r.begin(), r.end());
        return l;
    }
};
vec diviserlist(ll N){
  ll i;
  vec res;
  for(i=1;i*i<N;i++){
    if(N%i==0){
      res.eb(i);res.eb(N/i);
    }
  }
  if(i*i==N)res.eb(i);
  vsort(res);
  return res;
}
unordered_map<ll,ll> mp;
ll A,B,C,cnt[20000001];
int main(){
  startupcpp();
  for(ll i=2;i<20000001;++i){
    if(cnt[i])continue;
    for(ll j=i;j<20000001;j+=i)cnt[j]++;
  }
  int codeforces;cin>>codeforces;while(codeforces--){
  ll i,j;
  cin>>A>>B>>C;
  i=gcd(A,B);
  if(C%i){print(0);continue;}
  A/=i;B/=i;C/=i;
  ll ans=0;
  for(auto x:diviserlist(C)){
    if((C+x*B)%A)continue;
    j=(C+x*B)/A;
    if(j%x)continue;
    j/=x;
    if(j<20000001)i=cnt[j];
    else if(mp[j])i=mp[j];
    else{
      auto v=FastFactorize::factor(j);
      uniq(v);
      mp[j]=i=v.size();
    }
    ans+=1LL<<i;
  }
  print(ans);
}
}