#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=1e5+51;
ll test,cnt,sum;
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
	test=read();
	for(register int i=0;i<test;i++)
	{
		cnt=read(),sum=0;
		for(register int j=0;j<cnt;j++)
		{
			sum+=read();
		}
		printf("%d\n",sum%cnt?sum/cnt+1:sum/cnt);
	}
}