#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int main()
{
//    ios_base::sync_with_stdio(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ll n;
    cin >> n;
    if(n%2){
        cout << "-";
    }
    cout << ((n+1) / 2);
    return 0;
}