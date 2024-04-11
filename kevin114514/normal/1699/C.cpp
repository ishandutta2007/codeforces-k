#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define lb(v,x) (int)(lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (int)(upper_bound(ALL(v),x)-v.begin())
#define uni(v) v.resize(unique(ALL(v))-v.begin())
void die(string S){puts(S.c_str());exit(0);}
int pos[100100];
const ll mod=1e9+7;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			pos[x]=i;
		}
		int l=pos[0],r=pos[0];
		ll ans=1;
		for(int i=1;i<n;i++)
		{
			if(l<pos[i]&&pos[i]<r)
			{
				ans=ans*(r-l+1-i)%mod;
			}
			else
			{
				l=min(l,pos[i]);
				r=max(r,pos[i]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}