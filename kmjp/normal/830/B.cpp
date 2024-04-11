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
deque<int> D[101010];
vector<int> V;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	V add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		D[x].push_back(i+1);
		bt.add(i+1,1);
	}
	
	int pre=-1;
	FOR(x,101000) if(D[x].size()) {
		if(D[x].back()>pre) {
			while(D[x].front()<pre) D[x].push_back(D[x].front()), D[x].pop_front();
		}
		FORR(r,D[x]) {
			V.push_back(r);
			pre=r;
		}
	}
	
	pre=0;
	ll ret=0;
	FORR(r,V) {
		if(r>pre) {
			ret+=bt(r)-bt(pre);
		}
		else {
			ret+=bt(N)-bt(pre) + bt(r);
		}
		bt.add(r,-1);
		pre=r;
	}
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}