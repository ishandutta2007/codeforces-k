// @author kelvin
// #includes {{{
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
// }}}
// #defines {{{
#define RI(x) scanf("%d",&(x))
#define RII(x,y) scanf("%d %d",&(x),&(y))
#define RF(x) scanf("%lf",&(x))
#define RS(x) scanf("%s",x)
#define PRI(x) printf("%d\n",x);
#define PR printf
#define MP(x,y) make_pair(x,y)
#define PB(x) push_back(x)
#define POP() pop_back()
#define F first
#define S second
typedef pair<int,int> pii;
// }}}
// #functions {{{
pii operator+(const pii &a,const pii &b) { return MP(a.F+b.F,a.S+b.S); }
pii operator-(const pii &a,const pii &b) { return MP(a.F-b.F,a.S-b.S); }
pii& operator+=(pii &a,const pii &b) { a.F+=b.F; a.S+=b.S; return a; }
pii& operator-=(pii &a,const pii &b) { a.F-=b.F; a.S-=b.S; return a; }
template <class T,class U>
bool cmp_second(const pair<T,U> &a,const pair<T,U> &b) { return a.second<b.second; }
template <class T>
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
}
inline int sg(int x) { return x?(x>0?1:-1):0; }
// }}}

#define MAXN 2000500

int n,l;
char a[MAXN],b[MAXN];

bool solve() {
   l=n*2;
   int c2=0,a1=0,b1=0;
   for(int i=0;i<l;i++) {
      //if(a[i]=='1') ai++;
      //if(b[i]=='1') bi++;
      if(a[i]=='1'&&b[i]=='1')  c2++;
      if(a[i]=='1'&&b[i]=='0')  a1++;
      if(a[i]=='0'&&b[i]=='1')  b1++;
   }
   //printf("%d %d %d\n",c2,a1,b1);
   int ai=0,bi=0;
   for(int t=0;t<l;t++) {
      if(!(t&1)) { // a
         if(c2) {
            c2--;
            ai++;
         } else if(a1) {
            a1--;
            ai++;
         } else if(b1) {
            b1--;
         }
      } else { // b
         if(c2) {
            c2--;
            bi++;
         } else if(b1) {
            b1--;
            bi++;
         } else if(a1) {
            a1--;
         }
      }
   }
   if(ai>bi) puts("First");
   else if(ai<bi) puts("Second");
   else puts("Draw");
}

int main(void) {
   RI(n);
   RS(a);
   RS(b);
   solve();
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread