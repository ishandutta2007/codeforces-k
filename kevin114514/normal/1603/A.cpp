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

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		bool fl=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			bool f=1;
			for(int j=2;j<=i+1;j++)
				if(x%j!=0)
				{
					f=0;
					break;
				}
			fl|=f;
		}
		if(!fl)
			puts("YES");
		else	puts("NO");
	}
	return 0;
}