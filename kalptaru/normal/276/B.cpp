#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define readarr(a,n) ll a[(n)]; FOR(i, 0, (n)) {cin >> a[i];}
#define readmat(a,n,m) ll a[(n)][(m)]; FOR(i, 0, (n)){FOR(j,0,(m))cin>>a[i][j];}
#define printarr(a,n) FOR(i, 0, (n)) {cout<< a[i]<<' ';}
#define printmat(a,n,m) FOR(i, 0, (n)){FOR(j,0,(m))cout<<a[i][j]<<' ';cout<<"\n";}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
//	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int al[26]={0},k=0;
		FOR(i,0,s.size())
		al[s[i]-'a']++;
		FOR(i,0,26)
		{
			if(al[i]%2==1)
			k++;
		}
		if(k%2==1 || k==0)
		cout<<"First";
		else
		cout<<"Second";
	}
}