#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=105;

int n,t,a[N],mark[N];

int main(){
	cin>>t;
	while(t--){
		int ans=1;
		fill(mark,mark+N,0);
		cin>>n;
		f(i,0,n){ cin>>a[i]; mark[a[i]]++; }
		sort(a,a+n);
		f(i,1,n)
			if(a[i]>a[i-1]+1)
				ans=0;
		cout<<(ans? "YES" : "NO")<<endl;
		
	}
}