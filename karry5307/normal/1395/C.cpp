#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,m,flg,flg2;
ll x[MAXN],y[MAXN];
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
	n=read(),m=read();
	for(register int i=1;i<=n;i++)
	{
		x[i]=read();
	}
	for(register int i=1;i<=m;i++)
	{
		y[i]=read();
	}
	for(register int i=0;i<512;i++)
	{
		flg=1;
		for(register int j=1;j<=n;j++)
		{
			flg2=0;
			for(register int k=1;k<=m;k++)
			{
				flg2|=(((x[j]&y[k])|i)==i);
			}
			flg&=flg2;
		}
		if(flg)
		{
			return printf("%d\n",i),0;
		}
	}
}