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
// ll mod=998244353;
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
	#ifndef ONLINE_JUDGE
	freopen("INPUT.txt", "r", stdin);
	freopen("OUTPUT.txt", "w", stdout);
	#endif
	int test=1;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		int a[n],m=0,mi=0,ch[n]={0},gc,c,ans[n];
		FOR(i,0,n)
		{
			cin>>a[i];
			if(m<a[i])
			{
				m=a[i];
				mi=i;
			}
		}
		ans[0]=a[mi];
		ch[mi]=1;
		gc=m;
		FOR(i,1,n)
		{
			m=0;
			FOR(j,0,n)
			{
				if(ch[j])
				{
					continue;
				}
				c=__gcd(gc,a[j]);
				if(m<c)
				{
					m=c;
					mi=j;
				}
			}
			gc=__gcd(gc,a[mi]);
			ans[i]=a[mi];
			ch[mi]=1;
		}
		FOR(i,0,n)
		cout<<ans[i]<<' ';
		cout<<'\n';
	}
	return 0;
}