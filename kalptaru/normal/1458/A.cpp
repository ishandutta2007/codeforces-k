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
const ll mod=998244353;
// ll mod=1000000007;
ll INF=1e18+5;
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
	int test=1;
	// cin>>test;
	while(test--)
	{
		int n,m;
		cin>>n>>m;
		ll a[n],b[m];
		ll mi=INF;
		FOR(i,0,n)
		{
			cin>>a[i];
			mi=min(mi,a[i]);
		}
		FOR(i,0,m)
		{
			cin>>b[i];
		}
		ll g=-1;
		FOR(i,0,n)
		{
			if((a[i]-mi)>0)
			{
				if(g==-1)
				{
					g=a[i]-mi;
				}
				else
				{
					g=__gcd(g,a[i]-mi);
				}
			}
		}
		if(g==-1)
		{
			FOR(i,0,m)
			{
				cout<<mi+b[i]<<' ';
			}
			return 0;
		}
		FOR(i,0,m)
		{
			cout<<__gcd(g,b[i]+mi)<<' ';
		}
	}
	return 0;
}