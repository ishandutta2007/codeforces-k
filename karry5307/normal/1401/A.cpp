#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e3+51; 
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
	if(n<kk)
	{
		return (void)printf("%lld\n",kk-n);
	}
	puts((n+kk)%2?"1":"0");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}