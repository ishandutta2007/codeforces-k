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
int A[1010101];
int sum;
int C[2][1<<20][20];
int dis[20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&N);
	FOR(i,N) scanf("%d",&A[i]);
	int ma=0;
	FOR(j,20) {
		C[N%2][0][j]=N;
		dis[j]=N;
	}
	for(i=N-1;i>=0;i--) {
		sum^=A[i];
		FOR(j,20) {
			if(A[i]&(1<<j)) {
				if(C[i%2][sum>>j][j]>dis[j]) C[i%2][sum>>j][j]=0;
				ma=max(ma,C[i%2][sum>>j][j]-i);
				C[i%2][sum>>j][j]=max(C[i%2][sum>>j][j],i);
			}
			else {
				dis[j]=i;
				C[i%2][sum>>j][j]=i;
			}
		}
		
	}
	
	
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}