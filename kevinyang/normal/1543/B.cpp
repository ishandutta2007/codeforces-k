#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int sum = 0;
		for(int i = 0; i<n; i++){
			int x;
			cin >> x;
			sum+=x;
		}
		int v = sum%n;
		int v2 = n-sum%n;
		cout << v*v2 << "\n";
	}
	return 0;
}