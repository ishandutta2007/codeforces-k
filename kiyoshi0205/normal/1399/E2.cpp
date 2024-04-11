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

void topcoder(vector<int>& v){
  string s;
  while(1){
    cin>>s;
    int i=s[0]=='{',x=0;
    while(s[i]>='0'&&s[i]<='9'){
      x=x*10+s[i]-'0';
      ++i;
    }
    v.eb(x);
    if(s[i]=='}')break;
  }
}
void topcoder(string& s){
  string t;
  cin>>t;
  int i=1;
  while(t[i]!='"'){
    s+=t[i++];
  }
}

ll N,M,K,H,W,A,B,C,D;
string s,t;
vec vis;
pvec v,dv;
vector<vector<tdata>> g;
ll dfs(ll now,ll nowcost,ll c){
  ll cnt=0;
  if(vis[now])return 0;
  vis[now]=1;
  for(auto x:g[now]){
    cnt+=dfs(x.second.first,x.second.second,x.first);
  }
  (c?dv:v).eb(nowcost,cnt+!cnt);
  return cnt+!cnt;
}
int main(){
  startupcpp();
  int codeforces;cin>>codeforces;while(codeforces--){
  ll i,j=0;
  cin>>N>>M;
  vis=vec(N,0);
  g=vector<vector<tdata>>(N);
  rep1(H,N){
    cin>>i>>j>>K>>W;
    --i;--j;--W;
    g[i].eb(W,datas(j,K));
    g[j].eb(W,datas(i,K));
  }
  vis[0]=1;
  for(auto x:g[0])dfs(x.second.first,x.second.second,x.first);
  priority_queue<tdata> que,dque;
  ll S=0;
  for(auto x:v){
    que.push(tdata((x.first-x.first/2)*x.second,datas(x.first,x.second)));
    S+=x.first*x.second;
    // cout<<"{"<<x.first<<" "<<x.second<<"},";
  }
  que.push(tdata(-inf,datas(0,0)));
  for(auto x:dv){
    dque.push(tdata((x.first-x.first/2)*x.second,datas(x.first,x.second)));
    S+=x.first*x.second;
  }
  dque.push(tdata(-inf,datas(0,0)));
  // print("ok");
  ll ans=0,bfx=inf;
  while(S>M){
    auto x=que.top(),y=dque.top();
    if(S-M<=x.first){
      ++ans;
      break;
    }else if(S-M<=y.first){
      ans-=S-M+bfx<=y.first;
      ans+=2;
      break;
    }
    if(x.first*2<=y.first){
      S-=y.first;
      dque.pop();
      ans+=2;
      auto next=y.second;
      next.first>>=1;
      dque.push(tdata((next.first-next.first/2)*next.second,next));
    }else{
      S-=x.first;
      que.pop();
      auto next=x.second;
      next.first>>=1;
      que.push(tdata((next.first-next.first/2)*next.second,next));
      ans++;
      bfx=x.first;
    }
    // print(S<<" "<<ans);
  }
  vis.clear();
  g.clear();
  v.clear();
  dv.clear();
  print(ans);
  }return 0;
}