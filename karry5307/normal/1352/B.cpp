#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51; 
ll test,n,kk;
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
	n=read(),kk=read();
	if((n&1)&&(kk&1))
	{
		if(n<kk)
		{
			return (void)puts("No");
		}
		puts("Yes");
		for(register int i=1;i<=kk;i++)
		{
			printf("%d%c",i!=kk?1:n-kk+1," \n"[i==kk]);
		}
	}
	if((n&1)&&!(kk&1))
	{
		return (void)puts("No");
	}
	if(!(n&1)&&(kk&1))
	{
		if(n<2*kk)
		{
			return (void)puts("No");
		}
		puts("Yes");
		for(register int i=1;i<=kk;i++)
		{
			printf("%d%c",i!=kk?2:n-2*(kk-1)," \n"[i==kk]);
		}
	}
	if(!(n&1)&&!(kk&1))
	{
		if(n<kk)
		{
			return (void)puts("No");
		}
		puts("Yes");
		for(register int i=1;i<=kk;i++)
		{
			printf("%d%c",i!=kk?1:n-kk+1," \n"[i==kk]);
		}
	}
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();	
	}
}