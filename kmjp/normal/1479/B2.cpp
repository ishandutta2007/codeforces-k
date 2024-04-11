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
int A[101010];
static ll const def=1<<25;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
		FOR(i,NV) val[i+NV]=ma[i+NV]=1<<20;
		for(i=NV-1;i>=1;i--) ma[i]=min(ma[2*i],ma[2*i+1]);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) {
			return ma[k];
		}
		
		ll v=val[k]+min(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
		return v;
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			ma[k]+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=val[k]+min(ma[k*2],ma[k*2+1]);
		}
	}
};
SegTree_3<ll,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	if(N<=2) {
		cout<<1<<endl;
		return;
	}
	int ret=0;
	FOR(i,N) cin>>A[i];
	st.update(0,1,1+(A[0]!=A[1])-(1<<20));
	st.update(A[0],A[0]+1,2-(1<<20));
	for(i=2;i<N;i++) {
		// other
		int ma=min({st.getval(0,A[i])+1,st.getval(A[i],A[i]+1),st.getval(A[i]+1,N+1)+1});
		// same
		if(A[i]!=A[i-1]) {
			st.update(0,N+1,1);
		}
		y=st.getval(A[i-1],A[i-1]+1);
		if(ma<y) {
			st.update(A[i-1],A[i-1]+1,ma-y);
		}
	}
	
	cout<<st.getval(0,N+1)<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}