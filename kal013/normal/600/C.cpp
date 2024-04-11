#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
//#define int long long
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpi;
typedef vector<ppi> vppi;
typedef map<int,int> mii;
typedef map<int,vi> mvi;
typedef map<pii,int> mpi;
typedef priority_queue<ppi,vppi,greater<ppi>> min_heap_ppi;
typedef priority_queue<ppi> max_heap_ppi;
#define For(i,n) for(int i=0;i<n;i++)
#define Rev(i,n) for(int i=n-1;i>=0;i--)
#define tern(a,b,c) (!!(a))*b+(!(a))*c
#define cross(i,a,b) ((tern(b>a,1,-1))*(i))>=((tern(b>a,1,-1))*(b))
#define loop(i,a,b) for(int i=a;i!=b;i+=tern(b>a,1,-1))
#define sloop(i,a,b,s) for(int i=a;(!(cross(i,a,b)));i+=s)
#define inrange(i,a,b) ((i>=min(a,b)) && (i<=max(a,b)))
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define d0(x) cout<<(x)<<" "
#define d1(x) cout<<(x)<<endl
#define d2(x,y) cout<<(x)<<" "<<(y)<<endl
#define d3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define d4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl
#define d5(a,b,c,d,e) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<endl
#define d6(a,b,c,d,e,f) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<" "<<(f)<<endl
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define all(v) (v).begin(),(v).end()
#define sz(v) (v).size()
#define ll long long
//#define file cin

const int maxn=1e6+100;
const int MaxN=1e5+100;
const int mod=1e9+7;
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
// const int INF=1e16;

// inline void read(int &x) {
//     register int c = getchar_unlocked();
//     x = 0;
//     int neg = 0;

//     for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

//     if(c=='-') {
//     	neg = 1;
//     	c = getchar_unlocked();
//     }

//     for(; c>47 && c<58 ; c = getchar_unlocked()) {
//     	x = (x<<1) + (x<<3) + c - 48;
//     }

//     if(neg)
//     	x = -x;
// }
// inline void read_str(char *str){
//     register char c = 0;
//     register int i = 0;

//     while (c < 33)
//         c = getchar_unlocked();

//     while (c != '\n') {
//         str[i] = c;
//         c = getchar_unlocked();
//         i = i + 1;
//     }

//     str[i] = '\0';
// }

inline int fast_expo(int base,int power,int modulo=mod){
    ll x=base,cnt=power,ans=1;
    while(cnt){
        if (cnt&1) ans=(ans*x)%mod;
        x=(x*x)%mod;
        cnt>>=1;
    }
    int tmp=ans;
    return tmp;
}

inline int fib(int n,int a=1,int b=1,int c=1,int d=0,int acca=0,int accb=1,int m=mod){
    if (n==0) return acca;

    if (n&1) return fib(n/2,((a*a)%m+(b*c)%m)%m,((a*b)%m+(b*d)%m)%m,(c*(a+d)%m)%m,((c*b)%m+(d*d)%m)%m,((a*acca)%m+(b*accb)%m)%m,((c*acca)%m+(d*accb)%m)%m,m);
    else return fib(n/2,((a*a)%m+(b*c)%m)%m,((a*b)%m+(b*d)%m)%m,(c*(a+d)%m)%m,((c*b)%m+(d*d)%m)%m,acca,accb,m);
}

struct base{
    double x , y;
    base(){
        x = 0;
        y = 0;
    }
    base(double a){
        x = a;
        y = 0;
    }
    base(double a , double b){
        x = a;
        y = b;
    }
    base conj(){
        return base(x , -y);
    }
    base operator = (const base &o){
        x = o.x;
        y = o.y;
        return *this;
    }
    base operator + (const base &o) const {
        return base(x + o.x , y + o.y);
    }
    base operator - (const base &o) const {
        return base(x - o.x , y - o.y);
    }
    base operator * (const base &o) const {
        return base(x * o.x - y * o.y , y * o.x + x * o.y);
    }
    base operator * (const double num) const {
        return base(x * num , y * num);
    }
    base operator / (const double num) const {
        return base(x / num , y / num);
    }

};




/*/-----------------------------Code begins----------------------------------/*/
int l[maxn];
int arr[26];
vi res;
signed main(){
    string s;
    cin>>s;
    int n=s.size();
    
    For(i,26) arr[i]=0;
    For(i,n){
        arr[s[i]-'a']++;
        l[i]=-1;
    }
    int i=0,curr=0;
    while (i<26 && curr<n){
        if (arr[i]==0 || arr[i]==1){
            i+=1;
            continue;}
        if (l[curr]!=-1){
            curr+=1;
            continue;}
        l[curr]=i;
        arr[i]--;
        if (arr[i]!=0 and curr<n/2){
            l[n-curr-1]=i;
            arr[i]-=1;
        }
    }
    For(i,26){
        if (arr[i]==1){
            res.pb(i);
        }
    }
    int lef=0;
    For(i,(n+1)/2){
        if (l[i]==-1){
            l[i]=res[lef];
            l[n-1-i]=res[lef];
            lef++;
        }
    }
    sort(l,l+(n)/2);
    For(i,(n+1)/2){
        l[n-1-i]=l[i];
    }
    For(i,n){
        cout<<(char(l[i]+'a'));
    }

}