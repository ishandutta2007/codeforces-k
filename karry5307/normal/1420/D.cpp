// This code is written by Karry5307
#include<bits/stdc++.h>
// Definition
#define For(i,x,y) for(register int i=(x);i<(y);i++)
#define Forr(i,x,y) for(register int i=(x);i<=(y);i++)
#define Rep(i,x,y) for(register int i=(x);i>(y);i--)
#define Repp(i,x,y) for(register int i=(x);i>=(y);i--)
#define ve vector
#define iter iterator
#define pb emplace_back
#define popb pop_back
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x.size())
#define F first
#define S second
#define PY return (void)puts("Yes")
#define PN return (void)puts("Yes")
#define P0 return (void)puts("0")
#define P1 return (void)puts("-1")
using namespace std;
// Typedefs
typedef int ll;
typedef long long int li;
typedef unsigned int ul;
typedef unsigned long long int ull;
typedef double db;
typedef long double ldb;
typedef pair<ll,ll> pii;
typedef pair<li,li> pll;
const ll MAXN=6e5+51,MOD=998244353,inf=0x3f3f3f3f;
// Structures and variables
ll n,kk,tot,lst,sm,res;
ll l[MAXN],r[MAXN],u[MAXN],fact[MAXN],finv[MAXN],cntl[MAXN],cntr[MAXN];
// Fast IO
inline ll read()
{
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-') ch=getchar();
    if(ch=='-') neg=-1,ch=getchar();
    while(isdigit(ch)) num=(num<<3)+(num<<1)+(ch-'0'),ch=getchar();
    return neg==1?num:-num;
} 
inline li readu()
{
    register li num=0;
    register char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) num=(num<<3)+(num<<1)+(ch-'0'),ch=getchar();
    return num;
} 
template<class T>
inline void writep(T x)
{
    if(x<0){return (void)putchar('-'),writep(-x);}
    if(x<10){return (void)putchar(x|48);}
    writep(x/10),putchar((x%10)|48);
}
template<class T>
inline void write(T x,char ch=' '){writep(x),putchar(ch);}
template<class T>
inline void writeln(T x){writep(x),putchar('\n');}
// chkmin and chkmax
template<class T>
inline void chkmax(T &x,const T &y){x=x>y?x:y;}
template<class T>
inline void chkmin(T &x,const T &y){x=x<y?x:y;}
// Functions
template<class T,class Compare>
inline void sort(ve<T>&v,Compare cmp=less<T>()){sort(all(v),cmp);}
template<class T>
inline void reverse(ve<T>&v){reverse(all(v));}
template<class T>
inline void clear(T *arr){memset(arr,0,sizeof(arr));}
template<class T>
inline void setInf(T *arr){memset(arr,0x3f,sizeof(arr));}
// Math funcs
inline ll qpow(ll base,ll exponent)
{
    li res=1;
    while(exponent)
    {
        if(exponent&1)
        {
            res=(li)res*base%MOD;
        }
        base=(li)base*base%MOD,exponent>>=1;
    }
    return res;
}
inline ll gcd(ll x,ll y)
{
    return !y?x:gcd(y,x%y);
}
inline li lcm(ll x,ll y)
{
    return x/gcd(x,y)*y;
}
// Functions
inline void setup(ll cnt)
{
    fact[0]=fact[1]=finv[0]=1;
    for(register int i=1;i<=cnt;i++)
    {
        fact[i]=(li)fact[i-1]*i%MOD;
    }
    finv[cnt]=qpow(fact[cnt],MOD-2);
    for(register int i=cnt-1;i;i--)
    {
        finv[i]=(li)finv[i+1]*(i+1)%MOD;
    }
}
inline ll binom(ll m,ll n)
{
    if(m<0||n<0||m<n)
    {
        return 0;
    }
    return (li)fact[m]*finv[n]%MOD*finv[m-n]%MOD;
}
int main()
{
    n=read(),kk=read(),setup(3e5+10);
    for(register int i=1;i<=n;i++)
    {
        l[i]=read(),r[i]=read(),u[++tot]=l[i],u[++tot]=r[i];
    }
    sort(u+1,u+tot+1),tot=unique(u+1,u+tot+1)-u-1;
    for(register int i=1;i<=n;i++)
    {
        l[i]=lower_bound(u+1,u+tot+1,l[i])-u,cntl[l[i]]++;
        r[i]=lower_bound(u+1,u+tot+1,r[i])-u,cntr[r[i]+1]++;
    }
    for(register int i=1;i<=tot;i++)
    {
        lst=sm,sm+=cntl[i]-cntr[i];
        res=((li)res+binom(sm,kk)-binom(lst-cntr[i],kk)+MOD)%MOD;
    }
    printf("%d\n",res);
}