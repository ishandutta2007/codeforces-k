#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=5e5+99;
 
int x,n,t,ans,a[N],b[N],c[N],mark[N];
 
int main(){
	cin>>n;
	f(i,1,n+1) cin>>a[i];
	f(i,1,n+1){
		cin>>x;
		c[x]=i;
	}
	f(i,1,n+1) a[i]=c[a[i]];
	f(i,1,n+1)
		mark[(a[i]-i+n)%n]++;
	f(i,0,n) maxm(ans,mark[i]);
	cout<<ans;
}