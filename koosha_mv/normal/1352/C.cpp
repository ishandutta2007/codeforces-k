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
 
const int N=5e5+9;

ll n,k,t,l,r=2e9+9,mid;

ll solve(ll x){
	return x-(x-1)/n;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n>>k;
		l=0,r=2e9+9;
		while(l+1<r){
			mid=(l+r)/2;
			if(solve(mid)<=k) l=mid;
			else r=mid;
		}
		cout<<l<<endl;
	}
}