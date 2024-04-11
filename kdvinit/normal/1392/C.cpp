/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    int n;
    cin>>n;

    long long int a[n+1],ans=0;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=2;i<=n;i++)
    {
        if(a[i-1]>a[i]) ans+=a[i-1]-a[i];
    }

    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}