#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,n,l,r;
ll x[MAXN],prefix[MAXN];
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
inline void solve()
{
	n=read(),l=r=0;
	for(register int i=1;i<=n;i++)
	{
		x[i]=read(),prefix[i]=prefix[i-1]+!x[i];
		x[i]?r=i,l=!l?i:l:1;
	}
	printf("%d\n",prefix[r]-prefix[l-1]);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}