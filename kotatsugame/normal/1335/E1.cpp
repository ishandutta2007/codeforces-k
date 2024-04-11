#include<cstdio>
#include<algorithm>
const int MAXN=200002;
using namespace std;
int T,N;
int A[MAXN];
short Lnxt[200][MAXN],Rnxt[200][MAXN];
short cnt[200][MAXN];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=1;i<=N;i++)
		{
			scanf("%d",&A[i]);
			A[i]--;
		}
		for(int i=0;i<200;i++)
		{
			Rnxt[i][0]=0;
			Lnxt[i][N+1]=N+1;
			cnt[i][0]=0;
		}
		for(int i=1;i<=N;i++)
		{
			for(int j=0;j<200;j++)Rnxt[j][i]=Rnxt[j][i-1];
			Rnxt[A[i]][i]=i;
		}
		for(int i=N;i>=1;i--)
		{
			for(int j=0;j<200;j++)Lnxt[j][i]=Lnxt[j][i+1];
			Lnxt[A[i]][i]=i;
		}
		for(int i=1;i<=N;i++)
		{
			for(int j=0;j<200;j++)cnt[j][i]=cnt[j][i-1];
			cnt[A[i]][i]++;
		}
		for(int i=0;i<200;i++)cnt[i][N+1]=cnt[i][N];
		int ans=0;
		for(int k=0;k<200;k++)
		{
			int L=0,R=N+1;
			int now=0;
			while(L<R)
			{
				for(int x=0;x<200;x++)ans=max(ans,now*2+cnt[x][R-1]-cnt[x][L]);
				L=Lnxt[k][L+1];
				R=Rnxt[k][R-1];
				now++;
			}
		}
		printf("%d\n",ans);
	}
}