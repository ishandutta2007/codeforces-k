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
int A[3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>A[0]>>A[1]>>A[2];
		
		vector<int> P={1,2,3,4,5,6,7};
		int ret=0;
		do {
			int pat=0;
			int B[3]={A[0],A[1],A[2]};
			FORR(p,P) {
				int ok=1;
				FOR(i,3) if(B[i]==0 && p&(1<<i)) ok=0;
				if(ok) {
					pat++;
					FOR(i,3) if(p&(1<<i)) B[i]--;
				}
			}
			ret=max(ret,pat);
			
		} while(next_permutation(ALL(P)));
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}