#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
#define ll long long
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n, a[maxN];
bool chk[maxN];
void typre(){
    for(int i = 0; i <= n + 3; i++){
        chk[i] = 0;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        int ans = 0;
        while(n % 5 == 0){
            ans++;
            n = n / 5;
            n = n * 4;
            
        }
        while(n % 3 == 0){
            ans++;
            n = n / 3;
            n = n * 2;
            
        }
        while(n % 2 == 0){
            ans++;
            n = n / 2;
            n = n * 1;
            
        }
        if(n == 1) cout << ans << endl;
        else cout << -1 << endl;
    }
}