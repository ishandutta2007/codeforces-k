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
int n, a[maxN], k;
bool chk[maxN];
int pre[maxN];
int mx;

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n >> k; mx = 0;
        pre[0] = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
        }
        for(int i = 2; i <= n; i++){
            int num = a[i];
            if(a[i] * 100 > k * pre[i - 1]){
                if((num * 100) % k == 0) mx = max(mx, num * 100 / k - pre[i - 1]);
                else mx = max(mx, num * 100 / k + 1 - pre[i - 1]);
            }
        }
        cout << mx << endl;;
    }
}