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

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=0;
	V comp(V l,V r){ return __gcd(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,0);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return 0;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

int N;
int A[505050];
int Q;
SegTree_1<int,1<<20> st;
int T,L,R,X,Y;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&N);
	FOR(i,N) {
		scanf("%d",&A[i]);
		st.update(i,A[i]);
	}
	scanf("%d",&Q);
	while(Q--) {
		scanf("%d%d",&T,&L);
		L--;
		if(T==1) {
			scanf("%d%d",&R,&X);
			
			if(L+1==R) {
				_P("YES\n");
				continue;
			}
			
			
			int M=L;
			for(i=20;i>=0;i--) if(M+(1<<i)<=R) {
				if(st.getval(L,M+(1<<i)) % X==0) M+=1<<i;
			}
			x=st.getval(L,M);
			y=st.getval(M+1,R);
			if(__gcd(x,y) % X==0) {
				_P("YES\n");
			}
			else {
				_P("NO\n");
			}
			
		}
		else {
			scanf("%d",&X);
			A[L]=X;
			st.update(L,A[L]);
		}
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}