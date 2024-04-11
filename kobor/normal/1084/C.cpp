//Krzysztof Boryczka
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;

#define FOR(i, b, e) for(int i=b; i<=e; i++)
#define FORD(i, b, e) for(int i=b; i>=e; i--)
#define SIZE(x) ((int)(x).size())
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'
#define WATCH(x) cout<<(#x)<<" is "<<(x)<<ent

//END OF TEMPLATE

const ll MOD=1e9+7;
vector<ll> v;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	ll odp=1, akt=0;
	cin>>s;
	FOR(i, 0, SIZE(s)-1){
		if(s[i]=='a'){
			akt++;
		}
		if(s[i]=='b'){
			v.pb(akt+1);
			akt=0;
		}
	}
	v.pb(akt+1);
	for(auto x: v){
		odp*=x;
		odp%=MOD;
	}
	cout<<(odp-1+MOD)%MOD<<ent;
	return 0;
}