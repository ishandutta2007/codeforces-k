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

int N,M;
int A[2020];
int num[2020];
int ret;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	int tar=N/M;
	FOR(i,N) {
		cin>>A[i];
		if(A[i]<=M) num[A[i]]++;
	}
	FOR(i,N) {
		if(A[i]>M || num[A[i]]>tar) {
			x=min_element(num+1,num+M+1)-num;
			if(num[x]>=tar) break;
			ret++;
			if(A[i]<=M) num[A[i]]--;
			A[i]=x;
			num[A[i]]++;
		}
	}
	
	_P("%d %d\n",*min_element(num+1,num+M+1),ret);
	FOR(i,N) _P("%d%c",A[i],(i==N-1)?'\n':' ');
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}