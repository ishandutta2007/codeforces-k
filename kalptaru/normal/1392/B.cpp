#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
//#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
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
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		ll a;
		cin>>a;
		ll b[n],mi=mod,ma=-1*mod;
		FOR(i,0,n)
		{
			cin>>b[i];
			ma=max(ma,b[i]);
			mi=min(mi,b[i]);
		}
		FOR(i,0,n)
		{
			if((a%2)==0)
			{
				cout<<b[i]-mi<<' ';
			}
			else
			cout<<ma-b[i]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}