#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
//#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
//ll mod=67280421310721;
//ll mod=998244353;
ll INF=1e18;
ll po(ll a,ll b)
{
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
	int test=1;
//	cin>>test;
	while(test--)
	{
		ll n,k;
		cin>>n>>k;
		ll dp[k+1][n+1];
		memset(dp,0,sizeof(dp));
		FOR(i,0,n+1)
		{
			dp[1][i]=1;
		}
		FOR(i,2,k+1)
		{
			FOR(j,1,n+1)
			{
				for(int k=1;(k*j)<=n;k++)
				{
					dp[i][k*j]=(dp[i-1][j]+dp[i][k*j])%mod;
				}
			}
		}
		ll ans=0;
		FOR(i,1,n+1)
		{
			ans+=dp[k][i];
		}
		cout<<ans%mod;
	}
	return 0;
}