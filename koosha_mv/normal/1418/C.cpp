#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99;

int n,t,a[N],dp[2][N];
int sum;

int main(){
    cin>>t;
    while(t--){
        cin>>n;
        dp[0][0]=dp[0][1]=N;
        f(i,2,n+2){
            cin>>a[i];
            dp[1][i]=min(dp[0][i-1],dp[0][i-2]);
            dp[0][i]=min(dp[1][i-1]+a[i],dp[1][i-2]+a[i]+a[i-1]);
        }
        cout<<min(dp[1][n+1],dp[0][n+1])<<'\n';
    }
}