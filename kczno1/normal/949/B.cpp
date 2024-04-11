//by kcz 1552920354@qq.com
//if you find any bug in my code
//please tell me
#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define mp make_pair
#define gc (c=getchar())
char readc()
{
	char c;
	while(gc<'-');
	return c;
}
int read()
{
    char c;
    while(gc<'-');
    if(c=='-')
    {
        int x=gc-'0';
        while(gc>='0')x=x*10+c-'0';
        return -x;
    }
    int x=c-'0';
    while(gc>='0')x=x*10+c-'0';
    return x;
}
#undef gc

ll solve(ll x,ll n)
{
	if(n==1)return 1;
	if(x%2==1)return x/2+1;
	if(n%2==0)return n/2+solve(x/2,n/2);
	return n/2+solve(x/2+1,(n+1)/2);
}

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	ll n;int q;
	cin>>n>>q;
	while(q--)
	{
		ll x;
		scanf("%lld",&x);
		if(x==1)puts("1");
		else printf("%lld\n",solve(x,n));
	}
}