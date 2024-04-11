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

int H,W;
int A[51][51];
int R[2][51],C[2][51];
ll ret;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		FOR(x,W) {
			cin>>A[y][x];
			R[A[y][x]][y]++,C[A[y][x]][x]++, ret++;
		}
	}
	
	ret=H*W;
	FOR(y,H) FOR(i,2) if(R[i][y]>=2) ret+=(1LL<<R[i][y])-(1+R[i][y]);
	FOR(x,W) FOR(i,2) if(C[i][x]>=2) ret+=(1LL<<C[i][x])-(1+C[i][x]);
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}