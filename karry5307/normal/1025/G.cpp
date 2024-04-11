#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51,MOD=1e9+7;
ll n,x,res;
ll sz[MAXN];
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
inline ll qpow(ll base,ll exponent)
{
	ll res=1;
	while(exponent)
	{
		if(exponent&1)
		{
			res=(li)res*base%MOD;
		}
		base=(li)base*base%MOD,exponent>>=1;
	}
	return res;
}
int main()
{
	n=read();
	for(register int i=1;i<=n;i++)
	{
		x=read(),x!=-1?sz[x]++:1;
	}
	for(register int i=1;i<=n;i++)
	{
		sz[i]?res=(res+qpow(2,sz[i])-1)%MOD:1;
	}
	printf("%d\n",(qpow(2,n-1)-1-res+MOD)%MOD);
}