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
    for(int i=1;i<=n;i++) cin>>a[i];

    int used[n+1]={0};
    int val[n+1]={0};
    for(int i=n;i>0;i--)
    {
        if(i+a[i]>n) val[i]=a[i];
        else
        {
            val[i]=a[i]+val[i+a[i]];
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,val[i]);
    cout<<ans<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}