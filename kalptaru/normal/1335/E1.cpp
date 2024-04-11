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
	ll res=1;
	while(b)
	{
		if(b%2==1)
		{
			res*=a;
			res%=mod;
		}
		a*=a;
		a%=mod;
		b>>=1;
	}
	return res;
}
int pre[201][200005];
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
		if(n==1)
		{
			cin>>n;
			cout<<1<<'\n';
			continue;
		}
		int a[n];
		vector<int> b[201];
		int siz[201]={0};
		FOR(i,0,n)
		{
			cin>>a[i];
			siz[a[i]]++;
			pre[a[i]][i]++;
			b[a[i]].pb(i);
		}
		FOR(i,1,201)
		{
			FOR(j,1,n)
			{
				pre[i][j]=pre[i][j]+pre[i][j-1];
			}
		}
		int m=1;
		FOR(i,1,201)
		{
			int r=b[i].size();
			m=max(m,r);
			if(r<=1)
			continue;
			FOR(j,0,r)
			{
				if((r-j-1)<=j)
				break;
				FOR(k,1,201)
				{
					if(siz[k]==0)
					continue;
					if(i!=k)
					{
						m=max(m,((pre[k][b[i][r-j-1]]-pre[k][b[i][j]])+2*(j+1)));
					}
				}
			}
		}
		cout<<m<<'\n';
		FOR(i,0,n)
		{
			FOR(j,1,201)
			pre[j][i]=0;
		}
	}
	return 0;
}