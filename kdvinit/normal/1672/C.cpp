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

    int cnt=0, fi=-1, li=-1;
    for(int i=1; i<n; i++)
    {
        if(a[i]==a[i+1])
        {
            cnt++;
            li=i;
            if(fi==-1) fi=i;
        }
    }

    if(cnt<=1) { cout<<0<<endl; return; }

    int len = li+1-fi+1;

    int ans = len-3;
    if(ans==0) ans=1;

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}