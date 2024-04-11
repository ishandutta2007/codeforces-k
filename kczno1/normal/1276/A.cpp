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

const int N=1.5e5+5;
char s[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int tt;
	cin>>tt;
	while(tt--)
	{
		scanf("%s",s+1);
		int n=strlen(s+1);
		vector<int>ans;
		rep(i,1,n-2)
		{
			if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o')
			{
				if(s[i+3]=='n'&&s[i+4]=='e')
				{
					ans.push_back(i+2);
					i+=4;
				}
				else ans.push_back(i+1);
			}
			else
			if(s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e')
				ans.push_back(i+1);
		}
		printf("%d\n",(int)ans.size()); 
		for(auto x:ans)printf("%d ",x);puts("");
	}
}