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
void debugg(){cerr<<endl;}
template<class T,class... Args>void debugg(const T& x,const Args&... args){cerr<<" "<<x;debugg(args...);}
#define debug(...) cerr<<__LINE__<<" ["<<#__VA_ARGS__<<"]:",debugg(__VA_ARGS__)
#else
#define debug(...) (void(0))
#endif

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
template<class Cap> struct mf_graph{
public:
  mf_graph():_n(0){}
  mf_graph(int n):_n(n),g(n){}

  int add_edge(int from,int to,Cap cap){
    assert(0<=from&&from<_n);
    assert(0<=to&&to<_n);
    assert(0<=cap);
    int m=int(pos.size());
    pos.push_back({from,int(g[from].size())});
    int from_id=int(g[from].size());
    int to_id=int(g[to].size())+int(from==to);
    g[from].push_back(_edge{to,to_id,cap});
    g[to].push_back(_edge{from,from_id,0});
    return m;
  }

  struct edge {
    int from,to;
    Cap cap,flow;
  };

  edge get_edge(int i){
    assert(0<=i&&i<int(pos.size()));
    auto _e=g[pos[i].first][pos[i].second];
    auto _re=g[_e.to][_e.rev];
    return edge{pos[i].first,_e.to,_e.cap+_re.cap,_re.cap};
  }
  vector<edge> edges(){
    vector<edge> result;
    for(int i=0;i<int(pos.size());i++){
      result.push_back(get_edge(i));
    }
    return result;
  }
  void change_edge(int i,Cap new_cap,Cap new_flow){
    assert(0<=i&&i<int(pos.size()));
    assert(0<=new_flow&&new_flow<=new_cap);
    auto&_e=g[pos[i].first][pos[i].second];
    auto&_re=g[_e.to][_e.rev];
    _e.cap=new_cap-new_flow;
    _re.cap=new_flow;
  }

  Cap flow(int s,int t){
    return flow(s,t,numeric_limits<Cap>::max());
  }
  Cap flow(int s,int t,Cap flow_limit){
    assert(0<=s&&s<_n);
    assert(0<=t&&t<_n);
    assert(s!=t);

    vector<int> level(_n),iter(_n);
    simple_queue<int> que;

    auto bfs=[&](){
      fill(level.begin(),level.end(),-1);
      level[s]=0;
      que.clear();
      que.push(s);
      while(!que.empty()){
        int v=que.front();
        que.pop();
        for(auto e:g[v]){
          if(e.cap==0||level[e.to]>=0)continue;
          level[e.to]=level[v]+1;
          if(e.to==t)return;
          que.push(e.to);
        }
      }
    };
    auto dfs=[&](auto self,int v,Cap up){
      if(v==s)return up;
      Cap res=0;
      int level_v=level[v];
      for(int&i=iter[v]; i<int(g[v].size()); i++){
        _edge&e=g[v][i];
        if(level_v<=level[e.to]||g[e.to][e.rev].cap==0)continue;
        Cap d=self(self,e.to,min(up-res,g[e.to][e.rev].cap));
        if(d<=0)continue;
        g[v][i].cap+=d;
        g[e.to][e.rev].cap-=d;
        res+=d;
        if(res==up)break;
      }
      return res;
    };

    Cap flow=0;
    while(flow<flow_limit){
      bfs();
      if(level[t]==-1)break;
      fill(iter.begin(),iter.end(),0);
      while(flow<flow_limit){
        Cap f=dfs(dfs,t,flow_limit-flow);
        if(!f)break;
        flow+=f;
      }
    }
    return flow;
  }

  vector<bool> min_cut(int s){
    vector<bool> visited(_n);
    simple_queue<int> que;
    que.push(s);
    while(!que.empty()){
      int p=que.front();
      que.pop();
      visited[p]=true;
      for(auto e:g[p]){
        if(e.cap&&!visited[e.to]){
          visited[e.to]=true;
          que.push(e.to);
        }
      }
    }
    return visited;
  }
private:
  int _n;
  struct _edge{
    int to,rev;
    Cap cap;
  };
  vector<pair<int,int>> pos;
  vector<vector<_edge>> g;
  template<class T>struct simple_queue{
    vector<T> payload;
    int pos=0;
    void reserve(int n){payload.reserve(n);}
    int size() const{return int(payload.size())-pos;}
    bool empty() const{return pos==int(payload.size());}
    void push(const T& t){payload.push_back(t);}
    T& front(){return payload[pos];}
    void clear(){
      payload.clear();
      pos=0;
    }
    void pop(){++pos;}
  };
};
struct scc_graph{
public:
  scc_graph(int n):_n(n){}
  scc_graph(vector<vector<int>> g):_n(g.size()){
    for(int i=0;i<_n;++i)for(auto& x:g[i])add_edge(i,x);
    scc_ids();
  }
  scc_graph(vector<vector<long long>> g):_n(g.size()){
    for(int i=0;i<_n;++i)for(auto& x:g[i])add_edge(i,x);
    scc_ids();
  }

