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
		string s;
		cin>>s;
		int n=s.size();
		vector<int> v;
		bool f=(s[0]=='1');
		int c=1;
		FOR(i,1,n)
		{
			if(s[i]==s[i-1])
			c++;
			else
			{
				if(f) v.pb(c);
				f^=1;
				c=1;
			}
		}
		if(f)v.pb(c);
		sort(v.begin(),v.end());
		int ans=0;
		FOR(i,0,v.size())
		{
			if((i%2)==0)
			{
				ans+=v[v.size()-1-i];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}