#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define Add(x,y) x=(x+y)%mod;
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=1e6+99;

int k,n,t,a[N];

int C(int x){
	return x*(x+1)/2;
}
int calc(int x){
	if(x<=k){
		return C(x);
	}
	return C(k)+C(k-1)-C(2*k-1-x);
}
main(){
	cin>>t;
	while(t--){
		cin>>k>>n;
		int l=0,r=2*k-1;
		while(l+1<r){
			int mid=(l+r)/2;
			if(calc(mid)<n) l=mid;
			else r=mid;
		}	
		cout<<r<<endl;
	}	
}