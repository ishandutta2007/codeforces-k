#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51,MOD=998244353;
ll n,m,kk;
ll fact[MAXN],finv[MAXN];
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
inline void setup(ll cnt)
{
	fact[0]=fact[1]=finv[0]=1;
	for(register int i=2;i<=cnt;i++)
	{
		fact[i]=(li)fact[i-1]*i%MOD;
	}
	finv[cnt]=qpow(fact[cnt],MOD-2);
	for(register int i=cnt-1;i;i--)
	{
		finv[i]=(li)finv[i+1]*(i+1)%MOD;
	}
}
inline ll binom(ll m,ll n)
{
	return (li)fact[m]*finv[n]%MOD*finv[m-n]%MOD;
}
int main()
{
	n=read(),m=read(),kk=read(),setup(10000);
	printf("%d\n",(li)m*qpow(m-1,kk)%MOD*binom(n-1,kk)%MOD);
}