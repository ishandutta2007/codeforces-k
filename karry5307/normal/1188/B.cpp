#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
unordered_map<ll,li>mp;
ll n,MOD,kk,x,c;
li res;
inline ll read()
{
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=getchar();
    }
    if(ch=='-')
    {
        neg=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num*neg;
}
int main()
{
	n=read(),MOD=read(),kk=read();
	for(register int i=1;i<=n;i++)
	{
		x=read(),c=(li)x*x%MOD*x%MOD*x%MOD;
		mp[(c-(li)kk*x%MOD+MOD)%MOD]++;
	}
	for(auto i:mp)
	{
		res+=(i.second-1)*i.second/2;
	}
	printf("%lld\n",res);
}