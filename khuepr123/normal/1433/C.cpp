#include<bits/stdc++.h>
using namespace std;

#define sadasdads long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
#define ll long long
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, m, k, temp, temp1, temp2; int a[maxN]; int b[maxN]; bool chk[maxN];

void typre(){ // typical reset
    for(int i = 0; i <= n + 15; i++){
        chk[i] = 0;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
         bool x = 1;
        cin >> n; for(int i = 1; i <= n; i++){
            cin >> a[i];
            
        }
        for(int i = 2; i <= n; i++){
            if(a[i] - a[i - 1]){
                 x = 0;
            }
            
        }
        if(x) cout << "-1\n";
        else{
             int mx = 0;
             for(int i = 1; i <= n; i++){
            mx = max(mx, a[i]);
            
               }
               a[0] = a[1]; a[n + 1] = a[n]; int pos;
               for(int i = 1; i <= n; i++){
            if(a[i] == mx){
                 if(a[i] != a[i - 1] || a[i] != a[i + 1]) pos = i;
            }
          
        }
        cout << pos << "\n";  
        
        
        }
    }
}