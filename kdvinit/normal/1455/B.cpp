/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

void solve()
{
    int x;
    cin>>x;

    int y=0,n=0;
    while(y<x)
    {
        n++;
        y+=n;
    }

    if((y-x)!=1) cout<<n<<endl;
    else cout<<n+1<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}