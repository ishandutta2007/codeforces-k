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

const int N=1e6+99;

int n,l,r,k,t,a[N];

int main(){
	cin>>t;
	while(t--){
		cin>>n>>l>>r>>k;
		f(i,0,n) cin>>a[i];
		sort(a,a+n);
		int ans=0;
		f(i,0,n){
			if(l<=a[i] && a[i]<=r && a[i]<=k){
				ans++;
				k-=a[i];
			}
		}
		cout<<ans<<endl;
	}
}