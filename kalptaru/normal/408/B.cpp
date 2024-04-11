#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define readarr(a,n) ll a[(n)+2]; FOR(i, 1, (n)+1) {cin >> a[i];}
#define readmat(a,n,m) ll a[(n+2)][(m+2)]; FOR(i, 1, (n)+1){FOR(j,1,(m)+1)cin>>a[i][j];}
#define printarr(a,l,r) FOR(i, l, (r)+1) {cout<< a[i]<<' ';}
#define printmat(a,n,m) FOR(i, 1, (n)+1){FOR(j,1,(m)+1)cout<<a[i][j]<<' ';cout<<"\n";}
#define setpre(n) std::cout << std::fixed << std::setprecision(n);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
//	cin>>t;
	while(t--)
	{
		string p,s;
		cin>>p>>s;
		int pn[26]={0},sn[26]={0},ans=0;
		FOR(i,0,p.size())
		pn[p[i]-'a']++;
		FOR(i,0,s.size())
		sn[s[i]-'a']++;
		FOR(i,0,26)
		{
			if(pn[i]==0 && sn[i]>0)
			{
				cout<<-1;
				return 0;
			}
			else
			ans+=min(pn[i],sn[i]);
		}
		cout<<ans;
	}
}