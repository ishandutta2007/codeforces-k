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
		ll n;
		cin>>n;
		ll x[7]={0,0,1,1,2,2,2};
		ll y[7]={1,2,0,2,0,1,2};
		cout<<7*n+8<<'\n';
		cout<<0<<' '<<2<<'\n';
		FOR(i,0,n+1)
		{
			FOR(j,0,7)
			{
				if((i%2)==0)
				cout<<2*i+x[j]<<' '<<2+y[j]<<'\n';
				else
				cout<<2*i+x[j]<<' '<<2-y[j]<<'\n';
			}
		}
	}
	return 0;
}