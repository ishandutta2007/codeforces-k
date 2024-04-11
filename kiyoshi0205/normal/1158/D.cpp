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

struct S{
  ll x,y,id;
};
int main(){
  startupcpp();
  ll i,N;
  cin>>N;
  vector<S> v(N);
  rep(i,N){
    cin>>v[i].x>>v[i].y;
    v[i].id=i+1;
  }
  vec ans;
  ans.reserve(N);
  sort(all(v),[](S l,S r){return (l.x!=r.x)?l.x>r.x:l.y<r.y;});
  ans.emplace_back(v.back().id);
  ll nowx=v.back().x,nowy=v.back().y;
  v.pop_back();
  string s;
  cin>>s;
  char bf='R';
  ll bfx=nowx-1,bfy=nowy-mod*2;
  for(auto x:s){
    if(bf==x){
      sort(all(v),[&](S l,S r){
        bool f1=(bfx-nowx)*(l.y-nowy)>(bfy-nowy)*(l.x-nowx);
        bool f2=(l.x-nowx)*(r.y-nowy)>(l.y-nowy)*(r.x-nowx);
        return f1==f2;
      });
    }else{
      sort(all(v),[&](S l,S r){
        bool f1=(bfx-nowx)*(l.y-nowy)>(bfy-nowy)*(l.x-nowx);
        bool f2=(l.x-nowx)*(r.y-nowy)>(l.y-nowy)*(r.x-nowx);
        return f1^f2;
      });
    }
    ans.emplace_back(v.back().id);
    bfx=nowx;bfy=nowy;
    nowx=v.back().x;nowy=v.back().y;
    v.pop_back();
    bf=x;
  }
  ans.emplace_back(v[0].id);
  output(ans);
}