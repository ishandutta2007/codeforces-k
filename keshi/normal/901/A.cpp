//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

int n, a[maxn];

int main(){
	fast_io;

	cin >> n;
	for(int i = 0; i <= n; i++){
		cin >> a[i];
	}
	assert(a[0] == 1);
	bool ok = 0;
	int x = -1;
	for(int i = 0; i < n; i++){
		if(a[i] >= 2 && a[i + 1] >= 2) ok = 1, x = i;
	}
	if(!ok){
		cout << "perfect\n";
		return 0;
	}
	cout << "ambiguous\n";
	int ptr = 0;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j < a[i]; j++){
			cout << ptr << " ";
		}
		ptr += a[i];
	}
	cout << "\n";
	ptr = 0;
	for(int i = 0; i <= n; i++){
		if(x + 1 == i){
			cout << ptr - 1 << " ";
			for(int j = 1; j < a[i]; j++){
				cout << ptr << " ";
			}
			ptr += a[i];
		}
		else{
			for(int j = 0; j < a[i]; j++){
				cout << ptr << " ";
			}
			ptr += a[i];
		}
	}
	cout << "\n";

	
	return 0;
}