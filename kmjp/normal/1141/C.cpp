#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
ll Q[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll mi=0,ma=0;
	set<ll> S;
	S.insert(0);
	FOR(i,N-1) {
		cin>>x;
		Q[i+1]=Q[i]+x;
		mi=min(mi,Q[i+1]);
		ma=max(ma,Q[i+1]);
		S.insert(Q[i+1]);
	}
	if(ma-mi!=N-1 || S.size()!=N) return _P("-1\n");
	FOR(i,N) cout<<Q[i]-mi+1<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}