#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define pp() pop_back()
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define spre cout<<fixed<<setprecision(15);
typedef long long int ll;
typedef long double ld;
using namespace std;
// ll mod=67280421310721;
// const ll mod=998244353;
const ll mod=1e9+7;
ll INF=1e18;
const ll N=300005;
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
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif
    // freopen("azerah.in", "r", stdin);
    // freopen("azerah.out", "w", stdout);
    // ll gtest=0;
    // spre
    
	ll test=1;
	// int gt=0;
	cin>>test;
	while(test--)
	{
		int a,b,x;
		cin>>a>>b;
		x=a+b;
		set<int> s;
		if(x%2)
		{
			FOR(i,0,a+1)
			{
				if((a-i)<=(x/2) && i<=(x/2+1))
				{
					s.insert(x/2+a-i-i+1);
				}
				if((a-i)<=(x/2+1) && i<=(x/2))
				{
					s.insert(x/2+a-i-i);
				}
			}

		}
		else
		{
			FOR(i,0,a+1)
			{
				if((a-i)<=(x/2) && i<=(x/2))
				{
					s.insert(x/2+a-i-i);
				}
			}
		}
		int o=s.size();
		cout<<o<<'\n';
		for(auto i: s)
		{
			cout<<i<<' ';
		}
		cout<<'\n';
	}

	return 0;
}