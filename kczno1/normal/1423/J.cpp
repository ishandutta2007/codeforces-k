#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T&x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
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

const int D=1e9+7;

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int tt;
	cin>>tt;
	while(tt--)
	{
		s64 m;
		scanf("%lld",&m);
		s64 k=m/2;
		s64 hk=k/2%D;k%=D;
		printf("%d\n",int((hk+1)*(k+1+D-hk)%D));
	}
}