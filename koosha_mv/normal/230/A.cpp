#include<bits/stdc++.h>
using namespace std;int main(){int s,n,x[10000]={0},o,b,m=-1;cin>>s>>n;while(n--){cin>>o>>b;x[o]+=b;m=max(m,o);}for(int i=0;i<10000;i++)if(s>i)s+=x[i];(s>m?cout<<"YES":cout<<"NO");}