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

int T;
int N,L,R,S;
int A[505];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>L>>R>>S;
		L--,R--;
		int len=R-L+1;
		ZERO(A);
		for(i=L;i<=R;i++) {
			A[i]=i-L+1;
			S-=A[i];
		}
		A[R+1]=N+1;
		if(S<0) {
			cout<<-1<<endl;
			continue;
		}
		set<int> B;
		FOR(i,N) B.insert(i+1);
		for(i=R;i>=L;i--) {
			while(S&&A[i]+1<A[i+1]) A[i]++, S--;
			B.erase(A[i]);
		}
		FOR(i,N) if(i<L||i>R) {
			A[i]=*B.begin();
			B.erase(B.begin());
		}
		if(S) {
			cout<<-1<<endl;
		}
		else {
			FOR(i,N) cout<<A[i]<<" ";
			cout<<endl;
		}
			
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}