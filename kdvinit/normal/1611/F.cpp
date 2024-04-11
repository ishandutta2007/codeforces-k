/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

//Segment_Tree1
//Range Query And Node Update (replace a[pos] = new_val)
//For any associative operator (+, *, max, min, gcd, xor)
//Use .update(pos, new_val) and .query(l, r)
class Segment_Tree1
{
private:
    int n;      //Size of array
    int *t;     //Segment Tree

public:
    //Kindly change only this part
    inline int combine(int xx, int yy) { return min(xx, yy); }

    void build(int a[], int v, int tl, int tr)
    {
        if(tl==tr) t[v]=a[tl];
        else
        {
            int tm = (tl+tr)/2;
            build(a, 2*v, tl, tm);
            build(a, 2*v+1, tm+1, tr);
            t[v] = combine(t[2*v], t[2*v+1]);
        }
    }

    Segment_Tree1(int array[], int array_size) { n = array_size; t = new int[(4*n)]; build(array, 1, 1, n); }
    ~Segment_Tree1() { delete[] t; }

    int get_query(int v, int tl, int tr, int l, int r)
    {
        if(l==tl && r==tr) return t[v];
        int tm = (tl+tr)/2;
        if(l<=tm && tm<r) return combine(get_query(2*v, tl, tm, l, tm), get_query(2*v+1, tm+1, tr, tm+1, r));
        else if(tm<l) return get_query(2*v+1, tm+1, tr, l, r);
        else return get_query(2*v, tl, tm, l, r);
    }

    int query(int l, int r)     //Combine value of a[l...r]
    {
        if(l>r || l<1 || r>n) { cout<<"Invalid Query\n"; return -1; }
        return get_query(1, 1, n, l, r);
    }

    void get_update(int v, int tl, int tr, int pos, int new_val)
    {
        if(tl==tr) t[v]=new_val;
        else
        {
            int tm = (tl+tr)/2;
            if(pos<=tm) get_update(2*v, tl, tm, pos, new_val);
            else get_update(2*v+1, tm+1, tr, pos, new_val);
            t[v] = combine(t[2*v], t[2*v+1]);
        }
    }

    void update(int pos, int new_val)   //update a[pos]=new_val
    {
        //Note that this would not change the value in the original array
        if(pos<1 || pos>n) cout<<"Invalid Update\n";
        else get_update(1, 1, n, pos, new_val);
    }
};

void solve()
{
    int n, s;
    cin>>n>>s;

    int a[n+1], pos=0;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        if(a[i]+s>=0) pos=1;
    }

    if(pos==0) { cout<<-1<<endl; return; }

    int sum[n+1]={0};
    for(int i=1; i<=n; i++) sum[i]=sum[i-1]+a[i];

    Segment_Tree1 st1(sum, n);

    int len=0, strt=0, nd=0;
    for(int i=1; i<=n; i++)
    {
        if(a[i]+s<0) continue;
        int l=i, r=n+1;

        while(l+1!=r)
        {
            int mid = (l+r)/2;
            int mn = st1.query(i, mid) - sum[i-1] + s;
            if(mn>=0) l=mid;
            else r=mid;
        }

        int len2 = l-i+1;
        if(len2>len)
        {
            len=len2;
            strt = i;
            nd = l;
        }
    }

    cout<<strt<<" "<<nd<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}