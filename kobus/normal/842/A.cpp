#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
//#define int long long
typedef long long ll;
typedef pair<int,int>pii;
 
#define MAXN 11234567890123
#define INF INT_MAX/2
#define MOD 1000000



int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int l,r,x,y;
	double e;
	cin>>l>>r>>x>>y>>e;

	for(int i=x;i<=y;i++){
		if(e*i==(ll)e*i && e*i<=r && e*i>=l){
			cout<<"YES\n";
			return 0;
		}
	}
	cout<<"NO\n";

	return 0;
}