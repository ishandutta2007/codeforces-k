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
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
#define uni(v) v.resize(unique(ALL(v))-v.begin())
void die(string S){puts(S.c_str());exit(0);}
int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		int n;
		cin>>n;
		vector<int> vec;
		int p=0;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			vec.pb(x);
		}
		vector<int> vec2=vec;
		srt(vec2);
		rev(vec);
		vector<int> st=vec;
		for(int i=0;i<n;i++)
		{
			if(sz(st)&&st.back()==vec2[p])
			{
				p++;
				st.pop_back();
			}
			else if(sz(st)&&sz(st)%2==0&&(st[sz(st)-2]==vec2[p]))
			{
				int x=st.back();
				st.pop_back();
				st.pop_back();
				st.pb(x);
				p++;
			}
			else break;
		}
		if(p==n)
			puts("YES");
		else	puts("NO");
	}
	return 0;
}