//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n;

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> n;
		if(n % 2){
			cout << 7;
			n -= 3;
		}
		for(ll i = 0; i * 2 < n; i++){
			cout << 1;
		}
		cout << '\n';
	}
	
	return 0;
}