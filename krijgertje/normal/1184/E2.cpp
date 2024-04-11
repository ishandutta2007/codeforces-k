#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;  
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;
const int MAXLG=16;
const int MAXM=1000000;
struct E { int a,b,c,id; };
bool operator<(const E &p,const E &q) { return p.c<q.c; }

int n,m;
E e[MAXM];
vector<pair<int,int>> adj[MAXN];

bool used[MAXM];
int lim[MAXM];

int ufpar[MAXN],ufsz[MAXN];
int uffind(int a) { if(ufpar[a]==a) return a; return ufpar[a]=uffind(ufpar[a]); }
bool ufunite(int a,int b) { a=uffind(a),b=uffind(b); if(a==b) return false; if(ufsz[a]<ufsz[b]) swap(a,b); ufpar[b]=a,ufsz[a]+=ufsz[b]; return true; }

int par[MAXN];
int parcost[MAXN];
int dep[MAXN];
int up[MAXN][MAXLG+1];
int upcost[MAXN][MAXLG+1];

void dfsinit(int at) {
	dep[at]=par[at]==-1?0:1+dep[par[at]]; up[at][0]=par[at]==-1?at:par[at],upcost[at][0]=parcost[at]; REP(k,MAXLG) up[at][k+1]=up[up[at][k]][k],upcost[at][k+1]=max(upcost[at][k],upcost[up[at][k]][k]);
	REPSZ(i,adj[at]) {
		int to=adj[at][i].first,tocost=adj[at][i].second; if(to==par[at]) continue;
		//printf("%d is child of %d with cost %d\n",to+1,at+1,tocost);
		par[to]=at; parcost[to]=tocost; dfsinit(to);
	}
}

int lca(int a,int b) {
	if(dep[a]<dep[b]) swap(a,b);
	for(int k=MAXLG;k>=0;--k) if(dep[a]-(1<<k)>=dep[b]) a=up[a][k];
	for(int k=MAXLG;k>=0;--k) if(up[a][k]!=up[b][k]) a=up[a][k],b=up[b][k];
	return a==b?a:up[a][0];
}
int calcup(int a,int nsteps) {
	int ret=0;
	for(int k=MAXLG;k>=0;--k) if(nsteps&(1<<k)) ret=max(ret,upcost[a][k]),a=up[a][k];
	return ret;
}

void solve() {
	sort(e,e+m);
	REP(i,n) ufpar[i]=i,ufsz[i]=1;
	REP(i,m) used[i]=false;
	REP(i,m) {
		int a=e[i].a,b=e[i].b,c=e[i].c;
		if(!ufunite(a,b)) continue;
		used[e[i].id]=true; adj[a].PB(MP(b,c)); adj[b].PB(MP(a,c));
	}
	int nused=0; REP(i,m) if(used[i]) ++nused; assert(nused==n-1);
	
	par[0]=-1; parcost[0]=0; dfsinit(0);
	REP(i,m) if(!used[e[i].id]) {
		int a=e[i].a,b=e[i].b,c=lca(a,b);
		//printf("lca of %d and %d is %d\n",a+1,b+1,c+1);
		lim[e[i].id]=max(calcup(a,dep[a]-dep[c]),calcup(b,dep[b]-dep[c]));
	}
}


void run() {
	scanf("%d%d",&n,&m);
	REP(i,m) { int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b; e[i].a=a,e[i].b=b,e[i].c=c,e[i].id=i; }
	solve();
	REP(i,m) if(!used[i]) printf("%d\n",lim[i]);
}

int main() {
	run();
	return 0;
}