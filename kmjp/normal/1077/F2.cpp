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

int N,K,X;
int A[5050];

ll dp[5050][5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>X;
	FOR(i,N) cin>>A[i];
	
	FOR(x,5050) FOR(y,5050) dp[x][y]=-1LL<<60;
	dp[0][0]=0;
	for(i=1;i<=X;i++) {
		deque<pair<ll,int>> D;
		D.push_back({dp[i-1][0],0});
		for(j=1;j<=N;j++) {
			while(D.size() && D.front().second<j-K) D.pop_front();
			dp[i][j]=A[j-1]+D.front().first;
			while(D.size() && D.back().first<=dp[i-1][j]) D.pop_back();
			D.push_back({dp[i-1][j],j});
		}
	}
	
	ll ret=-1;
	FOR(i,N+1) if(i>N-K) ret=max(ret,dp[X][i]);
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}