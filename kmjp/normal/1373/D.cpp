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

int T;
int N;
int A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		ll ret=0;
		FOR(i,N) {
			cin>>A[i];
			if(i%2==0) ret+=A[i];
		}
		ll ma=0,mi=0;
		ll cur=0;
		for(i=1;i<N;i+=2) {
			cur+=A[i]-A[i-1];
			ma=max(ma,cur-mi);
			mi=min(cur,mi);
		}
		mi=cur=0;
		for(i=2;i<N;i+=2) {
			cur+=A[i-1]-A[i];
			ma=max(ma,cur-mi);
			mi=min(cur,mi);
		}
		cout<<ret+ma<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}