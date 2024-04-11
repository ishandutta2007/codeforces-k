/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, l;
    cin>>n>>l;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int ans = 0;
    for(int j=1; j<=l; j++)
    {
        int num = 1<<(j-1);

        int cnt[2]={0};
        for(int i=1; i<=n; i++)
        {
            int y = a[i]%2;
            cnt[y]++;
            a[i]/=2;
        }

        if(cnt[1]>cnt[0]) ans+=num;
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