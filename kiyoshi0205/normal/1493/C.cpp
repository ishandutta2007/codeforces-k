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
}

ll N,K;
string s,t;
int main(){
  startupcpp();
  int codeforces;cin>>codeforces;while(codeforces--){
  ll i,j,sum=0;
  cin>>N>>K>>s;
  if(N%K){
    print(-1);
    continue;
  }
  vec mandatory(26,0);
  t="";
  rep(i,N){
    --sum;
    if(--mandatory[s[i]-'a']<0){
      mandatory[s[i]-'a']+=K;
      sum+=K;
    }
    if(sum>N-i-1){
      assert(mandatory[s[i]-'a']==K-1);
      sum-=K-1;
      mandatory[s[i]-'a']=0;
      ll loop;
      rep(loop,N+1){
        For(j,s[i]-'a'+1,26)if(mandatory[j])break;
        if(j<26){t+='a'+j;mandatory[j]--;--sum;break;}
        --i;
        assert(i>=0);
        t.pop_back();
        ++sum;
        if(++mandatory[s[i]-'a']==K){
          mandatory[s[i]-'a']-=K;sum-=K;
          if(s[i]!='z'){
            t+=s[i]+1;
            --sum;
            if(--mandatory[s[i]-'a'+1]<0){
              mandatory[s[i]-'a'+1]+=K;
              sum+=K;
            }
            break;
          }
        }
      }
      assert(loop<=N);
      break;
    }
    t+=s[i];
  }
  assert(sum>=0);
  ll tmp=sum+t.size();
  mandatory[0]+=N-tmp;
  rep(i,26)rep(j,mandatory[i])t+='a'+i;
  print(t);
}
}