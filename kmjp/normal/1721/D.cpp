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

int T,N;
ll A[101010],B[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		vector<pair<vector<ll>,vector<ll>>> X;
		vector<ll> A,B;
		FOR(i,N) {
			cin>>x;
			A.push_back(x);
		}
		FOR(i,N) {
			cin>>x;
			B.push_back(x);
		}
		X.push_back({A,B});
		ll ret=0;
		for(i=30;i>=0;i--) {
			int ok=1;
			FORR2(a,b,X) {
				int C[2]={};
				FORR(v,a) {
					x=(v>>i)&1;
					C[x]++;
				}
				FORR(v,b) {
					x=(v>>i)&1;
					C[x^1]--;
				}
				if(C[0]||C[1]) ok=0;
			}
			if(ok) {
				ret|=1<<i;
				vector<pair<vector<ll>,vector<ll>>> Y;
				FORR2(a,b,X) {
					vector<ll> A[2],B[2];
					FORR(v,a) A[(v>>i)&1].push_back(v);
					FORR(v,b) B[((v>>i)&1)^1].push_back(v);
					if(A[0].size()) Y.push_back({A[0],B[0]});
					if(A[1].size()) Y.push_back({A[1],B[1]});
				}
				swap(X,Y);
			}
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}