#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=3e5+51;
ll cnt,cap,res;
ll num[MAXN];
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
    cnt=read(),cap=read();
	for(register int i=0;i<cnt;i++)
	{
		num[i]=read();
	}
	for(register int i=0;i<cnt;i++)
	{
		res+=num[i]/cap;
		if(num[i]%cap)
		{
			num[i+1]=max(num[i+1]-cap+(num[i]%cap),0ll);
			res++;
		}
	}
	cout<<res;
}