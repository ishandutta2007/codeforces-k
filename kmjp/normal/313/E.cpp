#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

typedef signed long long ll;
typedef unsigned long long ull;

#define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
#define _E(...) fprintf(stderr, __VA_ARGS__)
#undef _P
#define _P(...) printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define GETs(x) scanf("%s",x);
int GETi() { int i;scanf("%d",&i); return i;}
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

ll N,M;
int num[2][100001];
vector<int> res,D;
stack<int> S;

void solve() {
    int f,r,i,j,k,l, x,y,z;
    
    cin>>N>>M;
    FOR(x,N) num[0][GETi()]++;
    FOR(x,N) num[1][M-1-GETi()]++;
    
    for(i=M-1;i>=0;i--) {
        while(num[0][i] && num[1][i]) res.push_back(M-1),num[0][i]--,num[1][i]--;
        while(num[1][i]) S.push(M-1-i),num[1][i]--;
        while(num[0][i] && !S.empty()) res.push_back((i+S.top())%M),num[0][i]--,S.pop();
        while(num[0][i]) D.push_back(i),num[0][i]--;
    }
    
    FOR(i,D.size()) res.push_back((D[i]+S.top())%M),S.pop();
    sort(res.rbegin(),res.rend());
    FOR(i,N) _P("%d ",res[i]);
    _P("\n");
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}