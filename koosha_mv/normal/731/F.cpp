#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
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

const int N=4e5+99,S=500;

int n,t,ans,a[N],cnt[N];

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n;
	f(i,1,n+1){
		int x;
		cin>>x;
		cnt[x]++;
	}
	f(i,1,N) cnt[i]+=cnt[i-1];
	f(i,1,N){
		if(cnt[i]==cnt[i-1]) continue ;
		int res=0;
		for(int j=i;j+i<N;j+=i){
			res+=j*(cnt[j+i-1]-cnt[j-1]);
		}
		maxm(ans,res);
		//cout<<i<<" -> "<<res<<endl;
	}
	cout<<ans;
}