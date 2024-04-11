#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<PII> VPII;

const LD EPS=10e-9;
const int MOD=1000000007;
const int PMOD1=606574021;
const int PMOD2=606574027;
const int INF=1000000009;
const LL LLINF=1000000000000000009;

#define FOR(i, b, e) for(int i=b; i<=e; i++)
#define FORD(i, b, e) for(int i=b; i>=e; i--)
#define SIZE(x) ((int)(x).size())

#define PB push_back
#define MP make_pair
#define ST first
#define ND second

//END OF TEMPLATE

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	if(n<6){
		cout<<"-1\n";
	}
	else{
		cout<<"1 2\n";
		FOR(i, 3, 2+(n-2)/2){
			cout<<"1 "<<i<<'\n';
		}
		FOR(i, 3+(n-2)/2, n){
			cout<<"2 "<<i<<'\n';
		}
	}
	FOR(i, 1, n-1){
		cout<<i<<' '<<i+1<<'\n';
	}
	return 0;
}