#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define spre cout<<fixed<<setprecision(15);
typedef long long int ll;
using namespace std;
//ll mod=67280421310721;
ll mod=8589934592;
// const ll mod=1000000007;
ll INF=1e18;
ll po(ll a,ll b){
	ll re=1;  
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a);
			re%=mod;
		}
		a=(a*a);
		a%=mod;
		b>>=1;
	}
	return re;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif	
	ll test=1;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		ll x[n],y[n];
		FOR(i,0,n)
		{
			cin>>x[i]>>y[i];
		}
		sort(x,x+n);
		sort(y,y+n);
		if(n%2)
		{
			cout<<1<<'\n';
		}
		else
		{
			cout<<(x[n/2]-x[n/2-1]+1)*(y[n/2]-y[n/2-1]+1)<<'\n';
		}
	}
	return 0;
}