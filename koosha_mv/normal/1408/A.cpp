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

int n,t,a[N],b[N],c[N];

int main(){
    cin>>t;
    while(t--){
        cin>>n;
        f(i,0,n) cin>>a[i];
        f(i,0,n) cin>>b[i];
        f(i,0,n) cin>>c[i];
        int last=a[0];
        cout<<a[0]<<" ";
        f(i,1,n-1){
            if(a[i]!=last){
                cout<<a[i]<<" ";
                last=a[i];
            }
           else{
            cout<<b[i]<<" ";
               last=b[i];
           }
           }
       if(a[n-1]!=last && a[n-1]!=a[0]) cout<<a[n-1]<<" ";
       else{
        if(b[n-1]!=last && b[n-1] !=a[0]) cout<<b[n-1]<<" ";
           else cout<<c[n-1]<<" ";
           
       }
        cout<<endl;
       }
}