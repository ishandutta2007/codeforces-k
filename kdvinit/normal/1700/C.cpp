/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int x = a[1];
    int ad=0;
    int ans=0;

    for(int i=2; i<=n; i++)
    {
        int y = a[i]-a[i-1];
        ans+=(abs(y));
        if(y<0) ad+=(abs(y));
    }

    ans+=abs(x-ad);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}