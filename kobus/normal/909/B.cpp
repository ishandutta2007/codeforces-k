#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 512345
#define INF INT_MAX/2
#define MOD 1000000007

int solve(int n){
	if(n==1)return 1;
	if(n==2)return 2;
	return n+solve(n-2);
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;
	cout<<solve(n)<<endl;
	return 0;
}