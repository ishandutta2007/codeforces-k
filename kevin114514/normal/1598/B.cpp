#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
void die(string S){puts(S.c_str());exit(0);}
int grid[1010][5];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			for(int j=0;j<5;j++)
				cin>>grid[i][j];
		bool flag=false;
		for(int i=0;i<5;i++)
			for(int j=i+1;j<5;j++)
			{
				bool f=true;
				int x=0,y=0;
				for(int k=0;k<n;k++)
				{
					if(!grid[k][i]&&!grid[k][j])
						f=false;
					if(grid[k][i])
						x++;
					if(grid[k][j])
						y++;
				}
				if(f&&x>=n/2&&y>=n/2)
					flag=1;
			}
		if(flag)
			puts("YES");
		else	puts("NO");
	}
	return 0;
}