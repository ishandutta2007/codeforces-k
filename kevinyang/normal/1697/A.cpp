#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		int sum = 0;
		for(int i = 0; i<n; i++){
			int x;
			cin >> x;
			sum+=x;
		}
		cout << max(0LL,sum-m) << "\n";
	}
	return 0;
}