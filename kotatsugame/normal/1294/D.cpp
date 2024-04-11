#include<cstdio>
#include<algorithm>
using namespace std;
#include<vector>
#include<functional>
#include<limits>
template<typename T>
struct segtree{
	using F=function<T(T,T)>;
	const F calcfn,updatefn;
	int n;
	T defvalue;
	vector<T>dat;
	segtree(int n_=0,T defvalue_=numeric_limits<T>::max(),
		const F calcfn_=[](T a,T b){return a<b?a:b;},
		const F updatefn_=[](T a,T b){return b;}
	):defvalue(defvalue_),calcfn(calcfn_),updatefn(updatefn_)
	{
		n=1;
		while(n<n_)n<<=1;
		dat.assign(2*n-1,defvalue);
	}
	void copy(const vector<T>&v)
	{
		for(int i=0;i<v.size();i++)dat[i+n-1]=v[i];
		for(int i=n-2;i>=0;i--)dat[i]=calcfn(dat[i*2+1],dat[i*2+2]);
	}
	void update(int i,T a)
	{
		i+=n-1;
		dat[i]=updatefn(dat[i],a);
		while(i>0)
		{
			i=(i-1)/2;
			dat[i]=calcfn(dat[2*i+1],dat[2*i+2]);
		}
	}
	T query(int a,int b)//[a,b)
	{
		int L=(a<0?0:a>n?n:a)+n-1;
		int R=(b<0?0:b>n?n:b)+n-1;
		T lret=defvalue,rret=defvalue;
		for(;L<R;L>>=1,R>>=1)
		{
			if(!(L&1))lret=calcfn(lret,dat[L]);
			if(!(R&1))rret=calcfn(dat[--R],rret);
		}
		return calcfn(lret,rret);
	}
};
int Q,X;
main()
{
	scanf("%d%d",&Q,&X);
	auto f=[](pair<int,int>a,pair<int,int>b){return min(a,b);};
	auto g=[](pair<int,int>a,pair<int,int>b){return make_pair(a.first+1,a.second);};
	segtree<pair<int,int> >P(X,make_pair(Q+1,X),f,g);
	vector<pair<int,int> >init(X,make_pair(0,0));
	for(int i=0;i<X;i++)init[i].second=i;
	P.copy(init);
	for(;Q--;)
	{
		int Y;scanf("%d",&Y);P.update(Y%X,make_pair(0,0));
		pair<int,int>ans=P.query(0,X);
		printf("%lld\n",(long long)ans.first*(long long)X+(long long)ans.second);
	}
}