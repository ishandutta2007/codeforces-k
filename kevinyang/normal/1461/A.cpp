#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		for(int i = 0; i<n; i++){
			if(i%3==0)cout << "a";
			else if(i%3==1)cout << "b";
			else cout << "c";
		}
		cout << "\n";
	}
	return 0;
}