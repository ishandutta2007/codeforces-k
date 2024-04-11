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
#define uniq(v) (v).erase(unique(all(v)),(v).end())
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
template<class T,class E> ostream& operator<<(ostream& os,const pair<T,E>& p){return os<<"("<<p.first<<","<<p.second<<")";}
template<class T> ostream& operator<<(ostream& os,const vector<T>& v){
  os<<"{";ll i;
  rep(i,v.size()){
    if(i)os<<",";
    os<<v[i];
  }
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

ll N,M,K,H,W,A,B,C,D;
string s,t;
ll ans;
int main(){
  startupcpp();
  int codeforces;cin>>codeforces;while(codeforces--){
  ll i,j;
  cin>>N;
  vec v(N);
  rep(i,N)cin>>v[i];
  {
    vec cnt(N+1,0);
    rep(i,N)cnt[--v[i]]++;
    // debug(cnt);
    vrsort(cnt);
    if(N-cnt[0]+1<cnt[0]){
      print(-1);
      continue;
    }
  }
  vec cnt(N,0);
  pvec ablis;
  j=v[0];A=ans=0;
  debug(v);
  rep1(i,N){
    if(v[i-1]==v[i]){
      ++ans;
      if(j==v[i]){++cnt[j];++A;}
      else ablis.eb(j,v[i]);
      j=v[i];
    }
  }
  if(j==v[N-1]){++cnt[j];++A;}
  else ablis.eb(j,v[N-1]);
  debug(cnt,ablis);
  ll x=max_element(all(cnt))-cnt.begin();
  K=cnt[x]-(A-cnt[x])-1;
  for(auto ab:ablis){
    if(ab.first==x||ab.second==x)continue;
    K--;
  }
  print(ans+max(K,0LL));
}
}