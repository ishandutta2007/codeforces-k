#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
//ll mod=67280421310721;
//ll mod=998244353;
//ll mod=163577857;
ll INF=1e18;
ll po(ll a,ll b)
{
	ll re=1;
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a)%mod;
		}
		a=(a*a)%mod;
		b>>=1;
	}
	return re;
}
vector<pair<int,int> > ver[200005],hor[200005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		int s,v1,v2,t1,t2;
		cin>>s>>v1>>v2>>t1>>t2;
		if((s*v1+2*t1)<(s*v2+2*t2))
		{
			cout<<"First";
		}
		else if((s*v1+2*t1)==(s*v2+2*t2))
		cout<<"Friendship";
		else
		cout<<"Second";
	}
	return 0;
}