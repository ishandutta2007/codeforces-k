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

int N;
pair<int,int> S[100001];
int A[100001],B[100001];

void solve() {
    int f,r,i,j,k,l,x,y;
    
    N=GETi();
    FOR(i,N) S[i]=make_pair(GETi(),i);
    sort(S,S+N);
    
    FOR(i,N) {
        if(i<=N/3) {
            A[S[i].second]=0;
            B[S[i].second]=S[i].first;
        }
        else if(i<=2*N/3) {
            B[S[i].second]=0;
            A[S[i].second]=S[i].first;
        }
        else {
            A[S[i].second]=(N-i);
            B[S[i].second]=S[i].first-(N-i);
        }
    }
    
    
    _P("YES\n");
    FOR(i,N) _P("%d ", A[i]);
    _P("\n");
    FOR(i,N) _P("%d ", B[i]);
    _P("\n");
    
    return;
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}