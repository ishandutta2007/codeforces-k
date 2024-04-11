#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N;
set<int> E[202020];
int level[202020];
int F[50];
int U,V;

int dfs2(int cur,int pre,int L) {
	int C=1;
	FORR(e,E[cur]) if(e!=pre) C+=dfs2(e,cur,L);
	
	if(C==F[L-1]) U=cur,V=pre;
	if(C==F[L-2]) V=cur,U=pre;
	return C;
}


int dfs(int cur,int L) {
	if(L<=3) return 1;
	U=V=-1;
	dfs2(cur,cur,L);
	
	if(U==-1) {
		return 0;
	}
	E[U].erase(V);
	E[V].erase(U);
	int x=U,y=V;
	return dfs(x,L-1)&&dfs(y,L-2);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].insert(y-1);
		E[y-1].insert(x-1);
	}
	
	F[0]=F[1]=1;
	level[1]=1;
	for(i=2;i<=40;i++) {
		F[i]=F[i-1]+F[i-2];
		if(F[i]>N) break;
		level[F[i]]=i;
	}
	
	
	if(level[N]&&dfs(0,level[N])) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}