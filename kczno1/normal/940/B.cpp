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

const int U=101;
int s[U+5];

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","r",stdin);
	ll x,k,a,b,ans=0;
	cin>>x>>k>>a>>b;
	if(k==1)
	{
		cout<<(x-1)*a;
		return 0;
	}
	while(x>1)
	{
		if(x<k){ans+=(x-1)*a;break;}
		ans+=(x%k)*a;
		x-=x%k;
		ll y=x/k;
		ans+=min((x-y)*a,b);
		x=y;
	}
	cout<<ans;
}