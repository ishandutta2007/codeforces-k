#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MAXN = 1002;

ll a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 1; i < n; i++){
        if(a[i] + a[i - 1] < k){
            ans += k - a[i] - a[i - 1];
            a[i] = k - a[i - 1];
        }
    }
    cout << ans << endl;
    for(int i = 0; i < n; i++){
        if(i){
            cout << " ";
        }
        cout << a[i];
    }
    return 0;
}