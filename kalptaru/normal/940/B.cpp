#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
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
		ll n,k,a,b;
		cin>>n>>k>>a>>b;
		ll ans=0;
		while(n>1)
		{
			ans+=(a*(n%k));
			n-=(n%k);
			if(((n-(n/k))*a)<b)
			{
				ans+=((n-1)*a);
				n=1;
			}
			else
			{
				ans+=b;
				n/=k;
			}
		}
		cout<<ans;
	}
	return 0;
}