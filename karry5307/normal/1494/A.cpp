#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,tp,n,flg;
char ch[MAXN];
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
	scanf("%s",ch+1),n=strlen(ch+1);
	for(register int i=0;i<8;i++)
	{
		tp=0,flg=1;
		for(register int j=1;j<=n;j++)
		{
			if(!(i&(1<<(ch[j]-'A')))&&!tp)
			{
				flg=0;
				break;	
			} 
			i&(1<<(ch[j]-'A'))?tp++:tp--;
		}
		if(flg&&!tp)
		{
			return (void)puts("Yes");
		}
	}
	puts("No");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}