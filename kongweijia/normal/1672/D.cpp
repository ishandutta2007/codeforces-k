#include "bits/stdc++.h"
#define rep(i,a,n) for(auto i=a;i<=n;i++)
#define per(i,a,n) for(auto i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define all(A) A.begin(),A.end()
#define sz(A) (int)A.size()
template<class T> inline bool chmax(T &a, T b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;

string to_string(const string& s) {return '"' + s + '"';}
string to_string(const char* s) {return to_string((string) s);}
string to_string(char c) {return "'" + string(1,c) + "'";}
string to_string(bool x) {return x ? "true" : "false";}
template<typename A, typename B> string to_string(pair<A, B> p) {return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")";}
template<typename A> string to_string(A v) 
{
    bool first = 1;
    string res = "{";
    for(const auto &x: v) 
    {
        if (!first) res += ", ";
        first = 0;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() {cerr << endl;} 
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) 
{
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifndef ONLINE_JUDGE
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
    #define debug(...) if(0) puts("No effect.")
#endif

using ll = long long;
//using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 200'000;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n; scanf("%d",&n);
        static int a[maxn+5], b[maxn+5];
        rep(i,1,n) scanf("%d",&a[i]);
        rep(i,1,n) scanf("%d",&b[i]);
        static int slots[maxn+5];
        rep(i,1,n) slots[i] = 0;
        int ok = 1, last = -1, ptr = n;
        per(i,1,n)
        {
            int x = b[i];
            while(ok)
            {
                if(a[ptr]==x) {ptr--; break;}
                else
                {
                    if(last==x) {slots[x]++; break;}
                    else
                    {
                        if(slots[a[ptr]]>0) slots[a[ptr]]--, ptr--;
                        else ok = 0;
                    }
                }
            }
            last = x;
        }
        puts(ok ? "YES" : "NO");
    }
    return 0;
}