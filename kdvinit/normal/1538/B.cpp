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
    int sum=0;

    for(int i=1; i<=n; i++) { cin>>a[i]; sum+=a[i]; }

    if(sum%n!=0) { cout<<-1<<endl; return; }

    int m = sum/n;

    int k=0;
    for(int i=1; i<=n; i++) k+=(a[i]>m);
    cout<<k<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}