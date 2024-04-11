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

int main(void) {
   int xmax,ymax,x,y,rc,rd;
   RII(xmax,ymax);
   RII(x,y);
   RII(rc,rd);
   int rg=gcd(rc,rd);
   rc/=rg; rd/=rg;
   int xl,yl,rk;
   rk=min(xmax/rc,ymax/rd);
   xl=rc*rk;
   yl=rd*rk;
   int xl1,xl2,yl1,yl2;
   xl2=xl/2; xl1=xl-xl2;
   yl2=yl/2; yl1=yl-yl2;
   int x1,x2,y1,y2;
   x1=x-xl1;
   x2=x+xl2;
   y1=y-yl1;
   y2=y+yl2;
   if(x1<0) {
      int d=-x1;
      x1+=d;
      x2+=d;
   }
   if(x2>xmax) {
      int d=x2-xmax;
      x1-=d;
      x2-=d;
   }
   if(y1<0) {
      int d=-y1;
      y1+=d;
      y2+=d;
   }
   if(y2>ymax) {
      int d=y2-ymax;
      y1-=d;
      y2-=d;
   }
   printf("%d %d %d %d\n",x1,y1,x2,y2);
   return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread