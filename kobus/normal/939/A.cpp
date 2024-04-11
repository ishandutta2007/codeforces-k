#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define MAXN 212
#define INF LLONG_MAX
#define MOD 1000000007
#define MAX 21234

int gcd(int a,int b){
    a==0?b:gcd(b%a,a);
}
int tothe(int a,int b){
    if(b==0)return 1;
    int p=tothe(a,b/2)%MOD;
    p=(p*p)%MOD;
    return(b%2==0)?p:(a*p)%MOD;
}
int inv(int a){
    return tothe(a,MOD-2);
} 

int v[5123];


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);

    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>v[i];

    for(int i=1;i<=n;i++){
        if(v[v[v[i]]]==i){
            cout<<"YES"<<endl;
            return 0;
        }
    }

    cout<<"NO"<<endl;

    return 0;

}