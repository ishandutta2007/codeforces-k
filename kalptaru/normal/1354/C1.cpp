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
//ll mod=1000000007;
//ll mod=67280421310721;
ll mod=998244353;
ll INF=1e18;
ll po(ll a,ll b)
{
	ll re=1;
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a);
//			re%=mod;
		}
		a=(a*a);
//		a%=mod;
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
	cin>>test;
	cout<<fixed<<setprecision(10);
	while(test--)
	{
		long double n,a,c,ans=0,pi=acos(-1),e;
		cin>>n;
		e=360/(2*n);
		FOR(i,1,n)
		{
			ans+=sin(pi*i*e/180);
		}
		int u=n;
		if(u%2==0)
		{
			cout<<ans<<'\n';
		}
		else
		{
			cout<<(ans+1)/sqrt(2)<<'\n';
		}
	}
	return 0;
}