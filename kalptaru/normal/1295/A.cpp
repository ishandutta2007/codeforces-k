#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t=1;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		if(n%2==1)
		{
			cout<<7;
			n-=3;
		}
		else
		{
			cout<<1;
			n-=2;
		}
		while(n>0)
		{
			cout<<1;
			n-=2;
		}
		cout<<'\n';
	}
	return 0;
}