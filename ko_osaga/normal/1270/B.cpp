#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;
const int MAXN = 2505;
using pi = pair<int, int>;
using lint = long long;

/*int main(){

	vector<pi> ans;
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=k+1; i++){
		printf("? ");
		for(int j=1; j<=k+1; j++){
			if(i != j) printf("%d ", j);
		}
		puts(""); fflush(stdout);
		int p, v; cin >> p >> v;
		ans.emplace_back(v, p);
	}
	sort(all(ans));
	cout << "! " << count(all(ans), ans.back()) << endl;
}*/

int main(){
	int t;scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		vector<int> v(n);
		for(int i=0; i<n; i++) scanf("%d",&v[i]);
		bool good = 0;
		for(int i=1; i<n; i++){
			if(abs(v[i] - v[i-1]) >= 2){
				printf("YES\n%d %d\n", i, i+1);
				good = 1;
				break;
			}
		}
		if(!good) puts("NO");
	}
}