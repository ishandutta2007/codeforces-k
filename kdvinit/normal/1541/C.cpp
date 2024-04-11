/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);

    int ans = a[n]-a[1];
    for(int i=2; i<=n; i++)
    {
        int x =  a[i]-a[i-1];
        int cnt = (i-1)*(n-i+1);
        ans -= (x*cnt);
    }
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}