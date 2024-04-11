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

int T,N;
vector<int> E[303030];
int dia[303030];

int dfs(int cur,int pre,int d) {
	vector<int> L;
	L.push_back(d);
	L.push_back(d);
	FORR(e,E[cur]) if(e!=pre) {
		L.push_back(dfs(e,cur,d+1));
	}
	sort(ALL(L));
	reverse(ALL(L));
	if(L[1]>0) {
		dia[L[1]-1]=max(dia[L[1]-1],L[0]+L[1]-2*d);
	}
	return L[0];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N+2) {
			E[i].clear();
			dia[i]=0;
		}
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		
		int ma=dfs(0,0,0);
		for(i=N-1;i>=0;i--) dia[i]=max(dia[i],dia[i+1]);
		int cur=0;
		for(i=1;i<=N;i++) {
			while(cur<ma&&(dia[cur]+1)/2+i>cur) cur++;
			cout<<cur<<" ";
		}
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}