//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll t, n;

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n;
		ll x = (n + 3) / 4;
		for(ll i = 0; i < n - x; i++){
			cout << 9;
		}
		for(ll i = 0; i < x; i++){
			cout << 8;
		}
		cout << '\n';
	}
	
	return 0;
}