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
		ll k;
		cin>>n>>k;
		ll l1,l2,r1,r2;
		cin>>l1>>r1>>l2>>r2;
		if(l1>l2)
		{
			swap(l1,l2);
			swap(r1,r2);
		}
		ll l=max(r2,r1)-l1;
		ll ans=INF;
		if(r1<l2)
		{
			ll c=0,co=0;
			FOR(i,0,n)
			{
				c=(i+1)*(l2-r1);
				if(((i+1)*l)<k)
				{
					co=(i+1)*l;
					c+=co;
				}
				else
				{
					c+=k;
					co=k;
				}
				c+=2*(k-co);
				ans=min(ans,c);
			}
		}
		else if(r1<r2)
		{
			ll s=(r1-l2);
			k-=n*s;
			ans=0;
			if(k>0)
			{
				if((n*(l-s))<k)
				{
					ans=(n*(l-s));
					k-=(n*(l-s));
					ans+=2*k;
				}
				else
				{
					ans=k;
				}
			}
		}
		else
		{
			
			ll s=(r2-l2);
			k-=n*s;
			ans=0;
			if(k>0)
			{
				if((n*(l-s))<k)
				{
					ans=(n*(l-s));
					k-=(n*(l-s));
					ans+=2*k;
				}
				else
				{
					ans=k;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}