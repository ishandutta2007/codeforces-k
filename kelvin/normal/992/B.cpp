// @author kelvin
// #includes {{{
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <queue>
#include <bitset>
#include <sstream>
using namespace std;
// }}}
// #defines {{{
#define MP(x,y) make_pair(x,y)
#define PB(x) push_back(x)
#define POP() pop_back()
#define F first
#define S second
#define PR printf
int RI() { return 0; }
template<typename... T>
int RI(int& head,T&... tail) {
    return scanf("%d",&head) + RI(tail...);
}
void PRI(int x) {
    printf("%d\n",x);
}
template<typename... Args>
void PRI(int head,Args... tail) {
    printf("%d ",head);
    PRI(tail...);
}
#define RF(x) scanf("%lf",&(x))
#define RS(x) scanf("%s",x)
#define DPRI(x) fprintf(stderr,"<"#x"=%d>\n",x)
#define DPRII(x,y) fprintf(stderr,"<"#x"=%d, "#y"=%d>\n",x,y)
#define DPRIII(x,y,z) fprintf(stderr,"<"#x"=%d, "#y"=%d, "#z"=%d>\n",x,y,z)
#define DPRIIII(x,y,z,w) fprintf(stderr,"<"#x"=%d, "#y"=%d, "#z"=%d "#w"=%d>\n",x,y,z,w)
#define DPRF(x) fprintf(stderr,"<"#x"=%lf>\n",x)
#define DPRS(x) fprintf(stderr,"<"#x"=%s>\n",x)
#define DPRMSG(x) fprintf(stderr,#x"\n")
#define DPRPII(x) fprintf(stderr,"<"#x"=(%d,%d)>\n",x.F,x.S)
typedef pair<int,int> pii;
// }}}
// #functions {{{
pii operator+(const pii &a,const pii &b) { return MP(a.F+b.F,a.S+b.S); }
pii operator-(const pii &a,const pii &b) { return MP(a.F-b.F,a.S-b.S); }
pii& operator+=(pii &a,const pii &b) { a.F+=b.F; a.S+=b.S; return a; }
pii& operator-=(pii &a,const pii &b) { a.F-=b.F; a.S-=b.S; return a; }
template <class T,class U>
bool cmp_second(const pair<T,U> &a,const pair<T,U> &b) { return a.second<b.second; }
/*template <class T>
T gcd(T a,T b) { a=abs(a); b=abs(b); while(b) { T t=b; b=a%b; a=t; } return a; }
template <class T>
pair<T,T> ext_gcd(T a,T b) {
   T a0=1,a1=0,b0=0,b1=1;
   if(a<0) { a=-a; a0=-1; }
   if(b<0) { b=-b; b1=-1; }
   while(b) {
      T t,q=a/b;
      t=b; b=a-b*q; a=t;
      t=b0; b0=a0-b0*q; a0=t;
      t=b1; b1=a1-b1*q; a1=t;
   }
   return MP(a0,a1);
}*/
inline int sg(int x) { return x?(x>0?1:-1):0; }
/*inline string concatenate_strings(vector<string> ss) {
   tring s;
   for(int i=0;i<ss.size();i++)
      s+=ss[i];
   return s;
}
template <class T>
inline vector<T> read_from_string(string s) {
   vector<T> ret; stringstream ss(s,stringstream::in);
   while(1) { T x; ss>>x; ret.push_back(x); if(ss.eof()) break; }
   return ret;
}*/
// }}}

int gcd,lcm,lb,rb,r;

int dfs(int x, const vector<int>::iterator &it, const vector<int>::iterator &end) {
    if (it==end) {
        int y = r/x;
        return lb<=x && x<=rb && lb<=y && y<=rb ? 1 : 0;
    }
    return dfs(x, next(it), end) + dfs(x*(*it), next(it), end);
}

int solve() {
    if (lcm%gcd!=0) return 0;
    r = lcm/gcd;
    lb = (lb+gcd-1)/gcd;
    rb = rb/gcd;
    vector<int> pf;
    int rr = r;
    for (int p=2; p*p<=rr; p++) {
        if (rr%p) continue;
        pf.PB(p);
        while(rr%p==0) rr/=p;
    }
    if (rr>1) pf.PB(rr);
    for (auto &p: pf) {
        int q=p;
        while(r%(long long)(q*p)==0)
            q*=p;
        p=q;
    }
    //for (auto p: pf) printf(" %d", p); puts("");
    return dfs(1, pf.begin(), pf.end());
}

int main(void)
{
    RI(lb,rb,gcd,lcm);
    PRI(solve());
    return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread