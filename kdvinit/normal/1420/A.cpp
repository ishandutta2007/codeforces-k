/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=2;i<=n;i++)
    {
        if(a[i-1]>a[i]) continue;
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}