  void add_edge(int from,int to){
    assert(0<=from&&from<_n);
    assert(0<=to&&to<_n);
    edges.push_back({from,{to}});
  }
  void add_clause(int i,bool f,int j,bool g){
    assert(0<=i&&i*2<_n);
    assert(0<=j&&j*2<_n);
    add_edge(i<<1|!f,j<<1|g);
    add_edge(j<<1|!g,i<<1|f);
  }
  //n must be *2
  vector<bool> solve_twosat(){
    if(!group_num)scc_ids();
    int m=_n>>1;
    vector<bool> answer(m);
    for(int i=0;i<m;++i){
      if(ids[i<<1]==ids[i<<1|1])return{};
      answer[i]=ids[i<<1]<ids[i<<1|1];
    }
    return answer;
  }

  vector<vector<int>> scc(){
    if(!group_num)scc_ids();
    vector<int> counts(group_num);
    for(auto& x:ids)counts[x]++;
    vector<vector<int>> groups(group_num);
    for(int i=0;i<group_num;++i)groups[i].reserve(counts[i]);
    for(int i=0;i<_n;++i)groups[ids[i]].push_back(i);
    return groups;
  }
  int size(){return group_num;}
  int operator[](int k) const{return ids[k];}
private:
  int _n,group_num=0;
  struct edge{
    int to;
  };
  struct csr{
    vector<int> start;
    vector<edge> elist;
    csr(int n,const vector<pair<int,edge>>& edges):start(n+1),elist(edges.size()){
      for(auto& e:edges)++start[e.first+1];
      for(int i=0;i<n;++i)start[i+1]+=start[i];
      auto counter=start;
      for(auto& e:edges)elist[counter[e.first]++]=e.second;
    }
  };
  vector<int> ids;
  vector<pair<int,edge>> edges;
  // @return pair of(# of scc,scc id)
  void scc_ids(){
    auto g=csr(_n,edges);
    int now_ord=0;
    vector<int> visited,low(_n),ord(_n,-1);
    ids.resize(_n);
    visited.reserve(_n);
    auto dfs=[&](auto self,int v)-> void{
      low[v]=ord[v]=now_ord++;
      visited.push_back(v);
      for(int i=g.start[v];i<g.start[v+1];++i){
        auto to=g.elist[i].to;
        if(ord[to]==-1){
          self(self,to);
          low[v]=min(low[v],low[to]);
        }else{
          low[v]=min(low[v],ord[to]);
        }
      }
      if(low[v]==ord[v]){
        while(true){
          int u=visited.back();
          visited.pop_back();
          ord[u]=_n;
          ids[u]=group_num;
          if(u==v)break;
        }
        group_num++;
      }
    };
    for(int i=0;i<_n;++i){
      if(ord[i]==-1)dfs(dfs,i);
    }
    for(auto& x:ids){
      x=group_num-1-x;
    }
  }
};
ll N,M,K,H,W,A,B,C,D;
string s,t;
ll ans;
int main(){
  startupcpp();
  int codeforces;cin>>codeforces;while(codeforces--){
  ll i,j;
  cin>>N>>M;
  mat g(N,vec(M));
  scc_graph gl(N*M*2);
  rep(i,N)rep(j,M){
    cin>>g[i][j];
    if(i){
      if(g[i][j]==g[i-1][j]){
        gl.add_clause(i*M+j,true,(i-1)*M+j,true);
        gl.add_clause(i*M+j,false,(i-1)*M+j,false);
      }
      if(g[i][j]+1==g[i-1][j])gl.add_clause(i*M+j,false,(i-1)*M+j,true);
      if(g[i][j]==g[i-1][j]+1)gl.add_clause(i*M+j,true,(i-1)*M+j,false);
    }
    if(j){
      if(g[i][j]==g[i][j-1]){
        gl.add_clause(i*M+j,true,i*M+j-1,true);
        gl.add_clause(i*M+j,false,i*M+j-1,false);
      }
      if(g[i][j]+1==g[i][j-1])gl.add_clause(i*M+j,false,i*M+j-1,true);
      if(g[i][j]==g[i][j-1]+1)gl.add_clause(i*M+j,true,i*M+j-1,false);
    }
  }
  auto x=gl.solve_twosat();
  assert(x.size());
  rep(i,N)rep(j,M)if(x[i*M+j])g[i][j]++;
  matoutput(g);
}
}