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

    int a[n+1], b[n+1];
    for(int i=1; i<=n; i++) { cin>>a[i]; b[i]=a[i]; }
    sort(b+1, b+n+1);

    int cnt=0, i=n, mx=b[n];
    while(a[i]!=mx)
    {
        cnt++;
        int cur=a[i];
        while(a[i]<=cur) i--;
    }
    cout<<cnt<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}