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

ll K,A,B;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>A>>B;
	if(A<B) swap(A,B);
	
	if(A<K) return _P("-1\n");
	ll MA=0,MB=0;
	if(A%K) MB++;
	if(B%K) MA++;
	if(A/K<MA || B/K<MB) {
		cout<<-1<<endl;
	}
	else {
		cout<<A/K+B/K<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}